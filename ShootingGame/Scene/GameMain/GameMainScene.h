#pragma once
#include "../SceneBase.h"
#include"../../Character/Player/Player.h"
#include"../../Character/Enemy/Enemy.h"
#include"../../Bullet/Bullet.h"

#define MAX_ENEMY 3     //敵の数
#define MAX_STAGE 5

class GameMainScene :
    public SceneBase
{
private:
    int life;

    int attack_interval;
    int respawn_interval;
    int wait_timer;

    int stage_count;

    bool is_clear;              //ステージをクリアした？
    bool game_clear_flg;
    bool game_over_flg;

    Player* player;
    Enemy* enemy[MAX_ENEMY];
    Bullet* bullets[PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * MAX_ENEMY)]; /*プレイヤーと敵でわけたほうがいい、もしくは両方の分配列をつくる*/
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

    void NextStage();

    void CreateStage(const int stage);

    void AddScore(int& score) { player->SetScore(score); }

    //弾の配列を取得する
    Bullet* GetBullet(const int& value) { return bullets[value]; }

    Player* GetPlayer() { return player; }

    Enemy* GetEnemy(const int& value) { return enemy[value]; }
};

