#include "Enemy.h"
#include"DxLib.h"

Enemy::Enemy()
{
	location.x = 600;
	location.y = 400;
	radius = 15;

	speed = 3;
	is_show = true;

	hp = 50;
	point = 100;
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	if (hp < 0)
	{
		is_show = false;
	}

	if (is_show)
	{

	}
}

void Enemy::Draw() const
{
	if (is_show)
	{
		DrawCircleAA(GetLocation().x, GetLocation().y, GetRadius(), 10, 0xff0000, TRUE);
	}
}

void Enemy::Hit(int damage)
{
	hp -= damage;
}
