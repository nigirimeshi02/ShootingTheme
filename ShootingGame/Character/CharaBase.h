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
    //コンストラクタ
    CharaBase()
    {
        image = NULL;

        speed = 3;

        is_show = false;

        character_state = EMPTY;
    }

    //デストラクタ
    ~CharaBase() {};

    //描画に関すること以外の更新を実装する
    virtual void Update(GameMainScene* gamemain_scene) = 0;

    //描画に関することの更新を実装する
    virtual void Draw()const = 0;

    virtual void Hit(int damage) = 0;

    virtual void Attack(GameMainScene* gamemain_scene, CharaBase* myself, const int& value) = 0;

    bool GetIsShow() { return is_show; }

    void SetIsShow(const bool flg) { is_show = flg; }

    Character GetCharacterState() { return character_state; }
};