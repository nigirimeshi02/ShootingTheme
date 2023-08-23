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

    NwaySpawner wepon;
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

    void Attack(GameMainScene* gamemain_scene, const CharaBase* myself, const CharaBase* target, const int& value)override;
};

