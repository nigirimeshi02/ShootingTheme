#pragma once
#include "../Collider/SphereCollider.h"

class CharaBase :
    public SphereCollider
{
private:

protected:
    int image;

    float speed;

    bool is_show;
public:
    //コンストラクタ
    CharaBase();

    //デストラクタ
    ~CharaBase() {};

    //描画に関すること以外の更新を実装する
    virtual void Update() {};

    //描画に関することの更新を実装する
    virtual void Draw()const {};

    virtual void Hit(int damage) = 0;

    bool GetIsShow()
    {
        return is_show;
    }

    void SetIsShow(const bool flg)
    {
        is_show = flg;
    }
};

