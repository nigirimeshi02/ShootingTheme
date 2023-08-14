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
    //コンストラクタ
    Enemy();

    //デストラクタ
    ~Enemy();

    //描画に関すること以外の更新を実装する
    void Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;

    void Hit(int damage)override;
};

