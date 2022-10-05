#pragma once
#include "Items.h"
#include "SharedFunctions.h"

class Chest
{
public:

	Chest() = delete;
	~Chest();

	const static int myNoItem = -1;

	Chest(SharedFunctions::MyItems itemID,bool isLocked); //need to be fixed 

	int OpenChest();

	void AddItem(Items *myItems); //take the item
	
private:
	Items myItem;
	

	void CheckItem(const SharedFunctions::MyItems itemID);
	bool isItemUsed();
	SharedFunctions::MyItems GetItemID();

	bool myLockIsClosed;
	//bool CheckIfPlayerIsStrongEnough();

};

//chest will have what item it have 
//chest will return the itemID
//chest will return if the player used the itme