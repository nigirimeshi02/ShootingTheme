#include "Bullet.h"
#include"../common.h"
#include"DxLib.h"

Bullet::Bullet()
{
	location.x = 0;
	location.y = 0;
	radius = 7;

	damage = 1;

	show_time = 0;

	move_x = 0;
	move_y = 0;

	speed = 0;
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
		++show_time;
		if (angle < 0.5f)
		{
			location.x += (speed * acceleration) + move_x;
			location.y -= move_y;
		}
		else
		{
			location.x -= (speed * acceleration) + move_x;
			location.y += move_y;
		}
	}

	if (location.x < radius || location.x > SCREEN_WIDTH - radius || show_time > 60)
	{
		show_time = 0;
		is_show = false;
	}

	ChangeAngle();
}

void Bullet::Draw() const
{
	if (is_show)
	{
		DrawCircleAA(GetLocation().x, GetLocation().y, GetRadius(), 10, 0xffff00, TRUE);
	}
}

void Bullet::ChangeAngle()
{
	float rad = angle * (float)M_PI * 2;
	move_x = speed * cosf(rad);
	move_y = speed * sinf(rad);
}
