#include "Door.h"

Door::Door(int aFirstExit, int aSecondExit, int aThirdExit, int aFourthExit, bool IsLockedSecond, bool IsLockedThird, bool IsLockedFourth) //4
	:myFirstExit(aFirstExit), mySecondExit(aSecondExit), myThirdExit(aThirdExit), myFourthExit(aFourthExit)
	, myLokedIsClosed(false),myPlayerStringth(0)
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

int Door::GetUserInputRoomNrToGoTo()
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

int Door::ReturnTheRoom(int aDoorNr,const int & aCurrentRoomIndex)
{
	int roomIndex = aCurrentRoomIndex;
	switch (aDoorNr)
	{
	case static_cast<int>(Doors::FirstExit):
		if (roomIndex > 0) //so the player don't go back
		{
			roomIndex = myFirstExit; //check so when you are in room 0 to not go back
		}
		break;
	case static_cast<int>(Doors::SecondExit):
		//how to check if im in the last room

		roomIndex = mySecondExit; //check so when you are in last index to not add further
		break;

	case static_cast<int>(Doors::ThirdExit):
		roomIndex = myThirdExit;
		break;
	case static_cast<int>(Doors::FourthExit):
		roomIndex = myFourthExit;
		break;
	}

	return roomIndex;
}

int Door::GetNextDestnationRoom(const int& aCurrentRoomIndex)
{
	int doorNr = GetUserInputRoomNrToGoTo();
	int roomIndex = aCurrentRoomIndex;

	if (CheckIfClosed(doorNr)) //if door is closed 
	{
		//open the door with agility
		//open the door with stringth

		std::cout << "The Door is Closed :(" << std::endl;
		std::cout << "0. break the door" << std::endl;
		std::cout << "1. return back" << std::endl;
		int input = SharedFunctions::ReadInputInt(0, 1);
		if (input == 0)
		{
			if (CheckIfPlayerIsStrongEnough())
			{
				OpenDoorNr(doorNr);
				roomIndex = ReturnTheRoom(doorNr, aCurrentRoomIndex);
				std::cout << "Door nr " << doorNr << " is now open" << std::endl;
			}
			else
			{
				std::cout << "You are not strong enough to open the door" << std::endl;
			}
		}
		system("pause");
	}
	else
	{
		roomIndex = ReturnTheRoom(doorNr, aCurrentRoomIndex);
	}
	//check if the door is closed 
	
	return roomIndex; 
}

void Door::OpenDoorNr(int aDoorNr)
{
	assert(myLockArray[aDoorNr - 1] == true);
	assert((aDoorNr - 1) >= 0);
	myLockArray[aDoorNr - 1] = false;
}

void Door::SetMyPlayerStringth(int aStringth)
{
	myPlayerStringth = aStringth;
}

bool Door::CheckIfPlayerIsStrongEnough() // fix this
{
	//fix so that when you add door stringth ..
	//if player stringth > door stringth 
	//increace player stringth when defeating enimes

	if (myPlayerStringth > 15) //can break the door 
	{
		return true;
	}
	return false;
}

bool Door::CheckIfClosed(int anExitNr)
{
	switch (anExitNr)
	{
	case static_cast<int>(Doors::FirstExit):
		return false;
		break;

	case static_cast<int>(Doors::SecondExit):
		if (myLockArray[0] == true)
			return true;
		else
			return false;
		break;
	case static_cast<int>(Doors::ThirdExit):
		if (myLockArray[1] == true)
			return true;
		else
			return false;
		break;
	case static_cast<int>(Doors::FourthExit):
		if (myLockArray[2] == true)
			return true;
		else
			return false;
		break;
	}

	//return the next room
	//if the door can't be open then return to the same room
	return true;
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



