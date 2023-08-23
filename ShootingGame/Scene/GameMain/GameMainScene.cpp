#include "GameMainScene.h"
#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"

//#define DEBUG

GameMainScene::GameMainScene()
{
	life = 3;
	attack_interval = 0;
	respawn_interval = 0;

	player = new Player();
	for (int i = 0; i < ENEMY; i++)
	{
		enemy[i] = new Enemy((float)i, (float)(i * 150));
	}
	SpawnBullet();
}

GameMainScene::~GameMainScene()
{
	delete player;

	for (int i = 0; i < ENEMY; i++)
	{
		delete enemy[i];
	}

	for (int i = 0; i < PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * ENEMY); i++)
	{
		delete bullets[i];
	}
}

SceneBase* GameMainScene::Update()
{
	++attack_interval;

	if (attack_interval > 90)
	{
		attack_interval = 0;
	}

	if (life > 0)
	{
		player->Update(this);

		if (player->GetIsShow() == false)
		{
			++respawn_interval;
		}
	}

	if (respawn_interval > 60)
	{
		player->Respawn();
		life--;
		respawn_interval = 0;
	}

	is_clear = true;

	for (int i = 0; i < ENEMY; i++)
	{
		if (player->GetIsShow())
		{
			for (int j = 0; j < PLAYER_MAX_BULLET; j++)
			{
				player->Attack(this, player, enemy[i], j);
			}
		}

		if (enemy[i]->GetIsShow())
		{
			for (int j = PLAYER_MAX_BULLET + (PLAYER_MAX_BULLET * i); j < PLAYER_MAX_BULLET + ENEMY_MAX_BULLET + (ENEMY_MAX_BULLET * i); j++)
			{
				if (attack_interval < 30)
				{
					enemy[i]->Attack(this, enemy[i], player, j);
				}
			}
			enemy[i]->Update(this);

			is_clear = false;
		}
	}

	for (int i = 0; i < PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * ENEMY); i++)
	{
		bullets[i]->Update();
	}

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

	DrawFormatString(0, 0, 0xffffff, "SCORE:%d", player->GetScore());

	if (life > 0)
	{
		player->Draw();
	}
	else
	{
		DrawString(600, 400, "GameOver", 0xffffff, TRUE);
	}

	if (is_clear)
	{
		DrawString(600, 400, "GameClear", 0xffffff, TRUE);
	}

	for (int i = 0; i < ENEMY; i++)
	{
		enemy[i]->Draw();
	}

	for (int i = 0; i < PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * ENEMY); i++)
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
	for (int i = 0; i < ENEMY; i++)
	{
		//ƒvƒŒƒCƒ„[‚ª“G‚É“–‚½‚Á‚½‚ç
		if (enemy[i]->GetIsShow())
		{
			if (player->CheckCollision(enemy[i]))
			{
				player->SetIsShow(false);
			}
		}
	}

	//’e‚ª“–‚½‚Á‚½‚ç
	for (int i = 0; i < PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * ENEMY); i++)
	{
		if (bullets[i]->GetIsShow())
		{
			//ƒvƒŒƒCƒ„[‚Ì’e‚Å‚ÍƒvƒŒƒCƒ„[‚É“–‚½‚ç‚È‚¢‚æ‚¤‚É‚·‚é
			if (i > PLAYER_MAX_BULLET)
			{
				//’e‚ªƒvƒŒƒCƒ„[‚É“–‚½‚Á‚½‚ç
				if (bullets[i]->CheckCollision(player))
				{
					player->SetIsShow(false);

				}
			}

			for (int j = 0; j < ENEMY; j++)
			{
				//“G‚Ì’e‚Å‚Í“G‚É“–‚½‚ç‚È‚¢‚æ‚¤‚É‚·‚é
				if (i < PLAYER_MAX_BULLET)
				{
					//’e‚ª“G‚É“–‚½‚Á‚½‚ç
					if (bullets[i]->CheckCollision(enemy[j]))
					{
						enemy[j]->Hit(*(bullets[i]->GetDamage()));
					}
				}
			}
		}
	}
}

void GameMainScene::SpawnBullet()
{
	for (int i = 0; i < PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * ENEMY); i++)
	{
		bullets[i] = new Bullet();
	}
}