#pragma once
#include"../../Bullet/Bullet.h"
#include"../../Character/CharaBase.h"

#define PLAYER_MAX_BULLET 30
#define ENEMY_MAX_BULLET 30


class BulletsSpawner
{
protected:
	float speed;			//����
	float angle;			//�p�x
	float acceleration;		//���x�̕ω���
	float angleVelocity;	//�p�x�̕ω���
public:
	//�R���X�g���N�^
	BulletsSpawner();

	//�f�X�g���N�^
	~BulletsSpawner();

	virtual void Shoot(GameMainScene* gamemain_scene, const CharaBase* myself, const CharaBase* target, const int& value);
};

