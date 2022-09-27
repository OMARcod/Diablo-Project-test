#pragma once
#include "SharedFunctions.h"
class Door
{
public:
	Door(int aFirstExit, int aSecondExit);
	~Door();

	int EnterDoor(int aCurrentRoomIndex);
	
private:

	int myFirstExit;
	int mySecondExit;

};

