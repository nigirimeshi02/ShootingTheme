#include "Enemy.h"
#include"DxLib.h"
#include"../../common.h"
#include"../../Scene/GameMain/GameMainScene.h"

Enemy::Enemy(float x, float y)
{
	location.x = 800 + x;
	location.y = 250 + y;
	radius = 15;

	speed = 3;
	is_show = true;

	attack_interval = 0;
	move_count = 0;

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
