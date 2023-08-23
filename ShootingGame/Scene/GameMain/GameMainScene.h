#pragma once
#include "../SceneBase.h"
#include"../../Character/Player/Player.h"
#include"../../Character/Enemy/Enemy.h"
#include"../../Bullet/Bullet.h"

#define ENEMY 3     //敵の数

class GameMainScene :
    public SceneBase
{
private:
    int life;
    int attack_interval;
    int respawn_interval;

    bool is_clear;

    Player* player;
    Enemy* enemy[ENEMY];
    Bullet* bullets[PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * ENEMY)]; /*プレイヤーと敵でわけたほうがいい、もしくは両方の分配列をつくる*/
public:
    //コンストラクタ
    GameMainScene();

    //デストラクタ
    ~GameMainScene();

    //描画に関すること以外の更新を実装する
    SceneBase* Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;

    //当たり判定のチェック
    void HitCheck();

    //弾の配列に新しくデータを作成する
    void SpawnBullet();

    void AddScore(int& score) { player->SetScore(score); }

    //弾の配列を取得する
    Bullet* GetBullet(const int& value) { return bullets[value]; }
};

