#pragma once
#include"ColliderBase.h"

class SphereCollider :
    public ColliderBase
{
protected:
    float radius;       //���a
public:
    //�R���X�g���N�^
    SphereCollider(Location location, float radius = 5.f)
    {
        this->radius = radius;
    }

    void Draw()const override;

    //SphereCollider�Ƃ̓����蔻��
    bool HitSphere(const SphereCollider* sphere_collider)const override;

    //���a�̎擾
    float GetRadius()const
    {
        return radius;
    }
};

