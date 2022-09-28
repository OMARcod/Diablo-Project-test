#include "Door.h"

Door::Door(int aFirstExit, int aSecondExit, int aThirdExit, int aFourthExit, bool IsLockedSecond, bool IsLockedThird, bool IsLockedFourth) //4
	:myFirstExit(aFirstExit), mySecondExit(aSecondExit), myThirdExit(aThirdExit), myFourthExit(aFourthExit)
	,myLokedIsClosed(false)
{
	myLockArray.push_back(IsLockedSecond);
	myLockArray.push_back(IsLockedThird);
	myLockArray.push_back(IsLockedFourth);
}

Door::~Door()
{
}


int Door::EnterDoor(int aCurrentRoomIndex)
{

	//check condetion will be in the room class for if the room is 0 or max
	this->DisplayMenu();

	SharedFunctions::DorrAscii();


	//int mySecond;
	assert(aCurrentRoomIndex >= 0);


	aCurrentRoomIndex = GetNextDestnationRoom(aCurrentRoomIndex);



	//i have info of what room im in
	return aCurrentRoomIndex; //return the next door 
}


void Door::DisplayMenu()
{
	SharedFunctions::DrawLine();
	std::cout << "0. Go Back --> to room Nr: " << myFirstExit << std::endl;
	std::cout << "1. Next Room --> to room Nr: " << mySecondExit << std::endl;
	
	if (myThirdExit > -1)
	{
		std::cout << "2. Go To --> Room Nr: " << myThirdExit << std::endl;
	}
	if (myFourthExit > -1 && myThirdExit > -1)
	{
		std::cout << "3. Go To --> Room Nr: " << myFourthExit << std::endl;
	}
	SharedFunctions::DrawLine();


}

int Door::GetRoomNrToGoTo()
{
	int inputGoToRoomNr = 0;

	if (myThirdExit > -1) //if there is a 3ird door
	{
		if (myFourthExit > -1) //if there a 4orth door
		{
			inputGoToRoomNr = SharedFunctions::ReadInputInt(static_cast<int>(Doors::FirstExit), static_cast<int>(Doors::FourthExit)); // take 4 input
		}
		else
		{
			inputGoToRoomNr = SharedFunctions::ReadInputInt(static_cast<int>(Doors::FirstExit), static_cast<int>(Doors::ThirdExit)); // take 3 input
		}
	}
	else //take 2 input
	{
		inputGoToRoomNr = SharedFunctions::ReadInputInt(static_cast<int>(Doors::FirstExit), static_cast<int>(Doors::SecondExit));
	}
	assert(inputGoToRoomNr >= static_cast<int>(Doors::FirstExit)); //error if input < 0
	return inputGoToRoomNr;
}

int Door::GetNextDestnationRoom(int &aCurrentRoomIndex)
{
	int theNextRoom = GetRoomNrToGoTo();
	CheckIfClosed(theNextRoom); //Fix

	//check if the door is closed 
	switch (theNextRoom)
	{
	case static_cast<int>(Doors::FirstExit):
		if (aCurrentRoomIndex > 0) //so the player don't go back
		{
			aCurrentRoomIndex = myFirstExit; //check so when you are in room 0 to not go back
		}
		break;
	case static_cast<int>(Doors::SecondExit):
		//how to check if im in the last room
		//mySecond = mySecondExit;
		aCurrentRoomIndex = mySecondExit; //check so when you are in last index to not add further
		break;

	case static_cast<int>(Doors::ThirdExit):
		aCurrentRoomIndex = myThirdExit; 
		break;
	case static_cast<int>(Doors::FourthExit):
		aCurrentRoomIndex = myFourthExit; 
		break;

	}

	return aCurrentRoomIndex;
}

bool Door::CheckIfClosed(int aNextRoomNr)
{
	switch (aNextRoomNr)
	{
	case static_cast<int>(Doors::FirstExit):
		
		break;
	case static_cast<int>(Doors::SecondExit):
		if (myLockArray[static_cast<int>(Doors::SecondExit)] == true)
		{
			//The door is closed
		}
		else
		//go to the next room 

		break;
	case static_cast<int>(Doors::ThirdExit):
		break;
	case static_cast<int>(Doors::FourthExit):
		break;

	}

	//return the next room
	//if the door can't be open then return to the same room
	return false;
}

//bool Door::IsDoorClosed(int aCurrentRoom)
//{
////How to close one door and make it open if the player open it 
//
//
//	if (true)
//	{
//		std::cout << "The Door is locked! " << std::endl;
//		std::cout << "0. Break The Door!" << std::endl;
//		std::cout << "1. Damgage" << std::endl;
//	}
//	else
//	{
//		return false;
//	}
//
//
//}



