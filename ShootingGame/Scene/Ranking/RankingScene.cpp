#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"
#include "RankingScene.h"
#include"../Title/TitleScene.h"

#define DEBUG

RankingScene::RankingScene()
{

}

RankingScene::~RankingScene()
{

}

SceneBase* RankingScene::Update()
{
	if (PadInput::OnPressed(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
	{
		return new TitleScene();
	}

	return this;
}

void RankingScene::Draw() const
{
#ifdef DEBUG
	DrawString(0, 0, "Ranking", 0xffffff, TRUE);
#endif // DEBUG

	SetFontSize(36);

	DrawString(360, 580, "Aボタンを押してタイトルへ戻る", 0xffffff);

	SetFontSize(16);
}
