#pragma once
#include "../SceneBase.h"

class RankingScene :
    public SceneBase
{
public:
    //�R���X�g���N�^
    RankingScene();

    //�f�X�g���N�^
    ~RankingScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;
};

