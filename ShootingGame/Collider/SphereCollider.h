#pragma once
#include"ColliderBase.h"

class SphereCollider :
    public ColliderBase
{
protected:
    float radius;       //半径
public:
    //コンストラクタ
    SphereCollider(Location location, float radius = 5.f)
    {
        this->radius = radius;
    }

    void Draw()const override;

    //SphereColliderとの当たり判定
    bool HitSphere(const SphereCollider* sphere_collider)const override;

    //半径の取得
    float GetRadius()const
    {
        return radius;
    }
};

