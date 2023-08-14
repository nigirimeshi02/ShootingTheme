#pragma once
#include"../Collider/SphereCollider.h"

class Bullet :public SphereCollider
{
private:
	int damage;

	float speed;			//速さ
	float angle;			//角度
	float acceleration;		//速度の変化量
	float angleVelocity;	//角度の変化量

	bool is_show;
public:
	//コンストラクタ
	Bullet();

	//デストラクタ
	~Bullet();

	//描画に関すること以外の更新を実装する
	void Update();

	//描画に関することの更新を実装する
	void Draw()const override;

	int* GetDamage()
	{
		return &damage;
	}

	bool GetIsShow()
	{
		return is_show;
	}

	void SetIsShow(const bool flg)
	{
		is_show = flg;
	}
};

