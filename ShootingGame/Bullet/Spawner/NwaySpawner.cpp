#include "NwaySpawner.h"

NwaySpawner::NwaySpawner()
{
	numBullets = 1;
	baseAngle = 0;
	angleDiff = 0;
}

NwaySpawner::~NwaySpawner()
{

}

void NwaySpawner::Shoot(Bullet* bullet, CharaBase* character, const int value)
{
	if (bullet->GetIsShow() == false)
	{
		for (int i = 0; i < numBullets; i++)
		{
			bullet->SetIsShow(true);
			bullet->SetLocation({ character->GetLocation().x + character->GetRadius() ,character->GetLocation().y + i * 10 });
		}
	}
}
