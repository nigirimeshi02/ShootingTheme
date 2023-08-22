#pragma once
#include"../../Bullet/Bullet.h"
#include"../../Character/CharaBase.h"

#define PLAYER_MAX_BULLET 30
#define ENEMY_MAX_BULLET 30


class BulletsSpawner
{
protected:
	float speed;			//速さ
	float angle;			//角度
	float acceleration;		//速度の変化量
	float angleVelocity;	//角度の変化量
public:
	//コンストラクタ
	BulletsSpawner();

	//デストラクタ
	~BulletsSpawner();

	virtual void Shoot(GameMainScene* gamemain_scene, const CharaBase* myself, const CharaBase* target, const int& value);
};

