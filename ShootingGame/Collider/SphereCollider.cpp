#include "SphereCollider.h"
#include"DxLib.h"

SphereCollider::SphereCollider()
{
	this->location.x = 0;
	this->location.y = 0;
	this->radius = .5f;
}

void SphereCollider::Draw() const
{
	DrawCircleAA(GetLocation().x, GetLocation().y, GetRadius(), 10, 0xffffff, TRUE);
}

bool SphereCollider::CheckCollision(const SphereCollider* sphere_collider) const
{
	bool ret = false;

	//‰~‚Æ‰~‚Ì‹——£
	float distance = (sphere_collider->GetLocation().x - GetLocation().x) * (sphere_collider->GetLocation().x - GetLocation().x) +
					(sphere_collider->GetLocation().y - GetLocation().y) * (sphere_collider->GetLocation().y - GetLocation().y);

	if (distance <= (radius + sphere_collider->GetRadius()) * (radius + sphere_collider->GetRadius()))
	{
		ret = true;
	}

	return ret;
}
