#pragma once
#include "BulletsSpawner.h"

class NwaySpawner :
    public BulletsSpawner
{
private:
    int numBullets;     //���˂���e�̐�
    int angle_cnt;

    float baseAngle;    //���˂���ŏ��̒e�̌���
    float angleDiff;    // �e���m�̊p�x��
public:
    //�R���X�g���N�^
    NwaySpawner();

    //�f�X�g���N�^
    ~NwaySpawner();

    void Shoot(GameMainScene* gamemain_scene, const CharaBase* myself, const CharaBase* target, const int& value)override;

    //���˂���e�̐����擾����
    int GetNumBullets() { return numBullets; }

    //���˂���e�̐���ݒ肷��
    void SetNumBullets(const int value) { numBullets = value; }
};