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


	//void AddItem(const Items& aItem);
	void AddItem(std::shared_ptr<Items> aItem);

	bool isCapacityNotFull();
	void DisplayInventory();

	void DisableTheSpill();
	
private:
	bool myHaveSpill;
	int mySpillIndex;

	int myCurrentRoom;
	int myStrength; 
	int myAgility; 
	int myPhysics; 
	int myDefense;

	int myAttackValue;
	int myHealth;
	int myCarryingCapacity;

	int myItemWaight;

	void IncreasePlayerStat(int itemIndex);
	void DecreasePlayerStat(int itemIndex);

	std::vector<std::shared_ptr<Items>> myItemsVector;
	//Items myItem;
};
