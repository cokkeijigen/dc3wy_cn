﻿#pragma once
#define N "\n"

namespace Dc3wy {
	
	extern void jmp_audio_play_hook();
	extern void jmp_audio_stop_hook();
	extern void jmp_hook_init(intptr_t);
	namespace subtitle {
		extern void init();
		extern void destroy();
	}

	static const char* WdTitleName = \
		"【COKEZIGE STUDIO】Da Capo Ⅲ With You - Beta.0.5";
	static const char* Description = \
		"#########[COKEZIGE STUDIO]#########"
		N			"_staff_"
		N		"1.总之打点字上去！！！"
		N		"2.总之打点字上去！！！"
		N		"3.总之打点字上去！！！"
		N		"4.总之打点字上去！！！";
	static const char* ChapterTitles[][2] = {
		{"WY_9_0610_E1_COM","新たなる試練？"},
		{"WY_9_0609_F25_AOI","お医者さんごっこ"},
		{"WY_9_0609_F24_SRA","貧乳こそ世界の真理"},
		{"WY_9_0609_F23_SRR","緊縛プレイ"},
		{"WY_9_0609_F22_HMN","放課後、教室で……"},
		{"WY_9_0609_F21_RCC","立夏の淫夢"},
		{"WY_9_0609_F2_COM","少女の呼び声"},
		{"WY_9_0609_F1_COM","甘い吐息"},
		{"WY_9_0609_E35_COM","葵の見ている本"},
		{"WY_9_0609_E34_COM","さらの見ている本"},
		{"WY_9_0609_E33_COM","姫乃の見ている本"},
		{"WY_9_0609_E32_COM","シャルルの見ている本"},
		{"WY_9_0609_E31_COM","立夏の見ている本"},
		{"WY_9_0609_E23_COM","微笑みの天使"},
		{"WY_9_0609_E22_COM","時代は美乳／微乳"},
		{"WY_9_0609_E21_COM","爆乳三国志"},
		{"WY_9_0609_E12_COM","素人露出特集"},
		{"WY_9_0609_E11_COM","ソフトＳＭ入門編"},
		{"WY_9_0609_E4_COM","本という名の爆弾Ｄ"},
		{"WY_9_0609_E3_COM","本という名の爆弾Ｃ"},
		{"WY_9_0609_E2_COM","本という名の爆弾Ｂ"},
		{"WY_9_0609_E1_COM","本という名の爆弾Ａ"},
		{"WY_8_XXXX_A1_SMM","すももの笑顔"},
		{"WY_8_0821_C1_SMM","資料提供"},
		{"WY_8_0819_B1_SMM","報告と驚愕と祝福"},
		{"WY_8_0819_A1_SMM","恋人と迎える朝"},
		{"WY_8_0818_E1_SMM","すももと初エッチ"},
		{"WY_8_0818_D1_SMM","小説"},
		{"WY_8_0804_F3_SMM","前世の話"},
		{"WY_8_0804_F2_SMM","宇宙人召喚の儀式"},
		{"WY_8_0804_F1_SMM","お泊まり会"},
		{"WY_8_0801_B1_SMM","非公式新聞部からの挑戦状"},
		{"WY_8_0729_B1_SMM","体験入部"},
		{"WY_8_0721_E1_SMM","取材の申し入れ"},
		{"WY_8_0720_E1_SMM","すももの過去"},
		{"WY_8_0720_B1_SMM","大切な話"},
		{"WY_8_0719_E1_SMM","すももを尾行"},
		{"WY_8_0717_B1_SMM","人間観察"},
		{"WY_8_0715_B1_SMM","消える貌"},
		{"WY_8_0714_A1_SMM","寝不足"},
		{"WY_8_0713_E2_SMM","意識と興味"},
		{"WY_8_0713_E1_SMM","萌えポイント？"},
		{"WY_8_0712_B1_SMM","雪村すもも"},
		{"WY_8_0711_F1_SMM","自身の将来"},
		{"WY_8_0711_E1_SMM","すももの夢"},
		{"WY_7_1014_E2_MKT","今年イチバンの特ダネ"},
		{"WY_7_1014_E1_MKT","ふたりっきりの時間"},
		{"WY_7_1009_A1_MKT",""},
		{"WY_7_1003_E2_MKT","それぞれの特別"},
		{"WY_7_1003_E1_MKT","安心させて"},
		{"WY_7_1003_C2_MKT","秘密のカップル"},
		{"WY_7_1003_C1_MKT","杉並の真意"},
		{"WY_7_1003_A1_MKT","戻らなくていい"},
		{"WY_7_0930_A1_MKT","恋の自覚"},
		{"WY_7_0926_F2_MKT","すももの勘"},
		{"WY_7_0926_F1_MKT","気にしてないから"},
		{"WY_7_0926_B1_MKT","偶然の接触"},
		{"WY_7_0926_A1_MKT","コッツウォルズへ"},
		{"WY_7_0925_B1_MKT","迷子の迷子の美琴さん"},
		{"WY_7_0924_F1_MKT","パジャマの美琴"},
		{"WY_7_0924_D1_MKT","はるばる来たぜ倫敦"},
		{"WY_7_0921_E1_MKT","恋を実らせる方法？"},
		{"WY_7_0920_D1_MKT","旅行のための買い出し"},
		{"WY_7_0920_C1_MKT","あんな風になりたい"},
		{"WY_7_0918_C1_MKT","間接イーブン"},
		{"WY_7_0915_D1_MKT","修学旅行の班作り"},
		{"WY_7_0914_E1_MKT","あたしは謎の女"},
		{"WY_7_0913_E1_MKT","ロンドンに向けて"},
		{"WY_7_0913_A1_MKT","見えない壁"},
		{"WY_6_1514_B1_SKI","エピローグ"},
		{"WY_6_1501_F1_SKI","復活の四季"},
		{"WY_6_1409_A1_SKI","それからの日々"},
		{"WY_6_1408_B1_SKI","耕助の様子"},
		{"WY_6_1401_F2_SKI","霧と耕助と四季と"},
		{"WY_6_1401_F1_SKI","止まってしまった恋人"},
		{"WY_6_1401_D1_SKI","トラブル発生"},
		{"WY_6_1331_A1_SKI","事件の香り"},
		{"WY_6_1329_F2_SKI","結ばれる季節"},
		{"WY_6_1329_F1_SKI","大切な存在"},
		{"WY_6_1329_B1_SKI","切り裂き魔事件"},
		{"WY_6_1318_A1_SKI","皆の反応"},
		{"WY_6_1311_B1_SKI","新学期の始まり"},
		{"WY_6_1310_F1_SKI","明日から新学期"},
		{"WY_6_1310_E1_SKI","付き合ってないの？"},
		{"WY_6_1305_B1_SKI","一緒に過ごす静かな時間"},
		{"WY_6_1301_F1_SKI","巴のアドバイス"},
		{"WY_6_1301_B1_SKI","おせち料理"},
		{"WY_6_1231_F1_SKI","四季と年越し"},
		{"WY_6_1228_F1_SKI","耕助との仲"},
		{"WY_6_1228_B1_SKI","おせっかい耕助"},
		{"WY_6_1225_A1_SKI","昨日はどうだった？"},
		{"WY_6_1224_C1_SKI","四季とパーティー"},
		{"WY_6_1224_A1_SKI","四季をよろしく"},
		{"WY_6_1221_F1_SKI","命がけの任務の後に"},
		{"WY_6_1221_E1_SKI","悪夢の中で"},
		{"WY_5_1231_F1_AOI","新年"},
		{"WY_5_1226_A1_AOI","初デート"},
		{"WY_5_1225_A2_AOI","恋人"},
		{"WY_5_1225_A1_AOI","最後の願い"},
		{"WY_5_1224_A1_AOI","葵ちゃんとクリスマスパーティー"},
		{"WY_5_1220_F1_AOI","葵ちゃんと大浴場のお湯"},
		{"WY_5_1220_E1_AOI","葵ちゃんと風見鶏の寮"},
		{"WY_5_1219_E1_AOI","グニルックの練習"},
		{"WY_5_1219_B1_AOI","グニルックと葵ちゃん"},
		{"WY_5_1218_F1_AOI","手打ち蕎麦"},
		{"WY_5_1217_B1_AOI","海水浴の約束"},
		{"WY_5_1213_F1_AOI","葵ちゃんの記憶"},
		{"WY_5_1213_E1_AOI","葵ちゃんと一緒の下校"},
		{"WY_5_1212_A1_AOI","編入生"},
		{"WY_5_1211_E1_AOI","学園長に相談"},
		{"WY_5_1210_E1_AOI","甦る記憶"},
		{"WY_4_1327_F1_SRA","改めてプロポーズ"},
		{"WY_4_1327_E1_SRA","サラをよろしく"},
		{"WY_4_1327_B1_SRA","サラの雄姿"},
		{"WY_4_1327_A1_SRA","家族"},
		{"WY_4_1326_F1_SRA","清隆の匂い"},
		{"WY_4_1326_E1_SRA","大会前日"},
		{"WY_4_1323_D1_SRA","未来への布石"},
		{"WY_4_1322_C1_SRA","リッカのアドバイス"},
		{"WY_4_1321_B1_SRA","思い出のアクセサリー"},
		{"WY_4_1317_E1_SRA","特訓のサポート"},
		{"WY_4_1315_F1_SRA","大切なサラのために"},
		{"WY_4_1315_C1_SRA","次こそは"},
		{"WY_4_1312_A1_SRA","ぎこちない幸せ"},
		{"WY_4_1311_F1_SRA","素敵な初エッチ"},
		{"WY_4_1311_B1_SRA","公認の仲に"},
		{"WY_4_1311_A1_SRA","状況の整理"},
		{"WY_4_1309_E1_SRA","よみがえる想い"},
		{"WY_3_0713_C1_HMN","まるでハネムーンのように"},
		{"WY_3_0622_B2_HMN","結婚しようよ"},
		{"WY_3_0622_B1_HMN","水上レース開催"},
		{"WY_3_0621_F1_HMN","いよいよ明日"},
		{"WY_3_0618_E1_HMN","代表選手決定！"},
		{"WY_3_0611_F1_HMN","姫乃の差し入れ"},
		{"WY_3_0611_E1_HMN","リッカさんと特訓"},
		{"WY_3_0611_A1_HMN","リッカさんに相談"},
		{"WY_3_0610_D1_HMN","無理しないでね"},
		{"WY_3_0610_B1_HMN","連携の大切さ"},
		{"WY_3_0607_F1_HMN","姫乃の手料理"},
		{"WY_3_0607_E1_HMN","コースの下見"},
		{"WY_3_0607_C1_HMN","なんとしても出場"},
		{"WY_3_0607_A1_HMN","三回目の対抗戦"},
		{"WY_3_0605_E1_HMN","葛木家と五条院家"},
		{"WY_3_0604_F2_HMN","鬼からの解放"},
		{"WY_3_0604_F1_HMN","真剣な想い"},
		{"WY_3_0604_B1_HMN","帰りたいけど"},
		{"WY_3_0604_A2_HMN","今の俺たち"},
		{"WY_3_0604_A1_HMN","ありえなかった過去たち"},
		{"WY_2_9999_A1_SRR","きっと、また会える"},
		{"WY_2_1318_F1_SRR","笑顔でありがとう"},
		{"WY_2_1317_F1_SRR","特別な夜"},
		{"WY_2_1314_F1_SRR","大浴場で"},
		{"WY_2_1313_B1_SRR","地上でお買い物"},
		{"WY_2_1311_F1_SRR","男同士の関係"},
		{"WY_2_1229_C1_SRR","素敵なショッピング"},
		{"WY_2_1228_F1_SRR","お礼とお返し"},
		{"WY_2_1228_E1_SRR","限られた時間の中で"},
		{"WY_2_1228_C1_SRR","約束"},
		{"WY_2_1227_F1_SRR","最初で最後のプレゼント"},
		{"WY_2_1227_A1_SRR","エトの正体"},
		{"WY_2_1226_F1_SRR","二度目の初エッチ"},
		{"WY_2_1226_A1_SRR","初デート再来？"},
		{"WY_2_1225_A2_SRR","確かめ合うふたり"},
		{"WY_2_1225_A1_SRR","夢の中の記憶"},
		{"WY_1_0903_E1_RCC","これからもリッカさんと"},
		{"WY_1_0722_A1_RCC","一夜にして"},
		{"WY_1_0721_F1_RCC","いつまでも一緒に"},
		{"WY_1_0721_E1_RCC","種も仕掛けもある話"},
		{"WY_1_0721_C1_RCC","昔の思い出"},
		{"WY_1_0721_B22_RCC","ずぶ濡れ清隆"},
		{"WY_1_0721_B21_RCC","ずぶ濡れリッカ"},
		{"WY_1_0721_B2_RCC","遊園地デート"},
		{"WY_1_0721_B1_RCC","噂の移動遊園地"},
		{"WY_1_0721_A1_RCC","出立"},
		{"WY_1_0720_F2_RCC","昔の記憶"},
		{"WY_1_0720_F1_RCC","明日が楽しみ"},
		{"WY_1_0720_E1_RCC","帰ってこないリッカ"},
		{"WY_1_0716_B1_RCC","リッカのいない夏休み"},
		{"WY_1_0713_B1_RCC","明日から夏休み"},
		{"WY_1_0713_A1_RCC","終業式の朝"},
		{"WY_1_0709_E1_RCC","何が何でも"},
		{"WY_1_0709_A1_RCC","昨晩のイアン"},
		{"WY_1_0708_F1_RCC","ひょんなことから"},
		{"WY_1_0708_B1_RCC","移動遊園地？"},
		{"WY_1_0707_E1_RCC","彼女のためにできること"},
		{"WY_1_0706_F1_RCC","癒しの存在"},
		{"WY_1_0706_E2_RCC","忙し目のリッカさん"},
		{"WY_1_0706_E1_RCC","あれからの俺たち"},
		{"WY_1_0706_A1_RCC","プロローグ"}
	};
}
#undef N