#pragma once
#include "../Collider/SphereCollider.h"

class GameMainScene;

enum Character
{
    EMPTY = 0,
    PLAYER,
    ENEMY
};

class CharaBase :
    public SphereCollider
{
private:

protected:
    int image;

    float speed;

    bool is_show;

    Character character_state;
public:
    //�R���X�g���N�^
    CharaBase()
    {
        image = NULL;

        speed = 3;

        is_show = false;

        character_state = EMPTY;
    }

    //�f�X�g���N�^
    ~CharaBase() {};

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    virtual void Update(GameMainScene* gamemain_scene) = 0;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    virtual void Draw()const = 0;

    virtual void Hit(int damage) = 0;

    virtual void Attack(GameMainScene* gamemain_scene, CharaBase* myself, const int& value) = 0;

    bool GetIsShow() { return is_show; }

    void SetIsShow(const bool flg) { is_show = flg; }

    Character GetCharacterState() { return character_state; }
};