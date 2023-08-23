#pragma once
#include "../SceneBase.h"
#include"../../Character/Player/Player.h"
#include"../../Character/Enemy/Enemy.h"
#include"../../Bullet/Bullet.h"

#define ENEMY 3     //�G�̐�

class GameMainScene :
    public SceneBase
{
private:
    int life;
    int attack_interval;
    int respawn_interval;

    bool is_clear;

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

    void AddScore(int& score) { player->SetScore(score); }

    //�e�̔z����擾����
    Bullet* GetBullet(const int& value) { return bullets[value]; }
};

