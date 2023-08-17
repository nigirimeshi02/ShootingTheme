#pragma once
#include "BulletsSpawner.h"

class NwaySpawner :
    public BulletsSpawner
{
private:
    int numBullets;     //���˂���e�̐�
    float baseAngle;    //���˂���ŏ��̒e�̌���
    float angleDiff;    // �e���m�̊p�x��
public:
    //�R���X�g���N�^
    NwaySpawner();

    //�f�X�g���N�^
    ~NwaySpawner();

    void Shoot(Bullet* bullet, CharaBase* character, const int value)override;
};