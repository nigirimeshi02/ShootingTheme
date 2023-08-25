#include "BulletsSpawner.h"
#include"../../Scene/GameMain/GameMainScene.h"
#include"../../common.h"

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

void BulletsSpawner::Shoot(GameMainScene* gamemain_scene, CharaBase* myself, const int& value)
{
	if (gamemain_scene->GetBullet(value)->GetIsShow() == false)
	{
		for (int i = 0; i < 3; i++)
		{
			if (gamemain_scene->GetEnemy(i)->GetLocation().x > myself->GetLocation().x)
			{
				angle = 0.f;
				gamemain_scene->GetBullet(value)->SetLocation({ myself->GetLocation().x + myself->GetRadius() ,myself->GetLocation().y });
			}
			else
			{
				angle = 1.f;
				gamemain_scene->GetBullet(value)->SetLocation({ myself->GetLocation().x + (myself->GetRadius() * -angle) ,myself->GetLocation().y });
			}
		}
		
		gamemain_scene->GetBullet(value)->SetIsShow(true);
		gamemain_scene->GetBullet(value)->SetSpeed(speed);
		gamemain_scene->GetBullet(value)->SetAngle(angle);
		gamemain_scene->GetBullet(value)->SetAcceleration(acceleration);
		gamemain_scene->GetBullet(value)->SetAngleVelecity(angleVelocity);
		gamemain_scene->GetBullet(value)->SetLocation({ myself->GetLocation().x + myself->GetRadius() ,myself->GetLocation().y });
	}
}
