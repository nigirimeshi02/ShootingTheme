#pragma once
#include "../SceneBase.h"
#include"../../Character/Player/Player.h"
#include"../../Character/Enemy/Enemy.h"
#include"../../Bullet/Bullet.h"

class GameMain :
    public SceneBase
{
private:
    int player_life;

    Player* player;
    Enemy* enemy;
    Bullet* bullets[MAX_BULLET];
public:
    //�R���X�g���N�^
    GameMain();

    //�f�X�g���N�^
    ~GameMain();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;

    //�����蔻��̃`�F�b�N
    void HitCheck();

    //�e�̔z��ɐV�����f�[�^���쐬����
    void SpawnBullet();
};

