#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"
#include "TitleScene.h"
#include"../GameMain/GameMainScene.h"
#include"../Ranking/RankingScene.h"
#include"../End/EndScene.h"

#define DEBUG

TitleScene::TitleScene()
{
	interval = 0;
	cursor_num = 0;
	cursor_y = 0;
}

TitleScene::~TitleScene()
{

}

SceneBase* TitleScene::Update()
{
	cursor_y = cursor_num * 50;

	if (interval < 15)
	{
		interval++;
	}

	//上
	if ((PadInput::GetLStick().y > QUARTER && PadInput::GetLStick().y <= QUARTER * 4 || KeyInput::GetKeyDown(KEY_INPUT_W)) && interval >= 15)
	{
		cursor_num--;
		interval = 0;
		if (cursor_num < 0)
		{
			cursor_num = 2;
		}
	}

	//下
	if ((PadInput::GetLStick().y < -QUARTER && PadInput::GetLStick().y >= -QUARTER * 4 - 1 || KeyInput::GetKeyDown(KEY_INPUT_S)) && interval >= 15)
	{
		cursor_num++;
		interval = 0;
		if (cursor_num > 2)
		{
			cursor_num = 0;
		}
	}

	if (cursor_num == 0)
	{
		//ゲームメインへ
		if (PadInput::OnButton(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			return new GameMainScene();
		}
	}
	else if (cursor_num == 1)
	{
		//ランキングへ
		if (PadInput::OnButton(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			return new RankingScene();
		}
	}
	else
	{
		//エンド画面へ
		if (PadInput::OnButton(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			return new EndScene();
		}
	}

	return this;
}

void TitleScene::Draw() const
{
#ifdef DEBUG
	DrawFormatString(0, 20, 0xffffff, "%d %d", KeyInput::GetMouseLocationX(), KeyInput::GetMouseLocationY());
	DrawFormatString(0, 40, 0xffffff, "%d %d", PadInput::GetLStick().x, PadInput::GetRStick().x);
	DrawString(0, 0, "Title", 0xffffff, TRUE);
#endif // DEBUG

	//カーソル
	DrawTriangle(480, 400 + cursor_y, 450, 380 + cursor_y, 450, 420 + cursor_y, 0xffffff, TRUE);

	SetFontSize(36);

	DrawString(540, 380, "スタート", 0xffffff);

	DrawString(540, 430, "ランキング", 0xffffff);

	DrawString(540, 480, "終了", 0xffffff);

	SetFontSize(16);
}
