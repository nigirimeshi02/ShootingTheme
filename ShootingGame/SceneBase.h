#pragma once
#include"SceneManager/SceneManager.h"

class SceneBase :
	public AbstractScene
{
public:
	//コンストラクタ
	SceneBase() {};

	//デストラクタ
	~SceneBase() {};

	//描画以外の更新を実装する
	virtual AbstractScene* Update() = 0;

	//描画に関することを実装する
	virtual void Draw()const = 0;
};