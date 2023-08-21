#include "GameMainScene.h"
#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"

#define DEBUG

GameMainScene::GameMainScene()
{
	player_life = 3;

	player = new Player();
	enemy = new Enemy();
	SpawnBullet();
}

GameMainScene::~GameMainScene()
{
	delete player;
	delete enemy;
	for (int i = 0; i < (PLAYER_MAX_BULLET + ENEMY_MAX_BULLET); i++)
	{
		delete bullets[i];
	}
}

SceneBase* GameMainScene::Update()
{
	if (player_life > 0)
	{
		player->Update(this);
	}

	if (player->GetIsShow())
	{
		for (int i = 0; i < PLAYER_MAX_BULLET; i++)
		{
			player->Attack(this, player, i);
		}
	}
	if (enemy->GetIsShow())
	{
		for (int i = 20; i < ENEMY_MAX_BULLET; i++)
		{
			enemy->Attack(this, enemy, i);
		}
	}

	for (int i = 0; i < PLAYER_MAX_BULLET + ENEMY_MAX_BULLET; i++)
	{
		bullets[i]->Update();
	}

	enemy->Update(this);

	HitCheck();

	return this;
}

void GameMainScene::Draw() const
{
#ifdef DEBUG
	DrawFormatString(0, 20, 0xffffff, "%d %d", KeyInput::GetMouseLocationX(), KeyInput::GetMouseLocationY());
	DrawFormatString(0, 40, 0xffffff, "%d %d", PadInput::GetLStick().x,PadInput::GetRStick().x);
	DrawString(0, 0, "GameMain", 0xffffff, TRUE);
#endif // DEBUG
	if (player_life > 0)
	{
		player->Draw();
	}
	else
	{
		DrawString(600, 400, "GameOver", 0xffffff, TRUE);
	}
	enemy->Draw();
	for (int i = 0; i < PLAYER_MAX_BULLET + ENEMY_MAX_BULLET; i++)
	{
		if (bullets[i]->GetIsShow())
		{
			bullets[i]->Draw();	
			DrawFormatStringF(bullets[i]->GetLocation().x, bullets[i]->GetLocation().y, 0xff00ff, "%d", i);
		}
	}
}

void GameMainScene::HitCheck()
{
	//プレイヤーが敵に当たったら
	if (enemy->GetIsShow())
	{
		if (player->CheckCollision(enemy))
		{
			player->Respawn();
			if (player->GetIsShow())
			{
				player_life--;
			}
		}
	}

	//弾が当たったら
	for (Bullet* bullets : bullets)
	{
		if (bullets->GetIsShow())
		{
			//弾がプレイヤーに当たったら
			if (bullets->CheckCollision(player))
			{
				player->Respawn();
				if (player->GetIsShow())
				{
					player_life--;
				}
			}

			//弾が敵に当たったら
			if (bullets->CheckCollision(enemy))
			{
				enemy->Hit(*(bullets->GetDamage()));
			}
		}
	}
}

void GameMainScene::SpawnBullet()
{
	for (int i = 0; i < PLAYER_MAX_BULLET + ENEMY_MAX_BULLET; i++)
	{
		bullets[i] = new Bullet();
	}
}

Bullet* GameMainScene::GetBullet(int &value)
{
	for (;value < PLAYER_MAX_BULLET + ENEMY_MAX_BULLET; value++)
	{
		return bullets[value];
	}
}
