#pragma once
#include "SharedFunctions.h"
class Player
{
public:
	bool IsAlive();
	void LoseLife(int anAttackValue);
	int GetAttackValue();
	int GetLive();
	void AddLive(int nrToAdd);
	int GetCurrentRoom();
	//need to be fixed
	void GoToNextRoom();
	void SetCurrentRoom(int aCurrentRoom);


	Player();

private:

	int myLive;
	int myAttackValue;
	int myCurrentRoom;


};

