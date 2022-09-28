#include <iostream>
#include <vector>
#include "Room.h"
#include "Player.h"

Player player;
Room room(player);
Door doorRoom0(0, 1);
Door doorRoom1(0, 2);
Door doorRoom2(1, 3);
Door doorRoom3(2, 4, 5);
Door doorRoom4(3, 5, 0, 1);
Door doorRoom5(4,6); //i think it will crash
int main()
{
	std::vector<Room> rooms;
	//make 2 rooms
	rooms.push_back(room);
	rooms.push_back(room);
	rooms.push_back(room);
	rooms.push_back(room);
	rooms.push_back(room);
	rooms.push_back(room);

	//first room 
	//have first exit 0
	//have secund exit 1
	rooms[0].AddDoor(&doorRoom0); //take the address of door
	rooms[1].AddDoor(&doorRoom1); //take the address of door
	rooms[2].AddDoor(&doorRoom2); //take the address of door
	rooms[3].AddDoor(&doorRoom3); //take the address of door
	rooms[4].AddDoor(&doorRoom4); //take the address of door
	rooms[5].AddDoor(&doorRoom5); //take the address of door



	//while we have not visitid the last room and the player is alive
	while (player.GetCurrentRoom() < rooms.size() && player.IsAlive() == true)
	{
		rooms[player.GetCurrentRoom()].EnterRoom();
		//player.GoToNextRoom();
	}
	if (player.IsAlive() == true)
	{
		std::cout << "Diablo defeated!" << std::endl;
		SharedFunctions::DeathAscii();
	}
	else
	{
		std::cout << "you burn in hell!" << std::endl;
	}
}

