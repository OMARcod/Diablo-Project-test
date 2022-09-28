#pragma once
#include "SharedFunctions.h"
class Enemy
{
public:
	bool IsAlive();
	void LoseLife(int anAttackValue);
	int GetAttackValue();
	int GetLive();

	Enemy();

private:

	int myHealth;
	int myAttackValue;


};

