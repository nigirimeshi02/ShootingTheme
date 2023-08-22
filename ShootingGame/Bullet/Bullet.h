#pragma once
#include"../Collider/SphereCollider.h"

class Bullet :public SphereCollider
{
private:
	int damage;

	float move_x;
	float move_y;

	float speed;			//速さ
	float angle;			//角度
	float acceleration;		//速度の変化量
	float angleVelocity;	//角度の変化量

	bool is_show;			//表示させる？
public:
	//コンストラクタ
	Bullet();

	//デストラクタ
	~Bullet();

	//描画に関すること以外の更新を実装する
	void Update();

	//描画に関することの更新を実装する
	void Draw()const override;

	//角度変更処理
	void ChangeAngle();

	//damageを取得する
	int* GetDamage() { return &damage; }
	
	//速さを設定する
	void SetSpeed(float &speed) { this->speed = speed; }
	
	//角度を設定する
	void SetAngle(const float angle) { this->angle = angle; }

	//速度の変化量を設定する
	void SetAcceleration(const float& acceleration) { this->acceleration = acceleration; }
	
	//角度の変化量を設定する
	void SetAngleVelecity(const float& anglevelocity) { this->angleVelocity = anglevelocity; }

	//is_showを取得する
	bool GetIsShow() { return is_show; }

	//is_showを設定する
	void SetIsShow(const bool flg) { is_show = flg; }
};

