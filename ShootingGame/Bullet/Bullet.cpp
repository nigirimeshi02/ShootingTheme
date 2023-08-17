#include "Bullet.h"
#include"../common.h"
#include"DxLib.h"

Bullet::Bullet()
{
	location.x = 0;
	location.y = 0;
	radius = 7;

	damage = 10;
	speed = 10;
	angle = 0;
	acceleration = 1;
	angleVelocity = 0;

	is_show = false;
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	if (is_show)
	{
		location.x += speed * acceleration;
	}
	if (location.x < radius || location.x > SCREEN_WIDTH - radius)
	{
		is_show = false;
	}
}

void Bullet::Draw() const
{
	if (is_show)
	{
		DrawCircleAA(GetLocation().x, GetLocation().y, GetRadius(), 10, 0xffff00, TRUE);
	}
}
