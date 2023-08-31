#pragma once
#include "../SceneBase.h"
#include<string>

#define MAX_RANK 5
#define MAX_NAME 10

typedef struct
{
    int number;
    char name[MAX_NAME];
    long score;
}RankingData;

class RankingScene :
    public SceneBase
{
private:
    SceneBase* scene;               //シーン遷移用
    RankingData ranking[MAX_RANK];
public:
    //コンストラクタ
    RankingScene(int score = 0);

    //デストラクタ
    ~RankingScene();

    //描画に関すること以外の更新を実装する
    SceneBase* Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;

    int ReadRanking(RankingData ranking[]);

    void SortRanking(RankingData ranking[]);

    int SaveRanking(RankingData ranking[]);
};