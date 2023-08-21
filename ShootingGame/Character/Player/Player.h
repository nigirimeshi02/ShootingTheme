#pragma once
#include "../CharaBase.h"
#include"../../Bullet/Spawner/BulletsSpawner.h"
#include"../../Bullet/Spawner/NwaySpawner.h"

#define MAX_ACCELERATION 2.5f
#define RESPAWN_POS_X 320
#define RESPAWN_POS_Y 360

class Player :
    public CharaBase
{
private:
    int attack_interval;
    int hit_timer;
    int frame_count;
    int score;
    int life;

    float acc_x;
    float acc_y;

    BulletsSpawner* weapon;
public:
    //�R���X�g���N�^
    Player();

    //�f�X�g���N�^
    ~Player();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    void Update(GameMainScene* gamemain_scene)override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;

    void Hit(int damage)override;

    void Respawn();
    
    void Attack(GameMainScene* gamemain_scene, CharaBase* character, int& value);

    int GetLife()
    {
        return life;
    }
};

