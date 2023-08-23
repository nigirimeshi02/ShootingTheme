#include "Enemy.h"
#include"DxLib.h"
#include"../../Scene/GameMain/GameMainScene.h"

Enemy::Enemy(float x, float y)
{
	location.x = 800 + x;
	location.y = 250 + y;
	radius = 15;

	speed = 3;
	is_show = true;

	attack_interval = 0;
	hp = 50;
	point = 100;

	wepon = NwaySpawner();
}

Enemy::~Enemy()
{

}

void Enemy::Update(GameMainScene* gamemain_scene)
{
	if (hp < 0)
	{
		is_show = false;
		gamemain_scene->AddScore(point);
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

void Enemy::Attack(GameMainScene* gamemain_scene, const CharaBase* myself, const CharaBase* target, const int& value)
{
	if (++attack_interval % 71 == 0)
	{
		is_attack = true;
		wepon.Shoot(gamemain_scene, myself, target, value);
		attack_interval = 0;
	}
	else
	{
		is_attack = false;
	}
}
