#pragma once
#include "../CharaBase.h"
#include"../../Bullet/Spawner/BulletsSpawner.h"
#include"../../Bullet/Spawner/NwaySpawner.h"

class Enemy :
    public CharaBase
{
private:
    int hp;
    int point;
    NwaySpawner* wepon;
public:
    //�R���X�g���N�^
    Enemy();

    //�f�X�g���N�^
    ~Enemy();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    void Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;

    void Hit(int damage)override;
};

