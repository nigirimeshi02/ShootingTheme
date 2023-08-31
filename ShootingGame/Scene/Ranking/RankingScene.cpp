#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"
#include "RankingScene.h"
#include"../Title/TitleScene.h"
#include"InputRankingScene.h"

//#define DEBUG

RankingScene::RankingScene(int score)
{
	ReadRanking(ranking);
	SortRanking(ranking);

	scene = nullptr;

	if (ranking[4].score < score)
	{
		ranking[4].score = score;
		scene = new InputRankingScene(ranking[4].name);
	}
}

RankingScene::~RankingScene()
{

}

SceneBase* RankingScene::Update()
{

	if (scene != nullptr)
	{
		scene = scene->Update();
		if (scene == nullptr)
		{
			delete scene;
			scene = nullptr;

			SortRanking(ranking);
			SaveRanking(ranking);
		}
		else
		{
			return this;
		}
	}
	else
	{
		if (PadInput::OnButton(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			return new TitleScene();
		}

	}

	return this;
}

void RankingScene::Draw() const
{
#ifdef DEBUG
	DrawString(0, 0, "Ranking", 0xffffff, TRUE);
#endif // DEBUG

	if (scene != nullptr)
	{
		scene->Draw();
	}
	else
	{
		SetFontSize(36);

		for (int i = 0; i < MAX_RANK; i++)
		{
			DrawFormatString(360, 180 + i * 50, 0xffffff, "%2d %-10s %10d", ranking[i].number, ranking[i].name, ranking[i].score);
		}

		DrawString(360, 580, "Aボタンを押してタイトルへ戻る", 0xffffff);

		SetFontSize(16);
	}
}

int RankingScene::ReadRanking(RankingData ranking[])
{
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL)
	{
		//エラー処理
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ分配列データ読み込む
	for (int i = 0; i < MAX_RANK; i++)
	{
		int dammy = fscanf(fp, "%2d %10s %10d", &ranking[i].number, ranking[i].name, &ranking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}

void RankingScene::SortRanking(RankingData ranking[])
{
	int i, j;
	RankingData work;

	//選択法ソート
	for (i = 0; i < MAX_RANK - 1; i++)
	{
		for (j = i + 1; j < MAX_RANK; j++)
		{
			if (ranking[i].score <= ranking[j].score)
			{
				work = ranking[i];
				ranking[i] = ranking[j];
				ranking[j] = work;
			}
		}
	}

	//順位付け
	for (i = 0; i < MAX_RANK; i++)
	{
		ranking[i].number = 1;
	}

	//得点が同じ場合は同じ順位とする
	//同順位があった場合の次の順位はデータ個数が加算された順位とする
	for (i = 0; i < MAX_RANK - 1; i++)
	{
		for (j = i + 1; j < MAX_RANK; j++)
		{
			if (ranking[i].score > ranking[j].score)
			{
				ranking[j].number++;
			}
		}
	}
}

int RankingScene::SaveRanking(RankingData ranking[])
{
	FILE* fp;
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL)
	{
		//エラー処理
		printf("Ranking Data Error\n");
		return -1;
	}

	//ランキングデータ分配列データを書き込む
	for (int i = 0; i < MAX_RANK; i++)
	{
		fprintf(fp, "%2d %10s %10d\n", ranking[i].number, ranking[i].name, ranking[i].score);
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}