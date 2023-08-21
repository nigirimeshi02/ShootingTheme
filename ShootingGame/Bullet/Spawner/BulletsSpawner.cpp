#include "BulletsSpawner.h"
#include"../../Scene/GameMain/GameMainScene.h"

BulletsSpawner::BulletsSpawner()
{
	speed = 3;
	angle = 0;
	acceleration = 0;
	angleVelocity = 0;
}

BulletsSpawner::~BulletsSpawner()
{

}

void BulletsSpawner::Shoot(GameMainScene* gamemain_scene, CharaBase* character,  int &value)
{
	//for (int i = 0; i < PLAYER_MAX_BULLET + ENEMY_MAX_BULLET; i++);
	//{
		if (gamemain_scene->GetBullet(value)->GetIsShow() == false)
		{
			gamemain_scene->GetBullet(value)->SetIsShow(true);
			gamemain_scene->GetBullet(value)->SetLocation({ character->GetLocation().x + character->GetRadius() ,character->GetLocation().y });
		}
	//}
}
