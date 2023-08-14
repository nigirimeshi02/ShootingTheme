#pragma once
#include "BulletsSpawner.h"

class NwaySpawner :
    public BulletsSpawner
{
private:
    int numBullets;     //”­Ë‚·‚é’e‚Ì”
    float baseAngle;    //”­Ë‚·‚éÅ‰‚Ì’e‚ÌŒü‚«
    float angleDiff;    // ’e“¯m‚ÌŠp“x·
public:
    void Shoot(Bullet* bullt, CharaBase* character, const int value)override {};
};