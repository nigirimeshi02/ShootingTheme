#pragma once
#include "BulletsSpawner.h"

class NwaySpawner :
    public BulletsSpawner
{
private:
    int numBullets;     //発射する弾の数
    int angle_cnt;

    float baseAngle;    //発射する最初の弾の向き
    float angleDiff;    // 弾同士の角度差
public:
    //コンストラクタ
    NwaySpawner();

    //デストラクタ
    ~NwaySpawner();

    void Shoot(GameMainScene* gamemain_scene, const CharaBase* myself, const CharaBase* target, const int& value)override;

    //発射する弾の数を取得する
    int GetNumBullets() { return numBullets; }

    //発射する弾の数を設定する
    void SetNumBullets(const int value) { numBullets = value; }
};