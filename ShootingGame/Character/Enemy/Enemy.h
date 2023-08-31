#pragma once
#include "../CharaBase.h"
#include"../../Bullet/Spawner/BulletsSpawner.h"
#include"../../Bullet/Spawner/NwaySpawner.h"

#define NORMAL_ENEMY_RADIUS 15
#define BOSS_ENEMY_RADIUS (NORMAL_ENEMY_RADIUS * 3)

class Enemy :
    public CharaBase
{
private:
    int attack_interval;
    int move_count;

    int hp;
    int max_hp;
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

    void Init(const int& hp, const float radius);

    NwaySpawner* GetWeapon() { return &weapon; }
};

