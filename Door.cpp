#include "Door.h"

Door::Door(int aFirstExit, int aSecondExit, int aThirdExit, int aFourthExit, bool IsLockedSecond, bool IsLockedThird, bool IsLockedFourth)
	:myFirstExit(aFirstExit), mySecondExit(aSecondExit), myThirdExit(aThirdExit), myFourthExit(aFourthExit)
	, myLokedIsClosed(false),myPlayerStringth(0),myDoorStringth(15)
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

	this->DisplayMenu();

	SharedFunctions::DorrAscii();


	assert(aCurrentRoomIndex >= 0);


	aCurrentRoomIndex = GetNextDestnationRoom(aCurrentRoomIndex);



	return aCurrentRoomIndex; 
}

void Door::SetMyPlayerStringth(int aStringth)
{
	myPlayerStringth = aStringth;
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


	return true;
}

bool Door::CheckIfPlayerIsStrongEnough() 
{
	if (myPlayerStringth > myDoorStringth)
	{
		return true;
	}
	return false;
}

int Door::ReturnTheRoom(int aDoorNr,const int & aCurrentRoomIndex)
{
	int roomIndex = aCurrentRoomIndex;
	switch (aDoorNr)
	{
	case static_cast<int>(Doors::FirstExit):
		if (roomIndex > 0)
		{
			roomIndex = myFirstExit;
		}
		break;
	case static_cast<int>(Doors::SecondExit):
		
		roomIndex = mySecondExit;
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

int Door::GetUserInputRoomNrToGoTo()
{
	int inputGoToRoomNr = 0;

	if (myThirdExit > -1) 
	{
		if (myFourthExit > -1) 
		{
			inputGoToRoomNr = SharedFunctions::ReadInputInt(static_cast<int>(Doors::FirstExit), static_cast<int>(Doors::FourthExit)); 
		}
		else
		{
			inputGoToRoomNr = SharedFunctions::ReadInputInt(static_cast<int>(Doors::FirstExit), static_cast<int>(Doors::ThirdExit)); 
		}
	}
	else 
	{
		inputGoToRoomNr = SharedFunctions::ReadInputInt(static_cast<int>(Doors::FirstExit), static_cast<int>(Doors::SecondExit));
	}
	assert(inputGoToRoomNr >= static_cast<int>(Doors::FirstExit)); 
	return inputGoToRoomNr;
}

int Door::GetNextDestnationRoom(const int& aCurrentRoomIndex)
{
	int doorNr = GetUserInputRoomNrToGoTo();
	int roomIndex = aCurrentRoomIndex;

	if (CheckIfClosed(doorNr))
	{
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
				std::cout << "Door nr " << roomIndex << " is now open" << std::endl;
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
	return roomIndex; 
}

void Door::OpenDoorNr(int aDoorNr)
{
	assert(myLockArray[aDoorNr - 1] == true);
	assert((aDoorNr - 1) >= 0);
	myLockArray[aDoorNr - 1] = false;
}

void Door::DisplayMenu()
{
	SharedFunctions::DrawLine();
	std::cout << "0. Go Back --> to room Nr: " << myFirstExit << std::endl;
	std::cout << "1. Next Room --> to room Nr: " << mySecondExit << std::endl;


	if (myThirdExit > -1)
	{
		SharedFunctions::DrawLine();	
		std::cout << "2. Go To --> Room Nr: " << myThirdExit << std::endl;
	}
	if (myFourthExit > -1 && myThirdExit > -1)
	{
		std::cout << "3. Go To --> Room Nr: " << myFourthExit << std::endl;
	}
	SharedFunctions::DrawLine();


}






