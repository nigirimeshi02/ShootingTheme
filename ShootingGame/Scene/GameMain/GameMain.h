#pragma once
#include "../SceneBase.h"

class GameMain :
    public SceneBase
{
private:

public:
    //�R���X�g���N�^
    GameMain();

    //�f�X�g���N�^
    ~GameMain();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;

    //void HitCheck();

   // void SpawnBullet();
};

