#pragma once
#define _USE_MATH_DEFINES

#include<math.h>

struct Location
{
    float x;
    float y;
};

class SphereCollider
{
protected:
    Location location;
    float radius;       //半径
public:
    //コンストラクタ
    SphereCollider();

    virtual void Draw()const;

    //SphereColliderとの当たり判定
    bool CheckCollision(const SphereCollider* sphere_collider)const;

    //中心座標の取得
    Location GetLocation()const
    {
        return location;
    }

    //中心座標の設定
    virtual void SetLocation(Location location)
    {
        this->location = location;
    }

    //半径の取得
    float GetRadius()const
    {
        return radius;
    }
};

