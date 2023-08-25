#include "Enemy.h"
#include"DxLib.h"
#include"../../common.h"
#include"../../Scene/GameMain/GameMainScene.h"

#define NORMAL_ENEMY_RADIUS 15
#define BOSS_ENEMY_RADIUS (NORMAL_ENEMY_RADIUS * 3)

Enemy::Enemy(float x, float y)
{
	location.x = 800 + x;
	location.y = 250 + y;
	radius = NORMAL_ENEMY_RADIUS;

	speed = 3;
	is_show = false;
	character_state = ENEMY;

	attack_interval = 0;
	move_count = 0;

	hp = 50;
	point = 100;

	weapon = NwaySpawner();
}

Enemy::~Enemy()
{

}

void Enemy::Update(GameMainScene* gamemain_scene)
{
	if (hp <= 0)
	{
		is_show = false;
		gamemain_scene->AddScore(point);
	}

	if (is_show)
	{
		++move_count;

		if (move_count < 60)
		{
			location.y++;
		}
		else
		{
			if (move_count < 120)
			{
				location.y--;
			}
			else
			{
				move_count = 0;
			}
		}	

		//xŽ²‚ÌˆÚ“®§ŒÀ
		if (location.x < radius || location.x + radius > SCREEN_WIDTH)
		{
			if (location.x < radius)
			{
				location.x = radius;
			}
			else
			{
				location.x = SCREEN_WIDTH - radius;
			}
		}

		//yŽ²‚ÌˆÚ“®§ŒÀ
		if (location.y < radius || location.y + radius > SCREEN_HEIGHT)
		{
			if (location.y < radius)
			{
				location.y = radius;
			}
			else
			{
				location.y = SCREEN_HEIGHT - radius;
			}
		}

		gamemain_scene->HitCheck();
	}
}

void Enemy::Draw() const
{
	if (is_show)
	{
		DrawCircleAA(location.x, location.y, radius, 10, 0xff0000, TRUE);
		
		DrawFormatStringF(location.x - (radius + 5), location.y - (radius + 15), 0xffffff, "%d/50", hp);
	}
}

void Enemy::Hit(int damage)
{
	hp -= damage;
}

void Enemy::Attack(GameMainScene* gamemain_scene, CharaBase* myself, const int& value)
{
	if (++attack_interval % 61 == 0)
	{
		weapon.Shoot(gamemain_scene, myself, value);
		attack_interval = 0;
	}
	else
	{

	}
}

void Enemy::Init(const int& hp)
{
	is_show = false;

	attack_interval = 0;
	move_count = 0;

	this->hp = hp;
}
