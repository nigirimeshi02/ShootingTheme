#pragma once
#include"../Collider/SphereCollider.h"

class Bullet :public SphereCollider
{
private:
	int damage;

	float move_x;
	float move_y;

	float speed;			//����
	float angle;			//�p�x
	float acceleration;		//���x�̕ω���
	float angleVelocity;	//�p�x�̕ω���

	bool is_show;			//�\��������H
public:
	//�R���X�g���N�^
	Bullet();

	//�f�X�g���N�^
	~Bullet();

	//�`��Ɋւ��邱�ƈȊO�̍X�V����������
	void Update();

	//�`��Ɋւ��邱�Ƃ̍X�V����������
	void Draw()const override;

	//�p�x�ύX����
	void ChangeAngle();

	//damage���擾����
	int* GetDamage() { return &damage; }
	
	//������ݒ肷��
	void SetSpeed(float &speed) { this->speed = speed; }
	
	//�p�x��ݒ肷��
	void SetAngle(const float angle) { this->angle = angle; }

	//���x�̕ω��ʂ�ݒ肷��
	void SetAcceleration(const float& acceleration) { this->acceleration = acceleration; }
	
	//�p�x�̕ω��ʂ�ݒ肷��
	void SetAngleVelecity(const float& anglevelocity) { this->angleVelocity = anglevelocity; }

	//is_show���擾����
	bool GetIsShow() { return is_show; }

	//is_show��ݒ肷��
	void SetIsShow(const bool flg) { is_show = flg; }
};

