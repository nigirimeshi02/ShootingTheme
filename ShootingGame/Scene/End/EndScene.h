#pragma once
#include "../SceneBase.h"

class EndScene :
    public SceneBase
{
public:
    //�R���X�g���N�^
    EndScene();

    //�f�X�g���N�^
    ~EndScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;
};

