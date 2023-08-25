#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"
#include "Player.h"
#include"../../common.h"
#include"../../Scene/GameMain/GameMainScene.h"

//#define KEYBORD
#define PAD

Player::Player()
{
	location.x = RESPAWN_POS_X;
	location.y = RESPAWN_POS_Y;
	radius = 10;

	speed = 3;
	is_show = true;
	character_state = PLAYER;

	attack_interval = 0;
	hit_timer = 0;
	frame_count = 0;
	score = 0;
	life = 3;

	acc_x = 0;
	acc_y = 0;

	weapon = new NwaySpawner();
}

Player::~Player()
{
	delete weapon;
}

void Player::Update(GameMainScene* gamemain_scene)
{
	if (is_show)
	{
#ifdef PAD

		//	ç∂
		if (PadInput::GetLStick().x < -QUARTER && PadInput::GetLStick().x >= -QUARTER * 4 - 1)
		{
			if (acc_x > -MAX_ACCELERATION)
			{
				acc_x -= 0.5f;
			}
		}
		else
		{
			if (0 > acc_x)
			{
				if (++frame_count % 1 == 0)
				{
					acc_x += 0.5f;
				}
			}
		}

		//âE
		if (PadInput::GetLStick().x > QUARTER && PadInput::GetLStick().x <= QUARTER * 4)
		{
			if (acc_x < MAX_ACCELERATION)
			{
				acc_x += 0.5f;
			}
		}
		else
		{
			if (0 < acc_x)
			{
				if (++frame_count % 1 == 0)
				{
					acc_x -= 0.5f;
				}
			}
		}

		//è„
		if (PadInput::GetLStick().y > QUARTER && PadInput::GetLStick().y <= QUARTER * 4)
		{
			if (acc_y > -MAX_ACCELERATION)
			{
				acc_y -= 0.5f;
			}
		}
		else
		{
			if (0 > acc_y)
			{
				if (++frame_count % 1 == 0)
				{
					acc_y += 0.5f;
				}
			}
		}

		//â∫
		if (PadInput::GetLStick().y < -QUARTER && PadInput::GetLStick().y >= -QUARTER * 4 - 1)
		{
			if (acc_y < MAX_ACCELERATION)
			{
				acc_y += 0.5f;
			}
		}
		else
		{
			if (0 < acc_y)
			{
				if (++frame_count % 1 == 0)
				{
					acc_y -= 0.5f;
				}
			}
		}


#endif // PAD

#ifdef KEYBORD

		//ç∂
		if (KeyInput::GetKeyDown(KEY_INPUT_A))
		{
			if (acc_x > -MAX_ACCELERATION)
			{
				acc_x -= 0.5f;
			}
		}
		else
		{
			if (0 > acc_x)
			{
				if (++frame_count % 1 == 0)
				{
					acc_x += 0.5f;
				}
			}
		}

		//âE
		if (KeyInput::GetKeyDown(KEY_INPUT_D))
		{
			if (acc_x < MAX_ACCELERATION)
			{
				acc_x += 0.5f;
			}
		}
		else
		{
			if (0 < acc_x)
			{
				if (++frame_count % 1 == 0)
				{
					acc_x -= 0.5f;
				}
			}
		}

		//è„
		if (KeyInput::GetKeyDown(KEY_INPUT_W))
		{
			if (acc_y > -MAX_ACCELERATION)
			{
				acc_y -= 0.5f;
			}
		}
		else
		{
			if (0 > acc_y)
			{
				if (++frame_count % 1 == 0)
				{
					acc_y += 0.5f;
				}
			}
		}

		//â∫
		if (KeyInput::GetKeyDown(KEY_INPUT_S))
		{
			if (acc_y < MAX_ACCELERATION)
			{
				acc_y += 0.5f;
			}
		}
		else
		{
			if (0 < acc_y)
			{
				if (++frame_count % 1 == 0)
				{
					acc_y -= 0.5f;
				}
			}
		}

#endif // KEYBORD

		location.x += speed * acc_x;
		location.y += speed * acc_y;

		//xé≤ÇÃà⁄ìÆêßå¿
		if (location.x < radius || location.x + radius > SCREEN_WIDTH)
		{
			if (location.x < radius)
			{
				location.x = radius;
			}
			else
			{
				location.x = SCREEN_WIDTH - radius;
			}
		}

		//yé≤ÇÃà⁄ìÆêßå¿
		if (location.y < radius || location.y + radius > SCREEN_HEIGHT)
		{
			if (location.y < radius)
			{
				location.y = radius;
			}
			else
			{
				location.y = SCREEN_HEIGHT - radius;
			}
		}

		gamemain_scene->HitCheck();
	}
}

void Player::Draw() const
{
	if (is_show)
	{
		SphereCollider::Draw();
	}
}

void Player::Hit(int damage)
{
	
}

void Player::Respawn()
{
	SetLocation({ RESPAWN_POS_X,RESPAWN_POS_Y });

	acc_x = 0;
	acc_y = 0;

	is_show = true;
}

void Player::Attack(GameMainScene* gamemain_scene, CharaBase* myself, const int& value)
{
#ifdef PAD

	if (PadInput::OnPressed(XINPUT_BUTTON_A) && ++attack_interval % 61== 0)
	{
		weapon->Shoot(gamemain_scene, myself, value);
	}


#endif // PAD

#ifdef KEYBORD

	if (KeyInput::GetButtonDown(MOUSE_INPUT_LEFT) && ++attack_interval % 71 == 0)
	{
		weapon->Shoot(gamemain_scene, myself, target, value);
		attack_interval = 0;
	}

#endif // KEYBORD

}
