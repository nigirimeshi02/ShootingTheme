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
    //コンストラクタ
    Enemy(float x, float y);

    //デストラクタ
    ~Enemy();

    //描画に関すること以外の更新を実装する
    void Update(GameMainScene* gamemain_scene)override;

    //描画に関することの更新を実装する
    void Draw()const override;

    void Hit(int damage)override;

    void Attack(GameMainScene* gamemain_scene, CharaBase* myself, const int& value)override;

    void Init(const int& hp, const float radius);

    NwaySpawner* GetWeapon() { return &weapon; }
};

