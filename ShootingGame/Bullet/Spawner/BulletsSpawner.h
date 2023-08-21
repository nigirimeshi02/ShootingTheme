#pragma once
#include"../../Bullet/Bullet.h"
#include"../../Character/CharaBase.h"

#define PLAYER_MAX_BULLET 20
#define ENEMY_MAX_BULLET 40


class BulletsSpawner
{
private:
	float speed;			//����
	float angle;			//�p�x
	float acceleration;		//���x�̕ω���
	float angleVelocity;	//�p�x�̕ω���
public:
	//�R���X�g���N�^
	BulletsSpawner();

	//�f�X�g���N�^
	~BulletsSpawner();

	virtual void Shoot(GameMainScene* gamemain_scene, CharaBase* character,  int &value);
};

