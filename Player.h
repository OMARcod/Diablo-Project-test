#pragma once
#include "SharedFunctions.h"
class Player
{
public:
	bool IsAlive();
	void LoseLife(int anAttackValue);
	int GetAttackValue();
	int GetLive();



	Player();

private:

	int myLive;
	int myAttackValue;



};

