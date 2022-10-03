#pragma once
#include "SharedFunctions.h"
class Enemy
{
public:
	Enemy();
	~Enemy();

	bool IsAlive();

	int GetAttackValue();
	int GetHealth();

	void LoseLife(int anAttackValue);

private:

	int myHealth;
	int myAttackValue;


};
