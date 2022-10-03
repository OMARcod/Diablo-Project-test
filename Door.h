#pragma once
#include "SharedFunctions.h"
class Door
{
public:
	Door() = delete; 
	~Door();
	const static int myNoRoom = -1;

	Door(int aFirstExit, int aSecondExit, int aThirdExit = myNoRoom, int aFourthExit = myNoRoom
		,bool IsLockedSecond = false, bool IsLockedThird = false
		,bool IsLockedFourth = false); 


	int EnterDoor(int aCurrentRoomIndex);
	void SetMyPlayerStringth(int aStringth);


private:
	

	bool myLokedIsClosed;
	std::vector<bool> myLockArray;

	int myFirstExit;
	int mySecondExit;
	int myThirdExit; 
	int myFourthExit; 
	int myPlayerStringth; 
	int myDoorStringth;



	bool CheckIfClosed(int aNextRoomNr);
	bool CheckIfPlayerIsStrongEnough();

	int ReturnTheRoom(int aDoorNr,const int &aCurrentRoomIndex);
	int GetNextDestnationRoom(const int& aCurrentRoomIndex);
	int GetUserInputRoomNrToGoTo();

	void OpenDoorNr(int aDoorNr);
	void DisplayMenu();



	enum class Doors
	{
		FirstExit,
		SecondExit,
		ThirdExit,
		FourthExit,
	};

};

