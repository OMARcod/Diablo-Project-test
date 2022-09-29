#pragma once
#include "SharedFunctions.h"
class Enemy
{
public:
	bool IsAlive();
	void LoseLife(int anAttackValue);
	int GetAttackValue();
	int GetHealth();

	Enemy();

private:

	int myHealth;
	int myAttackValue;


};

//enemy should know if the 