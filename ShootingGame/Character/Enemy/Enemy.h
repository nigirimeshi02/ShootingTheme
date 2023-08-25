#pragma once
#include "../CharaBase.h"
#include"../../Bullet/Spawner/BulletsSpawner.h"
#include"../../Bullet/Spawner/NwaySpawner.h"

class Enemy :
    public CharaBase
{
private:
    int attack_interval;
    int move_count;

    int hp;
    int point;

    NwaySpawner weapon;
public:
    //�R���X�g���N�^
    Enemy(float x, float y);

    //�f�X�g���N�^
    ~Enemy();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    void Update(GameMainScene* gamemain_scene)override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;

    void Hit(int damage)override;

    void Attack(GameMainScene* gamemain_scene, CharaBase* myself, const int& value)override;

    void Init(const int& hp);

    NwaySpawner* GetWeapon() { return &weapon; }
};

