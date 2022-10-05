#pragma once
#include "SharedFunctions.h"
#include "Items.h"
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

	void AddItem(int itmeID); //this function take the item
	//id and make the calculation
	bool isCapacityNotFull();
	void DisplayInventory();

private:

	int myCurrentRoom;
	
	int myStrength; 
	int myAgility; 
	int myPhysics; 
	int myDefense;


	int myAttackValue;
	int myHealth;
	int myCarryingCapacity; // myCarryingCapacity(myStrength + myAgility) //change it 

	const int myOriginalDefense;

	//new 
	std::vector<Items> myItemsVector;
	Items myItem;
};
