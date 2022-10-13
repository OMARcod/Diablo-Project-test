#pragma once
#include "SharedFunctions.h"
#include "Items.h"
class Chest
{
public:

	Chest() = delete;
	~Chest();

	const static int myNoItem = -1;

	Chest(bool isLocked);

	bool EnterChest();
	std::shared_ptr<Items> GetChestItem();
	bool isChestEmpty();
	//void AddItem(const Items& aItem);
	void AddItem(std::shared_ptr<Items> aItem);
	
private:
	
	bool myLockIsClosed;
	bool myChestIsEmpty;
	std::shared_ptr<Items> myItem;


};

