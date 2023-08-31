#pragma once
#include "../SceneBase.h"
#include<string>    

#define MAX_CHARACTER 26        //アルファベットの文字数
#define ROW 3                   //列
#define COL 9                   //行
#define INTERVAL 15

using namespace std;

class InputRankingScene :
    public SceneBase
{
private:
    static const char char_set[MAX_CHARACTER];

    char* player_name;

    int interval;
    int cursor;

    string name;
public:
    //コンストラクタ
    InputRankingScene(char name[]);

    //デストラクタ
    ~InputRankingScene();

    //描画に関すること以外の更新を実装する
    SceneBase* Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;

    bool OnUp();

    bool OnDown();

    bool OnLeft();

    bool OnRight();
};

