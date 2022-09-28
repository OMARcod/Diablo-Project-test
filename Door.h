#pragma once
#include "SharedFunctions.h"
class Door
{
public:
	Door(int aFirstExit, int aSecondExit);
	Door(int aFirstExit, int aSecondExit,int aThirdExit);
	Door(int aFirstExit, int aSecondExit, int aThirdExit, int aFourthExit); //New
	~Door();
	int EnterDoor(int aCurrentRoomIndex);
	
private:
	
	//std::vector<bool> isLockArray;

	int myFirstExit;
	int mySecondExit;

	int myThirdExit; //new	
	int myFourthExit; //new

	void DisplayMenu();
	int GetInput();
	int GetNextDestnationRoom(int& aCurrentRoomIndex);

	//bool IsDoorClosed(int aCurrentRoom);

	enum class Doors
	{
		FirstExit,
		SecondExit,
		ThirdExit,
		FourthExit,
	};

};

//Door should have the infor for which room they can leed to 
// you can have magic doors 
//i think i can do that by makeing another door constorctor that take 
//4 doors or 3 doors ....
//my therd exit ,,, my fourth exit 
//then in the enter door function if those values are == 0 
//only display 1 and 2

//thre should be opend and closed door 
//closed door .. could be opened if the player is strong enough 
//so there should be a check funciton to see if the player can open
//i think this function should be here beuse i allrady asking the player
//but this function should have infor about the player stringth and agility


//every door should be as object with closed door
//so when you open a door and go to the other room 
//you can go back and the door should be opened
//bool isDoorClosed = ture;
//when player open isClosedDoor = false;