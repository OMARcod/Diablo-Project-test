#pragma once
#include "SharedFunctions.h"
#include "Items.h"
class Chest
{
public:

	Chest() = delete;
	~Chest();

	const static int myNoItem = -1;

	Chest(const Items& aItem,bool isLocked);

	int EnterChest();
	bool isChestEmpty();
	
private:
	
	bool myLockIsClosed;
	bool myChestIsEmpty;
	int myItemID;
	Items myItem;


};

