#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"
#include "GameMainScene.h"
#include"../Title/TitleScene.h"

//#define DEBUG

GameMainScene::GameMainScene()
{
	life = 3;

	attack_interval = 0;
	respawn_interval = 0;
	wait_timer = 180;

	stage_count = 1;

	is_clear = true;
	game_clear_flg = false;
	game_over_flg = false;

	player = new Player();

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i] = new Enemy(0, 0);
	}

	SpawnBullet();

	CreateStage(stage_count);
}

GameMainScene::~GameMainScene()
{
	delete player;

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		delete enemy[i];
	}

	for (int i = 0; i < PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * MAX_ENEMY); i++)
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
		if (player->GetIsShow())
		{
			for (int j = 0; j < PLAYER_MAX_BULLET; j++)
			{
				player->Attack(this, player, j);
			}
		}
		else
		{
			++respawn_interval;
		}
	}
	else
	{
		game_over_flg = true;
		if (--wait_timer < 0)
		{
			return new TitleScene();
		}
	}

	if (respawn_interval > 60)
	{
		player->Respawn();
		life--;
		respawn_interval = 0;
	}

	//�N���A�t���O��true�ɂ��Ă���
	is_clear = true;

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (enemy[i]->GetIsShow())
		{
			enemy[i]->Update(this);

			for (int j = PLAYER_MAX_BULLET + (PLAYER_MAX_BULLET * i); j < PLAYER_MAX_BULLET + ENEMY_MAX_BULLET + (ENEMY_MAX_BULLET * i); j++)
			{
				if (attack_interval < 30)
				{
					enemy[i]->Attack(this, enemy[i], j);
				}
			}

			//�G����l�ł������Ă���Ȃ�false�ɂ���
			is_clear = false;
		}
	}

	for (int i = 0; i < PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * MAX_ENEMY); i++)
	{
		bullets[i]->Update();
	}

	if (player->GetIsShow())
	{
		if (is_clear)
		{
			if (stage_count < MAX_STAGE)
			{
				if (--wait_timer < 0)
				{
					NextStage();
				}
			}
			else
			{
				game_clear_flg = true;
				if (--wait_timer < 0)
				{
					return new TitleScene();
				}
			}
		}
	}

	return this;
}

void GameMainScene::Draw() const
{
#ifdef DEBUG
	DrawFormatString(0, 20, 0xffffff, "%d %d", KeyInput::GetMouseLocationX(), KeyInput::GetMouseLocationY());
	DrawFormatString(0, 40, 0xffffff, "%d %d", PadInput::GetLStick().x,PadInput::GetRStick().x);
	DrawString(0, 0, "GameMain", 0xffffff, TRUE);
#endif // DEBUG

	DrawFormatString(400, 0, 0xffffff, "STAGE:%d", stage_count);
	DrawFormatString(600, 0, 0xffffff, "SCORE:%d", player->GetScore());

	if (life > 0)
	{
		player->Draw();
	}
	else
	{
		DrawString(600, 400, "GameOver", 0xffffff, TRUE);
	}

	if (game_clear_flg)
	{
		DrawString(600, 400, "GameClear", 0xffffff, TRUE);
	}

	for (int i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i]->Draw();
	}

	for (int i = 0; i < PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * MAX_ENEMY); i++)
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
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (enemy[i]->GetIsShow())
		{
			//�v���C���[���G�ɓ���������
			if (player->CheckCollision(enemy[i]))
			{
				player->SetIsShow(false);
			}
		}
	}

	//�e������������
	for (int i = 0; i < PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * MAX_ENEMY); i++)
	{
		if (bullets[i]->GetIsShow())
		{
			//�v���C���[�̒e�ł̓v���C���[�ɓ�����Ȃ��悤�ɂ���
			if (i > PLAYER_MAX_BULLET)
			{
				//�e���v���C���[�ɓ���������
				if (bullets[i]->CheckCollision(player))
				{
					player->SetIsShow(false);

				}
			}

			for (int j = 0; j < MAX_ENEMY; j++)
			{
				//�G�̒e�ł͓G�ɓ�����Ȃ��悤�ɂ���
				if (i < PLAYER_MAX_BULLET)
				{
					//�e���G�ɓ���������
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
	for (int i = 0; i < PLAYER_MAX_BULLET + (ENEMY_MAX_BULLET * MAX_ENEMY); i++)
	{
		bullets[i] = new Bullet();
	}
}

void GameMainScene::NextStage()
{
	++stage_count;
	wait_timer = 180;
	CreateStage(stage_count);
}

void GameMainScene::CreateStage(const int stage)
{
	player->SetLocation({ RESPAWN_POS_X,RESPAWN_POS_Y });
	switch (stage)
	{
	case 1:
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			enemy[i]->SetLocation({ 800.f,400.f });
			enemy[i]->Init(50);

			if (i == 0)
			{
				if (enemy[i]->GetIsShow() == false)
				{
					enemy[i]->GetWeapon()->SetNumBullets(1);
					enemy[i]->SetIsShow(true);
				}
			}
			else
			{
				enemy[i]->SetIsShow(false);
			}
		}

		break;
	case 2:
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			enemy[i]->SetLocation({ (float)i + 800.f, (float)(i * 150) + 250.f });
			enemy[i]->Init(50);

			if (i <= 1)
			{
				if (enemy[i]->GetIsShow() == false)
				{
					enemy[i]->GetWeapon()->SetNumBullets(2);
					enemy[i]->SetIsShow(true);
				}
			}
			else
			{
				enemy[i]->SetIsShow(false);
			}
		}

		break;
	case 3:
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			enemy[i]->SetLocation({ (float)i + 800.f, (float)(i * 150) + 250.f });
			enemy[i]->Init(50);

			if (enemy[i]->GetIsShow() == false)
			{
				enemy[i]->SetIsShow(true);
				if (i == 1)
				{
					enemy[i]->GetWeapon()->SetNumBullets(3);
				}
			}
		}

		break;
	case 4:
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			enemy[i]->SetLocation({ (float)i + 800.f, (float)(i * 150) + 250.f });
			enemy[i]->Init(50);

			if (enemy[i]->GetIsShow() == false)
			{
				enemy[i]->SetIsShow(true);
				enemy[i]->GetWeapon()->SetNumBullets(3);
			}
		}

		break;
	case 5:
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			enemy[i]->SetLocation({ 800.f,400.f });
			enemy[i]->Init(300);

			if (enemy[i]->GetIsShow() == false)
			{
				if (i == 0)
				{
					if (enemy[i]->GetIsShow() == false)
					{
						enemy[i]->GetWeapon()->SetNumBullets(1);
						enemy[i]->SetIsShow(true);
					}
				}
				else
				{
					enemy[i]->SetIsShow(false);
				}
			}
		}

		break;
	}
}