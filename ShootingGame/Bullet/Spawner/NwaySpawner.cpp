#include "NwaySpawner.h"
#include"../../Scene/GameMain/GameMainScene.h"

NwaySpawner::NwaySpawner()
{
	numBullets = 3;
	angle_cnt = 0;

	baseAngle = 0;
	angleDiff = 0;
}

NwaySpawner::~NwaySpawner()
{

}

void NwaySpawner::Shoot(GameMainScene* gamemain_scene, const CharaBase* myself, const CharaBase* target, const int& value)
{
	if (gamemain_scene->GetBullet(value)->GetIsShow() == false)
	{
		gamemain_scene->GetBullet(value)->SetIsShow(true);

		if (target->GetLocation().x > myself->GetLocation().x)
		{
			baseAngle = 0.f;
			gamemain_scene->GetBullet(value)->SetLocation({ myself->GetLocation().x + myself->GetRadius() ,myself->GetLocation().y });
		}
		else
		{
			baseAngle = 1.f;
			gamemain_scene->GetBullet(value)->SetLocation({ myself->GetLocation().x + (myself->GetRadius() * -baseAngle) ,myself->GetLocation().y });
		}

		gamemain_scene->GetBullet(value)->SetSpeed(speed);
		gamemain_scene->GetBullet(value)->SetAcceleration(acceleration);
		gamemain_scene->GetBullet(value)->SetAngleVelecity(angleVelocity);
		gamemain_scene->GetBullet(value)->SetLocation({ myself->GetLocation().x + myself->GetRadius() ,myself->GetLocation().y });

		if (numBullets == 1)
		{
			gamemain_scene->GetBullet(value)->SetAngle(baseAngle);
		}
		else if (numBullets == 2)
		{
			angleDiff = 0.05f;
			if (value % 2 == 0)
			{
				gamemain_scene->GetBullet(value)->SetAngle(baseAngle - angleDiff);
			}
			else
			{
				gamemain_scene->GetBullet(value)->SetAngle(baseAngle + angleDiff);
			}
		}
		else
		{
			angleDiff = 0.1f;
			if (angle_cnt == 0)
			{
				gamemain_scene->GetBullet(value)->SetAngle(baseAngle - angleDiff);
				angle_cnt++;
			}
			else if (angle_cnt == 1)
			{
				gamemain_scene->GetBullet(value)->SetAngle(baseAngle + angleDiff);
				angle_cnt++;
			}
			else if (angle_cnt == 2)
			{
				gamemain_scene->GetBullet(value)->SetAngle(baseAngle);
				angle_cnt = 0;
			}
		}
	}
}
