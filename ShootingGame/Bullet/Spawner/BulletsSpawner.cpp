#include "BulletsSpawner.h"

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

void BulletsSpawner::Shoot(Bullet* bullet, CharaBase* character, const int value)
{
	if (bullet->GetIsShow() == false)
	{
		bullet->SetIsShow(true);
		bullet->SetLocation({ character->GetLocation().x + character->GetRadius() ,character->GetLocation().y });
	}
}
