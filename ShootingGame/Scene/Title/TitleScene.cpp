#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"
#include "TitleScene.h"
#include"../GameMain/GameMainScene.h"

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
	if (cursor_num == 0)
	{
		if (PadInput::OnPressed(XINPUT_BUTTON_A) || KeyInput::GetButton(KEY_INPUT_SPACE))
		{
			return new GameMainScene();
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

}
