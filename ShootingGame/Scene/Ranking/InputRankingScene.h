#pragma once
#include "../SceneBase.h"
#include<string>    

#define MAX_CHARACTER 26        //�A���t�@�x�b�g�̕�����
#define ROW 3                   //��
#define COL 9                   //�s
#define INTERVAL 15

using namespace std;

class InputRankingScene :
    public SceneBase
{
private:
    static const char char_set[MAX_CHARACTER];

    char* player_name;

    int interval;
    int cursor;

    string name;
public:
    //�R���X�g���N�^
    InputRankingScene(char name[]);

    //�f�X�g���N�^
    ~InputRankingScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;

    bool OnUp();

    bool OnDown();

    bool OnLeft();

    bool OnRight();
};

