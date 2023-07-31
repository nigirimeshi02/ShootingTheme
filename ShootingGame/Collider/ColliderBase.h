#pragma once
#define _USE_MATH_DEFINES

#include<math.h>

struct Location
{
	float x;
	float y;
};

class ColliderBase
{
protected:
	Location location;
public:
	//コンストラクタ
	ColliderBase(Location location = { 0,0 })
	{
		this->location = location;
	}

	//デストラクタ
	~ColliderBase() {};

	virtual void Draw()const = 0;

	//SphereColliderとの当たり判定
	virtual bool HitSphere(const class SphereCollider* spherecollider)const = 0;

	//中心座標の取得
	Location GetLocation()const
	{
		return location;
	}

	//中心座標の設定
	virtual Location SetLocation(Location location)
	{
		this->location = location;
	}
};