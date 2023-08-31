#include"../../InputControl/Key/KeyInput.h"
#include"../../InputControl/Pad/PadInput.h"
#include "InputRankingScene.h"
#include"../Ranking/RankingScene.h"
#include"../Title/TitleScene.h"

//#define DEBUG

const char InputRankingScene::char_set[MAX_CHARACTER] =
{
	'a','b','c','d','e','f','g','h','i',
	'j','k','l','m','n','o','p','q','r',
	's','t','u','v','w','x','y','z'
};

InputRankingScene::InputRankingScene(char name[])
{
	player_name = name;

	interval = 0;
	cursor = 0;
}

InputRankingScene::~InputRankingScene()
{

}

SceneBase* InputRankingScene::Update()
{

	if (interval < INTERVAL)
	{
		interval++;
	}

	if (PadInput::OnButton(XINPUT_BUTTON_A))
	{
		if (name.size() >= MAX_NAME - 1)
		{
			name.erase(name.end() - 1);
		}

		name = name + char_set[cursor];
	}

	if (PadInput::OnButton(XINPUT_BUTTON_B))
	{
		name.erase(name.end() - 1);
	}

	if (OnUp() && interval >= INTERVAL)
	{
		cursor -= COL;
		if (cursor < 0)
		{
			cursor = (COL * ROW) + cursor;
			if (MAX_CHARACTER - 1 < cursor)
			{
				cursor -= COL;
			}
		}

		interval = 0;
	}
	else if (OnDown() && interval >= INTERVAL)
	{
		cursor += COL;
		if (MAX_CHARACTER - 1 < cursor)
		{
			cursor = cursor % COL;
		}

		interval = 0;
	}
	else if (OnLeft() && interval >= INTERVAL)
	{
		if (cursor % COL == 0)
		{
			cursor += COL;
			if (MAX_CHARACTER - 1 < cursor)
			{
				cursor--;
			}
		}

		cursor--;
		interval = 0;
	}
	else if (OnRight() && interval >= INTERVAL)
	{
		cursor++;
		if (cursor % COL == 0)
		{
			cursor -= COL;
		}
		if (MAX_CHARACTER - 1 < cursor)
		{
			cursor = COL * (ROW - 1);
		}

		interval = 0;
	}

	if (PadInput::OnButton(XINPUT_BUTTON_START) &&
		name.size() > 0)
	{
		sprintf_s(player_name, 10, name.c_str());
		return nullptr;
	}

	return this;
}

void InputRankingScene::Draw() const
{
#ifdef DEBUG
	DrawString(0, 0, "InputRanking", 0xffffff, TRUE);
#endif // DEBUG

	SetFontSize(36);

	for (int i = 0; i < MAX_CHARACTER; i++)
	{
		DrawFormatString((140 + 100) + 50 + (80 * (i % COL)), 310 + 30 + (85 * (i / COL)), 0xffffff, "%c", char_set[i]);
	}

	DrawFormatString((140 + 100) + 50, (10 + 100) + 30, 0xffffff, "%s", name.c_str());

	DrawString(250, 630, "A:“ü—Í B:ˆê‚Â–ß‚é START:Œˆ’è", 0xffffff);

	SetFontSize(16);

	DrawCircle(250 + (80 * (cursor % COL)), 360 + (85 * (cursor / COL)), 5, 0xffffff);
}

bool InputRankingScene::OnUp()
{
	if (PadInput::GetLStick().y > QUARTER ||
		PadInput::OnPressed(XINPUT_BUTTON_DPAD_UP))
	{
		return true;
	}

	return false;
}

bool InputRankingScene::OnDown()
{
	if (PadInput::GetLStick().y < -QUARTER ||
		PadInput::OnPressed(XINPUT_BUTTON_DPAD_DOWN))
	{
		return true;
	}

	return false;
}

bool InputRankingScene::OnLeft()
{
	if (PadInput::GetLStick().x < -QUARTER ||
		PadInput::OnPressed(XINPUT_BUTTON_DPAD_LEFT))
	{
		return true;
	}

	return false;
}

bool InputRankingScene::OnRight()
{
	if (PadInput::GetLStick().x > QUARTER ||
		PadInput::OnPressed(XINPUT_BUTTON_DPAD_RIGHT))
	{
		return true;
	}

	return false;
}
