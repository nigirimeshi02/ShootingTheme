#pragma once
#include"../../Bullet/Bullet.h"
#include"../../Character/CharaBase.h"

#define MAX_BULLET 20


class BulletsSpawner
{
private:
	float speed;			//速さ
	float angle;			//角度
	float acceleration;		//速度の変化量
	float angleVelocity;	//角度の変化量
public:
	//コンストラクタ
	BulletsSpawner();

	//デストラクタ
	~BulletsSpawner();

	virtual void Shoot(Bullet* bullt, CharaBase* character, const int value);
};

