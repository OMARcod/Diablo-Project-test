#include "Game.h"

Game::Game()
	:noRoom(-1), arraySize(6), myRoom(0),
	room(player),
	doorRoom0(0, 1, 5, noRoom, false, true),
	doorRoom1(0, 2),
	doorRoom2(1, 3),
	doorRoom3(2, 4, 5),
	doorRoom4(3, 5, 0, 1),
	doorRoom5(4, 6),
	normalChest(static_cast<int>(SharedFunctions::MyItems::Milk), false),
	magicCheest(static_cast<int>(SharedFunctions::MyItems::Heart), false)
{
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

	rooms[0].AddChest(&normalChest);
	rooms[1].AddChest(&magicCheest);


	rooms[0].AddItemToRoom(static_cast<int>(SharedFunctions::MyItems::Defense));
	rooms[1].AddItemToRoom(static_cast<int>(SharedFunctions::MyItems::Sword));
	rooms[2].AddItemToRoom(static_cast<int>(SharedFunctions::MyItems::Defense));
	rooms[3].AddItemToRoom(static_cast<int>(SharedFunctions::MyItems::Heart));

}



void Game::GameLoop()
{
	while (player.GetCurrentRoom() < rooms.size() && player.IsAlive() == true)
	{
		myRoom = player.GetCurrentRoom();
		rooms[myRoom].EnterRoom();
	}
	if (player.IsAlive())
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
