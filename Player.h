#pragma once
#include "SharedFunctions.h"
class Player
{
public:
	Player();
	~Player();

	bool IsAlive();
	void LoseLife(int anAttackValue);
	int GetAttackValue();
	int GetHealth();
	void AddLive();
	int GetCurrentRoom();
	void SetCurrentRoom(int aCurrentRoom);

	void DisplayPlayreCharacteristics();
	void DisplayPlayreHpAndDefence();

	void ResetDefence();

private:

	int myCurrentRoom;

	int myStrength; 
	int myAgility; 
	int myPhysics; 
	int myDefense;


	int myAttackValue;
	int myHealth;
	int myCarryingCapacity; 

	const int myOriginalDefense;
};
