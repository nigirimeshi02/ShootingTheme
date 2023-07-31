#include "SphereCollider.h"
#include"DxLib.h"

void SphereCollider::Draw() const
{
	DrawCircleAA(GetLocation().x, GetLocation().y, GetRadius(), 10, 0xff0000, TRUE);
}

bool SphereCollider::HitSphere(const SphereCollider* sphere_collider) const
{
	bool ret = false;
	return ret;
}
