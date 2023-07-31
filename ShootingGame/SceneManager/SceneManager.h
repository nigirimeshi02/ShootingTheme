#pragma once
#include "AbstractScene.h"

class SceenManager :
    public AbstractScene
{
private:
    //現在のシーン
    AbstractScene* now_sceen;
public:
    //コンストラクタ
    SceenManager(AbstractScene* scene) :now_sceen(scene) {};

    //デストラクタ
    ~SceenManager() { delete now_sceen; }

    //描画に関すること以外の更新を実装する
    AbstractScene* Update()override;

    //描画に関することを
    void Draw()const override;
};

