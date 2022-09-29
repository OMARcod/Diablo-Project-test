#pragma once
#include "SharedFunctions.h"
class Player
{
public:
	Player();


	bool IsAlive();
	void LoseLife(int anAttackValue);
	int GetAttackValue();
	int GetHealth();
	void AddLive();
	int GetCurrentRoom();
	void GoToNextRoom();
	void SetCurrentRoom(int aCurrentRoom);

	void DisplayPlayreCharacteristics();


	void ResetDefence();

private:




	int myCurrentRoom;

	int myStrength; //new
	int myAgility; //new
	int myPhysics; //new
	int myDefense;//new


	int myAttackValue;
	int myHealth;
	int myCarryingCapacity; //new

	const int myOriginalDefense;
};

//
// Attack Value = Strength  * agility
// Health = Phisyks * 4 + Strength * 6 + agility * 3
// Carrying Capacity = Strength + Agility / 3 * Defense
//
//Every secondary  Applity should be depndend on two basic applity


//the attack from the enmie should be less with defence 