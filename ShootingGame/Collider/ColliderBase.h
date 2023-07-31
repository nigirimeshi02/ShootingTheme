#pragma once
#define _USE_MATH_DEFINES

#include<math.h>

struct Location
{
	float x;
	float y;
};

class ColliderBase
{
protected:
	Location location;
public:
	//�R���X�g���N�^
	ColliderBase(Location location = { 0,0 })
	{
		this->location = location;
	}

	//�f�X�g���N�^
	~ColliderBase() {};

	virtual void Draw()const = 0;

	//SphereCollider�Ƃ̓����蔻��
	virtual bool HitSphere(const class SphereCollider* spherecollider)const = 0;

	//���S���W�̎擾
	Location GetLocation()const
	{
		return location;
	}

	//���S���W�̐ݒ�
	virtual Location SetLocation(Location location)
	{
		this->location = location;
	}
};