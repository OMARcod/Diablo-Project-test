#pragma once
#include "SharedFunctions.h"
#include "Items.h"
#include "ItemFactory.h"
class Player
{
public:
	Player();
	~Player();

	bool IsAlive();
	void TakeDamage(int anAttackValue);
	int GetAttackValue();
	int GetHealth();
	int GetDefence();
	int GetCurrentRoom();
	void SetCurrentRoom(int aCurrentRoom);

	void DisplayPlayreCharacteristics();
	void DisplayPlayreHpAndDefence();


	void AddItem(const Items& aItem);

	bool isCapacityNotFull();
	void DisplayInventory();

	void DisableTheSpill();
	
private:
	bool mySpillIsActive;


	int myCurrentRoom;
	int myStrength; 
	int myAgility; 
	int myPhysics; 
	int myDefense;

	int myAttackValue;
	int myHealth;
	int myCarryingCapacity;

	int myItemWaight;

	int myMaxSpillDuration;
	int myCurrentSpillDuration;

	std::vector<Items> myItemsVector;
	//Items myItem;
};
