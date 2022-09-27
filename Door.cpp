#include "Door.h"

Door::Door(int aFirstExit, int aSecondExit)
	:myFirstExit(aFirstExit),mySecondExit(aSecondExit)
{
}

Door::~Door()
{
}



int Door::EnterDoor(int aCurrentRoomIndex)
{
	//ask door 
		// if first exet go back
		//if second exit go to next room

	//check condetion will be in the room class for if the room is 0 or max
	std::cout << "0. Go back" << std::endl;
	std::cout << "1. Next room" << std::endl;
	SharedFunctions::DorrAscii();
	int inputGoToRoomNr = SharedFunctions::ReadInputInt(0, 1);
	int mySecond;
			assert(aCurrentRoomIndex >= 0);
	switch (inputGoToRoomNr)
	{
	case 0:
		if (aCurrentRoomIndex > 0) //so the player don't go back
		{
			aCurrentRoomIndex = myFirstExit; //check so when you are in room 0 to not go back
		}
		break;
	case 1:
		//how to check if im in the last room
		mySecond= mySecondExit;
		aCurrentRoomIndex = mySecond; //check so when you are in last index to not add further
	default:
		break;
	}
	//i have info of what room im in
	return aCurrentRoomIndex; //return the next door 
}
