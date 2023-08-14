#pragma once
#include"../Collider/SphereCollider.h"

class Bullet :public SphereCollider
{
private:
	int damage;

	float speed;			//����
	float angle;			//�p�x
	float acceleration;		//���x�̕ω���
	float angleVelocity;	//�p�x�̕ω���

	bool is_show;
public:
	//�R���X�g���N�^
	Bullet();

	//�f�X�g���N�^
	~Bullet();

	//�`��Ɋւ��邱�ƈȊO�̍X�V����������
	void Update();

	//�`��Ɋւ��邱�Ƃ̍X�V����������
	void Draw()const override;

	int* GetDamage()
	{
		return &damage;
	}

	bool GetIsShow()
	{
		return is_show;
	}

	void SetIsShow(const bool flg)
	{
		is_show = flg;
	}
};

