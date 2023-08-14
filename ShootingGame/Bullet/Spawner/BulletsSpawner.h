#pragma once
#include"../../Bullet/Bullet.h"
#include"../../Character/CharaBase.h"

#define MAX_BULLET 20


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

	virtual void Shoot(Bullet* bullt, CharaBase* character, const int value);
};

