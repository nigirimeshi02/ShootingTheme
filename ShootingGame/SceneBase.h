#pragma once
#include"SceneManager/SceneManager.h"

class SceneBase :
	public AbstractScene
{
public:
	//�R���X�g���N�^
	SceneBase() {};

	//�f�X�g���N�^
	~SceneBase() {};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update() = 0;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw()const = 0;
};