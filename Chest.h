#pragma once
#include "SharedFunctions.h"
#include "Items.h"
class Chest
{
public:

	Chest() = delete;
	~Chest();

	const static int myNoItem = -1;

	Chest(int itemID,bool isLocked); //need to be fixed 

	int EnterChest();
	bool isChestEmpty();
	
private:
	
	Items myItem;
	bool myLockIsClosed;
	int myItemID;
	bool myChestIsEmpty;

	//bool CheckIfPlayerIsStrongEnough();

};

//chest will have what item it have 
//chest will return the itemID
//chest will return if the player used the itme