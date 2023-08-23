#include "EndScene.h"

#define DEBUG

EndScene::EndScene()
{

}

EndScene::~EndScene()
{

}

SceneBase* EndScene::Update()
{
	return nullptr;
}

void EndScene::Draw() const
{
#ifdef DEBUG
	DrawString(0, 0, "End", 0xffffff, TRUE);
#endif // DEBUG
}
