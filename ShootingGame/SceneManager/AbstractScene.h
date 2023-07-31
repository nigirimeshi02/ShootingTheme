#pragma once
#include"DxLib.h"

class AbstractScene
{
public:
	//�f�X�g���N�^
	virtual ~AbstractScene() {};

	//�`��Ɋւ��邱�ƈȊO�̍X�V����������
	virtual AbstractScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const = 0;
};