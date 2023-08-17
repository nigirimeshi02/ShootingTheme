#pragma once
#include "BulletsSpawner.h"

class NwaySpawner :
    public BulletsSpawner
{
private:
    int numBullets;     //発射する弾の数
    float baseAngle;    //発射する最初の弾の向き
    float angleDiff;    // 弾同士の角度差
public:
    //コンストラクタ
    NwaySpawner();

    //デストラクタ
    ~NwaySpawner();

    void Shoot(Bullet* bullet, CharaBase* character, const int value)override;
};