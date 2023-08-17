#pragma once
#include "../CharaBase.h"
#include"../../Bullet/Spawner/BulletsSpawner.h"
#include"../../Bullet/Spawner/NwaySpawner.h"

class Enemy :
    public CharaBase
{
private:
    int attack_interval;
    int hp;
    int point;
    NwaySpawner* wepon;
public:
    //コンストラクタ
    Enemy();

    //デストラクタ
    ~Enemy();

    //描画に関すること以外の更新を実装する
    void Update(GameMainScene* gamemain_scene)override;

    //描画に関することの更新を実装する
    void Draw()const override;

    void Hit(int damage)override;

    void Attack(Bullet* bullet, CharaBase* character, const int value);
};

