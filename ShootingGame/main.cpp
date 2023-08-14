#include"SceneManager/SceneManager.h"
#include"common.h"
#include"Scene/GameMain/GameMain.h"
#include"InputControl/Key/KeyInput.h"
#include"InputControl/Pad/PadInput.h"

/************************************************
* プログラムの開始
*************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	double nextTime = GetNowCount();	//システム時間の取得

	SetMainWindowText("シューティングゲーム");	//タイトル

	ChangeWindowMode(TRUE);		//ウィンドウモードで起動

	SetAlwaysRunFlag(TRUE);		//常にアクティブ状態にする

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//画面サイズの設定

	if (DxLib_Init() == -1)return -1;	//DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);		//描画先を裏にする

	SceenManager* sceenManager = new SceenManager(dynamic_cast<AbstractScene*>(new GameMain()));

	//ゲームループ
	while ((ProcessMessage() == 0) &&
		sceenManager->Update() != nullptr &&
		!(CheckHitKey(KEY_INPUT_ESCAPE)))
	{
		ClearDrawScreen();		//画面の初期化

		KeyInput::Update();

		PadInput::Update();

		sceenManager->Draw();

		ScreenFlip();			//裏画面の内容を表画面に反映

		nextTime += 1.0 / 60.0 * 1000.0;		//フレームレートの設定＋ミリ単位に合わせる

		//現在の時間が現在のシステム時間をこえたら
		//現在の時間を現在のシステム時間を引いた分だけ待たせる
		if (nextTime > GetNowCount())
		{
			WaitTimer((int)nextTime - GetNowCount());
		}
		//現在のシステム時間を取得
		else
		{
			nextTime = GetNowCount();
		}
	}

	DxLib_End();		//DXライブラリ使用の終了処理

	return 0;

}