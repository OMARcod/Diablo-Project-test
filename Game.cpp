#include "Game.h"

Game::Game()
	:noRoom(-1), arraySize(6), myRoomNr(0),
	myRoom(myPlayer),
	myDoorRoom0(0, 1, 5, noRoom, false, true),
	myDoorRoom1(0, 2),
	myDoorRoom2(1, 3),
	myDoorRoom3(2, 4, 5),
	myDoorRoom4(3, 5, 0, 1),
	myDoorRoom5(4, 6),
	myNormalChest(false),
	myMagicCheest( false)
{
	for (int i = 0; i < arraySize; i++)
	{
		myRooms.push_back(myRoom);
	}
	myRooms[0].AddDoor(&myDoorRoom0);
	myRooms[1].AddDoor(&myDoorRoom1);
	myRooms[2].AddDoor(&myDoorRoom2);
	myRooms[3].AddDoor(&myDoorRoom3);
	myRooms[4].AddDoor(&myDoorRoom4);
	myRooms[5].AddDoor(&myDoorRoom5);

	myNormalChest.AddItem(itemFactory.CreatItem(ItemFactory::eItemTypes::Milk));
	myMagicCheest.AddItem(itemFactory.CreatItem(ItemFactory::eItemTypes::MaxHealthSpill));

	myRooms[0].AddChest(&myMagicCheest);
	myRooms[1].AddChest(&myNormalChest);

	itemFactory.InitItemTypes();

	myRooms[0].AddItem(itemFactory.CreatItem(ItemFactory::eItemTypes::Shield));
	myRooms[1].AddItem(itemFactory.CreatItem(ItemFactory::eItemTypes::Sword));
	myRooms[2].AddItem(itemFactory.CreatItem(ItemFactory::eItemTypes::Milk));
	myRooms[3].AddItem(itemFactory.CreatItem(ItemFactory::eItemTypes::Sword));

}



void Game::GameLoop()
{
	while (myPlayer.GetCurrentRoom() < myRooms.size() && myPlayer.IsAlive() == true)
	{
		myRoomNr = myPlayer.GetCurrentRoom();
		myRooms[myRoomNr].EnterRoom();
	}
	if (myPlayer.IsAlive())
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
