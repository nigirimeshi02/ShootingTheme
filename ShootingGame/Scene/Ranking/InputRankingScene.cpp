#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"
#include "InputRankingScene.h"
#include"../Title/TitleScene.h"

#define DEBUG

InputRankingScene::InputRankingScene()
{

}

InputRankingScene::~InputRankingScene()
{

}

SceneBase* InputRankingScene::Update()
{
	if (PadInput::OnPressed(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
	{
		return new TitleScene();
	}

	return this;
}

void InputRankingScene::Draw() const
{
#ifdef DEBUG
	DrawString(0, 0, "InputRanking", 0xffffff, TRUE);
#endif // DEBUG
}
