#pragma once
#include "../SceneBase.h"

class InputRankingScene :
    public SceneBase
{
public:
    //�R���X�g���N�^
    InputRankingScene();

    //�f�X�g���N�^
    ~InputRankingScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;
};

