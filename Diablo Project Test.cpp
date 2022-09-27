#include <iostream>
#include <vector>
#include "Room.h"
#include "Player.h"

Room room;
Player player;
Door door(0, 1);
int main()
{
	std::vector<Room> rooms;
	rooms.push_back(room);
	rooms.push_back(room);

	rooms[0].AddDoor(&door);



	

	while (player.GetCurrentRoom() < rooms.size() && player.IsAlive() == true)
	{
		rooms[player.GetCurrentRoom()].EnterRoom(player);
		player.GoToNextRoom();
	}
	if (player.IsAlive() == true)
	{
		std::cout << "Diablo defeated!" << std::endl;
	}
	else
	{
		std::cout << "you burn in hell!" << std::endl;
	}
}

