#pragma once
#include <vector>
#include "Room.h"
#include "Player.h"
#include "Chest.h"
#include "ItemFactory.h"
#include "Items.h"

class Game
{
public:
	Game();
	~Game(){}

	void GameLoop();

private:
	const int myNoRoom;
	const int myArraySize;
	int myRoomNr;

	Player myPlayer;
	Room myRoom;
	Door myDoorRoom0;
	Door myDoorRoom1;
	Door myDoorRoom2;
	Door myDoorRoom3;
	Door myDoorRoom4;
	Door myDoorRoom5;

	Chest myNormalChest;
	Chest myMagicCheest;

	ItemFactory myItemFactory;
	Items myItem;

	std::vector<Room> myRooms;
};

