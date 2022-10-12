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
	Items GetChestItem();
	bool isChestEmpty();
	void AddItem(const Items& aItem);
	
private:
	
	bool myLockIsClosed;
	bool myChestIsEmpty;
	Items myItem;


};

