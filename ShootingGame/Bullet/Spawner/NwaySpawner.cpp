#include "NwaySpawner.h"
#include"../../Scene/GameMain/GameMainScene.h"

NwaySpawner::NwaySpawner()
{
	numBullets = 1;
	baseAngle = 0;
	angleDiff = 0;
}

NwaySpawner::~NwaySpawner()
{

}

void NwaySpawner::Shoot(GameMainScene* gamemain_scene, CharaBase* character, int &value)
{
	if (gamemain_scene->GetBullet(value)->GetIsShow() == false)
	{
		//for (int i = 0; i < numBullets; i++)
		//{
			gamemain_scene->GetBullet(value)->SetIsShow(true);
			gamemain_scene->GetBullet(value)->SetLocation({character->GetLocation().x + character->GetRadius() ,character->GetLocation().y + 0 * 10});
		//}
	}
}
