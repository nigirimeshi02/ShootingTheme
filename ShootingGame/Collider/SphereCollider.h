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
    float radius;       //���a
public:
    //�R���X�g���N�^
    SphereCollider();

    virtual void Draw()const;

    //SphereCollider�Ƃ̓����蔻��
    bool CheckCollision(const SphereCollider* sphere_collider)const;

    //���S���W�̎擾
    Location GetLocation()const
    {
        return location;
    }

    //���S���W�̐ݒ�
    virtual void SetLocation(Location location)
    {
        this->location = location;
    }

    //���a�̎擾
    float GetRadius()const
    {
        return radius;
    }
};

