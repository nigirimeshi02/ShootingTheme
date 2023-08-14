#pragma once
#include "../SceneBase.h"
#include"../../Character/Player/Player.h"
#include"../../Character/Enemy/Enemy.h"
#include"../../Bullet/Bullet.h"

class GameMain :
    public SceneBase
{
private:
    int player_life;

    Player* player;
    Enemy* enemy;
    Bullet* bullets[MAX_BULLET];
public:
    //コンストラクタ
    GameMain();

    //デストラクタ
    ~GameMain();

    //描画に関すること以外の更新を実装する
    SceneBase* Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;

    //当たり判定のチェック
    void HitCheck();

    //弾の配列に新しくデータを作成する
    void SpawnBullet();
};

