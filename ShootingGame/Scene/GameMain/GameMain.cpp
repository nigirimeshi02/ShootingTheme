#include "GameMain.h"
#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"

#define DEBUG

GameMain::GameMain()
{
	player_life = 3;

	player = new Player();
	enemy = new Enemy();
	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullets[i] = new Bullet();
	}
}

GameMain::~GameMain()
{
	delete player;
	delete enemy;
	for (int i = 0; i < MAX_BULLET; i++)
	{
		delete bullets[i];
	}
}

SceneBase* GameMain::Update()
{
	if (player_life > 0)
	{
		player->Update();
	}

	if (player->GetIsShow())
	{
		for (int i = 0; i < 4; i++)
		{
			player->Attack(bullets[i], player, i);
		}
	}

	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullets[i]->Update();
	}

	enemy->Update();

	HitCheck();
	return this;
}

void GameMain::Draw() const
{
#ifdef DEBUG
	DrawFormatString(0, 20, 0xffffff, "%d %d", KeyInput::GetMouseLocationX(), KeyInput::GetMouseLocationY());
	DrawFormatString(0, 40, 0xffffff, "%d %d", PadInput::GetLStick().x,PadInput::GetRStick().x);
	DrawString(0, 0, "GameMain", 0xffffff, TRUE);
#endif // DEBUG
	if (player_life > 0)
	{
		if (player->GetIsShow())
		{
			player->Draw();
		}
	}
	else
	{
		DrawString(600, 400, "GameOver", 0xffffff, TRUE);
	}
	enemy->Draw();
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullets[i]->GetIsShow())
		{
			bullets[i]->Draw();	
			DrawFormatStringF(bullets[i]->GetLocation().x, bullets[i]->GetLocation().y, 0xff00ff, "%d", i);
		}
	}
}

void GameMain::HitCheck()
{
	//ƒvƒŒƒCƒ„[‚ª“G‚É“–‚½‚Á‚½‚ç
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

	////’e‚ªƒvƒŒƒCƒ„[‚É“–‚½‚Á‚½‚ç
	//if (bullet->CheckCollision(player))
	//{
	//	player->Respawn();
	//	if (player->GetIsShow())
	//	{
	//		player_life--;
	//	}
	//}

	//’e‚ª“G‚É“–‚½‚Á‚½‚ç
	for (Bullet* bullets : bullets)
	{
		if (bullets->CheckCollision(enemy))
		{
			enemy->Hit(*(bullets->GetDamage()));
		}
	}
}

void GameMain::SpawnBullet()
{

}
