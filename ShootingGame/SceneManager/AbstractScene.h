#pragma once
#include"DxLib.h"

class AbstractScene
{
public:
	//デストラクタ
	virtual ~AbstractScene() {};

	//描画に関すること以外の更新を実装する
	virtual AbstractScene* Update() = 0;

	//描画に関することを実装する
	virtual void Draw()const = 0;
};