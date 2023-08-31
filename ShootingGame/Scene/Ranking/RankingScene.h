#pragma once
#include "../SceneBase.h"
#include<string>

#define MAX_RANK 5
#define MAX_NAME 10

typedef struct
{
    int number;
    char name[MAX_NAME];
    long score;
}RankingData;

class RankingScene :
    public SceneBase
{
private:
    SceneBase* scene;               //�V�[���J�ڗp
    RankingData ranking[MAX_RANK];
public:
    //�R���X�g���N�^
    RankingScene(int score = 0);

    //�f�X�g���N�^
    ~RankingScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;

    int ReadRanking(RankingData ranking[]);

    void SortRanking(RankingData ranking[]);

    int SaveRanking(RankingData ranking[]);
};