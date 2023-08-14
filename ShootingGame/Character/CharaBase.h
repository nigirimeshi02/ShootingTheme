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
    //�R���X�g���N�^
    CharaBase();

    //�f�X�g���N�^
    ~CharaBase() {};

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    virtual void Update() {};

    //�`��Ɋւ��邱�Ƃ̍X�V����������
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

