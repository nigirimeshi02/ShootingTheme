#pragma once
#include "../SceneBase.h"
#include"../../Character/Player/Player.h"
#include"../../Character/Enemy/Enemy.h"
#include"../../Bullet/Bullet.h"

#define ENEMY 1     //�G�̐�

class GameMainScene :
    public SceneBase
{
private:
    int player_life;

    Player* player;
    Enemy* enemy[ENEMY];
    Bullet* bullets[PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * ENEMY)]; /*�v���C���[�ƓG�ł킯���ق��������A�������͗����̕��z�������*/
public:
    //�R���X�g���N�^
    GameMainScene();

    //�f�X�g���N�^
    ~GameMainScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;

    //�����蔻��̃`�F�b�N
    void HitCheck();

    //�e�̔z��ɐV�����f�[�^���쐬����
    void SpawnBullet();

    //�e�̔z����擾����
    Bullet* GetBullet(const int& value) { return bullets[value]; }
};

