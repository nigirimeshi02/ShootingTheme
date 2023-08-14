#include"SceneManager/SceneManager.h"
#include"common.h"
#include"Scene/GameMain/GameMain.h"
#include"InputControl/Key/KeyInput.h"
#include"InputControl/Pad/PadInput.h"

/************************************************
* �v���O�����̊J�n
*************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	double nextTime = GetNowCount();	//�V�X�e�����Ԃ̎擾

	SetMainWindowText("�V���[�e�B���O�Q�[��");	//�^�C�g��

	ChangeWindowMode(TRUE);		//�E�B���h�E���[�h�ŋN��

	SetAlwaysRunFlag(TRUE);		//��ɃA�N�e�B�u��Ԃɂ���

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);	//��ʃT�C�Y�̐ݒ�

	if (DxLib_Init() == -1)return -1;	//DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);		//�`���𗠂ɂ���

	SceenManager* sceenManager = new SceenManager(dynamic_cast<AbstractScene*>(new GameMain()));

	//�Q�[�����[�v
	while ((ProcessMessage() == 0) &&
		sceenManager->Update() != nullptr &&
		!(CheckHitKey(KEY_INPUT_ESCAPE)))
	{
		ClearDrawScreen();		//��ʂ̏�����

		KeyInput::Update();

		PadInput::Update();

		sceenManager->Draw();

		ScreenFlip();			//����ʂ̓��e��\��ʂɔ��f

		nextTime += 1.0 / 60.0 * 1000.0;		//�t���[�����[�g�̐ݒ�{�~���P�ʂɍ��킹��

		//���݂̎��Ԃ����݂̃V�X�e�����Ԃ���������
		//���݂̎��Ԃ����݂̃V�X�e�����Ԃ��������������҂�����
		if (nextTime > GetNowCount())
		{
			WaitTimer((int)nextTime - GetNowCount());
		}
		//���݂̃V�X�e�����Ԃ��擾
		else
		{
			nextTime = GetNowCount();
		}
	}

	DxLib_End();		//DX���C�u�����g�p�̏I������

	return 0;

}