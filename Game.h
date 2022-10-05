#pragma once
#include <vector>
#include "Room.h"
#include "Player.h"
#include "Chest.h"
class Game
{
public:
	Game();
	~Game(){}

	void GameLoop();

private:
	const int noRoom;
	const int arraySize;
	int myRoom;

	Player player;
	Room room;
	Door doorRoom0;
	Door doorRoom1;
	Door doorRoom2;
	Door doorRoom3;
	Door doorRoom4;
	Door doorRoom5;

	Chest normalChest;
	Chest magicCheest;


	std::vector<Room> rooms;
};

/*
		 __________
		/\____;;___\
	   | /         /
	   `. ())oo() .
		|\(%()*^^()^\
	   %| |-%-------|
	  % \ | %  ))   |
	  %  \|%________|
*/


//todo 
//fix the witght 
//fix the magic thing 
//fix the chset is locked
