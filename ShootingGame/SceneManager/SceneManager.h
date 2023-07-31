#pragma once
#include "AbstractScene.h"

class SceenManager :
    public AbstractScene
{
private:
    //���݂̃V�[��
    AbstractScene* now_sceen;
public:
    //�R���X�g���N�^
    SceenManager(AbstractScene* scene) :now_sceen(scene) {};

    //�f�X�g���N�^
    ~SceenManager() { delete now_sceen; }

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    AbstractScene* Update()override;

    //�`��Ɋւ��邱�Ƃ�
    void Draw()const override;
};

