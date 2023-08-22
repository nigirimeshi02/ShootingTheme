#include "BulletsSpawner.h"
#include"../../Scene/GameMain/GameMainScene.h"

BulletsSpawner::BulletsSpawner()
{
	speed = 10;
	angle = 0;
	acceleration = 1;
	angleVelocity = 0;
}

BulletsSpawner::~BulletsSpawner()
{

}

void BulletsSpawner::Shoot(GameMainScene* gamemain_scene, const CharaBase* myself, const CharaBase* target, const int& value)
{
	if (gamemain_scene->GetBullet(value)->GetIsShow() == false)
	{
		this->angle = atan2f(target->GetLocation().y, target->GetLocation().x);
		gamemain_scene->GetBullet(value)->SetIsShow(true);
		gamemain_scene->GetBullet(value)->SetSpeed(speed);
		gamemain_scene->GetBullet(value)->SetAngle(angle);
		gamemain_scene->GetBullet(value)->SetAcceleration(acceleration);
		gamemain_scene->GetBullet(value)->SetAngleVelecity(angleVelocity);
		gamemain_scene->GetBullet(value)->SetLocation({ myself->GetLocation().x + myself->GetRadius() ,myself->GetLocation().y });
	}
}
