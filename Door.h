#pragma once
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

