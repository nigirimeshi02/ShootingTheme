#pragma once
#include "../SceneBase.h"

class TitleScene :
    public SceneBase
{
private:
    int interval;
    int cursor_num;
    int cursor_y;
public:
    //�R���X�g���N�^
    TitleScene();

    //�f�X�g���N�^
    ~TitleScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;
};

