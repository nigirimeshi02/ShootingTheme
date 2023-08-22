#pragma once
#include "../Collider/SphereCollider.h"

class GameMainScene;

class CharaBase :
    public SphereCollider
{
private:

protected:
    int image;

    float speed;

    bool is_show;
    bool is_attack;
public:
    //�R���X�g���N�^
    CharaBase()
    {
        image = NULL;

        speed = 3;

        is_show = false;
        is_attack = false;
    }

    //�f�X�g���N�^
    ~CharaBase() {};

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    virtual void Update(GameMainScene* gamemain_scene) = 0;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    virtual void Draw()const = 0;

    virtual void Hit(int damage) = 0;

    virtual void Attack(GameMainScene* gamemain_scene, const CharaBase* myself, const CharaBase* target, const int& value) = 0;

    bool GetIsShow() { return is_show; }

    void SetIsShow(const bool flg) { is_show = flg; }

    bool GetIsAttack() { return is_attack; }

    void SetIsAttack(const bool flg) { is_attack = flg; }
};

