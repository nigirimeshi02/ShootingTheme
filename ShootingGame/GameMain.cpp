#include "GameMain.h"

GameMain::GameMain()
{

}

GameMain::~GameMain()
{

}

SceneBase* GameMain::Update()
{
	return this;
}

void GameMain::Draw() const
{
	DrawString(0, 0, "GameMain", 0xffffff, TRUE);
}
