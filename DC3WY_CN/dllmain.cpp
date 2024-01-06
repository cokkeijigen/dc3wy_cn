﻿#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include <vector>
#include "dc3wy.h"
#include "detours.h"
#pragma comment(lib, "detours.lib")

namespace Hook::Mem {

    static bool MemWrite(uintptr_t Addr, void* Buf, size_t Size) {
        DWORD OldPro = NULL; SIZE_T wirteBytes = NULL;
        if (VirtualProtect((VOID*)Addr, Size, PAGE_EXECUTE_READWRITE, &OldPro)) {
            WriteProcessMemory(INVALID_HANDLE_VALUE, (VOID*)Addr, Buf, Size, &wirteBytes);
            VirtualProtect((VOID*)Addr, Size, OldPro, &OldPro);
            return Size == wirteBytes;
        }
        return false;
    }

    static bool JmpWrite(uintptr_t orgAddr, uintptr_t tarAddr) {
        uint8_t jmp_write[5] = { 0xE9, 0x0, 0x0, 0x0, 0x0 };
        tarAddr = tarAddr - orgAddr - 5;
        memcpy(jmp_write + 1, &tarAddr, 4);
        return MemWrite(orgAddr, jmp_write, 5);
    }
}

namespace Hook::Type {
    typedef struct { HFONT jis_f; HFONT gbk_f; size_t size; } Font;
    typedef HANDLE(WINAPI* FindFirstFileA)(LPCSTR, LPWIN32_FIND_DATAA);
    typedef DWORD (WINAPI* GetGlyphOutlineA)(HDC, UINT, UINT, LPGLYPHMETRICS, DWORD, LPVOID, MAT2*);
    typedef HANDLE(WINAPI* CreateFileA)(LPCSTR , DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
    typedef HANDLE(WINAPI* CreateFileW)(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
    typedef HWND(WINAPI* CreateWindowExA)(DWORD, LPCSTR, LPCSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID);
}

namespace Hook::Fun {

    static std::string  NewReplacePathA;
    static std::wstring NewReplacePathW;
    static std::vector<Type::Font*> Fonts;

    static Type::Font* GetFontStruct(HDC& hdc, tagTEXTMETRICA lptm = {}) {
        GetTextMetricsA(hdc, &lptm);
        size_t size = (size_t)lptm.tmHeight;
        for (Type::Font* f : Fonts) if (f->size == size) return f;
        Type::Font* nf = new Type::Font{ nullptr, nullptr, size };
        nf->gbk_f = CreateFontA(size, size / 2, 0, 0, 0, 0, 0, 0, 0x86, 4, 0x20, 4, 4, "黑体");
        nf->jis_f = CreateFontA(size, size / 2, 0, 0, 0, 0, 0, 0, 0x80, 4, 0x20, 4, 4, "黑体");
        Fonts.push_back(nf);
        return nf;
    }

    static bool ReplacePathW(std::wstring path) {
        path.assign(path.substr(path.find_last_of(L"\\") + 1)).insert(0, L"cn_Data\\");
        if (GetFileAttributesW(path.c_str()) == INVALID_FILE_ATTRIBUTES)  return false;
        return NewReplacePathW.assign(path).size();
    }

    static bool ReplacePathA(std::string path) {
        path.assign(path.substr(path.find_last_of("\\") + 1)).insert(0, "cn_Data\\");
        if (GetFileAttributesA(path.c_str()) == INVALID_FILE_ATTRIBUTES) return false;
        return NewReplacePathA.assign(path).size();
    }

    Type::GetGlyphOutlineA OldGetGlyphOutlineA;
    static DWORD WINAPI NewGetGlyphOutlineA(HDC hdc, UINT uChar, UINT fuf, LPGLYPHMETRICS lpgm, DWORD cjbf, LPVOID pvbf, MAT2* lpmat) {
        Type::Font* font = GetFontStruct(hdc);
        if (uChar == 0xA1EC) { 
            uChar = 0x81F4; // 替换♪
            SelectObject(hdc, font->jis_f);
        } else {
            // 替换半角空格
            if (uChar == 0x23) uChar = 0x20;
            SelectObject(hdc, font->gbk_f);
        }
        return OldGetGlyphOutlineA(hdc, uChar, fuf, lpgm, cjbf, pvbf, lpmat);
    }

    Type::CreateWindowExA OldCreateWindowExA;
    static HWND WINAPI NewCreateWindowExA(DWORD dwExSl, LPCSTR lpClsN, LPCSTR lpWndN, DWORD dwSl, int X, int Y, int nW, int nH, HWND hWndP, HMENU hM, HINSTANCE hIns, LPVOID lpPr) {
        HWND hWndMain = OldCreateWindowExA(dwExSl, lpClsN, lpWndN, dwSl, X, Y, nW, nH, hWndP, hM, hIns, lpPr);
        RECT mainClientRect = { NULL };
        GetClientRect(hWndMain, &mainClientRect);
        int subW = mainClientRect.right - mainClientRect.left;
        int subH = mainClientRect.bottom - mainClientRect.top;
        WNDCLASSA wcSub = { NULL };
        wcSub.lpfnWndProc = Dc3wy::subtitle::WndProc;
        wcSub.hInstance = GetModuleHandle(NULL);
        wcSub.lpszClassName = "ChildWindowClass";
        RegisterClassA(&wcSub);
        HWND hWndChild = OldCreateWindowExA(WS_EX_OVERLAPPEDWINDOW, "ChildWindowClass", "Child Window", WS_CHILD | WS_VISIBLE,
            0, 0, 300, 500,
            hWndMain, NULL, GetModuleHandle(NULL), NULL);
        SetLayeredWindowAttributes(hWndChild, RGB(0, 0, 0), 0, LWA_COLORKEY);
        // 置顶子窗口
        SetWindowPos(hWndChild, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        Dc3wy::subtitle::init(hWndMain);
        return hWndMain;
    }

    Type::FindFirstFileA OldFindFirstFileA;
    static HANDLE WINAPI NewFindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData) {
        return OldFindFirstFileA(ReplacePathA(lpFileName) ? NewReplacePathA.c_str() : lpFileName, lpFindFileData);
    }

    Type::CreateFileA OldCreateFileA;
    static HANDLE WINAPI NewCreateFileA(LPCSTR lpFN, DWORD dwDA, DWORD dwSM, LPSECURITY_ATTRIBUTES lpSA, DWORD dwCD, DWORD dwFAA, HANDLE hTF)  {
        return OldCreateFileA(ReplacePathA(lpFN) ? NewReplacePathA.c_str() : lpFN, dwDA, dwSM, lpSA, dwCD, dwFAA, hTF);
    }

    Type::CreateFileW OldCreateFileW;
    static HANDLE WINAPI NewCreateFileW(LPCWSTR lpFN, DWORD dwDA, DWORD dwSM, LPSECURITY_ATTRIBUTES lpSA, DWORD dwCD, DWORD dwFAA, HANDLE hTF) {
        return OldCreateFileW(ReplacePathW(lpFN) ? NewReplacePathW.c_str() : lpFN, dwDA, dwSM, lpSA, dwCD, dwFAA, hTF);
    }
}

namespace Hook {

    static void Init() {
        if (HMODULE USER32_DLL = GetModuleHandleW(L"user32.dll")) {
            Fun::OldCreateWindowExA = (Type::CreateWindowExA)GetProcAddress(USER32_DLL, "CreateWindowExA");
        }
        if (HMODULE GDI32_DLL = GetModuleHandleW(L"gdi32.dll")) {
            Fun::OldGetGlyphOutlineA = (Type::GetGlyphOutlineA)GetProcAddress(GDI32_DLL, "GetGlyphOutlineA");
        }
        if (HMODULE KERNEL32_DLL = GetModuleHandleW(L"kernel32.dll")) {
            //
            Fun::OldFindFirstFileA = (Type::FindFirstFileA)GetProcAddress(KERNEL32_DLL, "FindFirstFileA");
            Fun::OldCreateFileA = (Type::CreateFileA)GetProcAddress(KERNEL32_DLL, "CreateFileA");
            Fun::OldCreateFileW = (Type::CreateFileW)GetProcAddress(KERNEL32_DLL, "CreateFileW");
        }
        if (DWORD BaseAddr = (DWORD)GetModuleHandleW(NULL)) {
            Dc3wy::jmp_hook_init((intptr_t)BaseAddr);
            Mem::MemWrite(BaseAddr + 0x0E8DB, (void*)&Dc3wy::WdTitleName, 4);
            Mem::MemWrite(BaseAddr + 0x0DABF, (void*)&Dc3wy::Description, 4);
            Mem::MemWrite(BaseAddr + 0x9DF58, Dc3wy::ChapterTitles, sizeof(Dc3wy::ChapterTitles));
            Mem::JmpWrite(BaseAddr + 0x31870, (intptr_t)&Dc3wy::jmp_audio_play_hook);
            Mem::JmpWrite(BaseAddr + 0x32490, (intptr_t)&Dc3wy::jmp_audio_stop_hook);
        }
    }

    static void Attach() {
        DetourTransactionBegin();
        if (Fun::OldCreateWindowExA) {
            DetourAttach((void**)&Fun::OldCreateWindowExA, Fun::NewCreateWindowExA);
        }
        if (Fun::OldGetGlyphOutlineA) {
            DetourAttach((void**)&Fun::OldGetGlyphOutlineA, Fun::NewGetGlyphOutlineA);
        }
        if (Fun::OldFindFirstFileA)   {
            DetourAttach((void**)&Fun::OldFindFirstFileA,   Fun::NewFindFirstFileA);
        }
        if (Fun::OldCreateFileA) {
            DetourAttach((void**)&Fun::OldCreateFileA, Fun::NewCreateFileA);
        }
        if (Fun::OldCreateFileW) {
            DetourAttach((void**)&Fun::OldCreateFileW, Fun::NewCreateFileW);
        }
        DetourUpdateThread(GetCurrentThread());
        DetourTransactionCommit();
    }
}

extern "C" __declspec(dllexport) void hook(void) { }
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) 
    {
    case DLL_PROCESS_ATTACH:
    //#ifdef _DEBUG
        AllocConsole();
        (void)freopen("CONOUT$", "w", stdout);
        (void)freopen("CONIN$", "r", stdin);
    //#endif
        Hook::Init();
        Hook::Attach();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}