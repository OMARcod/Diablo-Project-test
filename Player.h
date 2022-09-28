#pragma once
#include "SharedFunctions.h"
class Player
{
public:
	bool IsAlive();
	void LoseLife(int anAttackValue);
	int GetAttackValue();
	int GetLive();
	void AddLive();
	int GetCurrentRoom();
	//need to be fixed
	void GoToNextRoom();
	void SetCurrentRoom(int aCurrentRoom);


	Player();

private:


	int myCurrentRoom;

	int myHealth;
	int myAttackValue;
	int myCarryingCapacity; //new

	int Strength; //new
	int Agility; //new
	int Defense;//new

};

//
// Attack Value = Strength  * agility
// Health = Phisyks * 4 + Strength * 6 + agility * 3
// Carrying Capacity = Strength + Agility / 3 * Defense
//
//Every secondary  Applity should be depndend on two basic applity


//the attack from the enmie should be less with defence 