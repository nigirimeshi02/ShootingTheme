#include "Enemy.h"
#include"DxLib.h"
#include"../../Scene/GameMain/GameMainScene.h"

Enemy::Enemy()
{
	location.x = 600;
	location.y = 400;
	radius = 15;

	speed = 3;
	is_show = true;

	attack_interval = 0;
	hp = 50;
	point = 100;

	wepon = new NwaySpawner();
}

Enemy::~Enemy()
{
	delete wepon;
}

void Enemy::Update(GameMainScene* gamemain_scene)
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

void Enemy::Attack(Bullet* bullet, CharaBase* character, const int value)
{
	if (++attack_interval % 61 == 0)
	{
		wepon->Shoot(bullet, character, value);
	}
}
