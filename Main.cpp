#include <iostream>
#include <vector>
#include "Room.h"
#include "Player.h"

int main()
{
	const int noRoom = -1;
	const int arraySize = 6;

	Player player;
	Room room(player);
	Door doorRoom0(0, 1, 5, noRoom, false, true);
	Door doorRoom1(0, 2);
	Door doorRoom2(1, 3);
	Door doorRoom3(2, 4, 5);
	Door doorRoom4(3, 5, 0, 1);
	Door doorRoom5(4,6); 

	std::vector<Room> rooms;

	for (int i = 0; i < arraySize; i++)
	{
		rooms.push_back(room);
	}
	rooms[0].AddDoor(&doorRoom0);
	rooms[1].AddDoor(&doorRoom1); 
	rooms[2].AddDoor(&doorRoom2); 
	rooms[3].AddDoor(&doorRoom3); 
	rooms[4].AddDoor(&doorRoom4); 
	rooms[5].AddDoor(&doorRoom5); 
	
	SharedFunctions::DrawWelcomeAscii();

	int myRoom = 0;
	while (player.GetCurrentRoom() < rooms.size() && player.IsAlive() == true)
	{
		myRoom = player.GetCurrentRoom();
		rooms[myRoom].EnterRoom();
	}
	if (player.IsAlive() == true)
	{
		std::cout << "Diablo defeated!" << std::endl;
		SharedFunctions::DeathAscii();
	}
	else
	{
		std::cout << "you burn in hell!" << std::endl;
		SharedFunctions::DeathAscii();

	}
	system("pause");
}

