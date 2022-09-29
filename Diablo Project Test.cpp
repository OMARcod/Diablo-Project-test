#include <iostream>
#include <vector>
#include "Room.h"
#include "Player.h"

int main()
{
	const int null = -1;

	Player player;
	Room room(player);
	Door doorRoom0(0, 1, 5, null, false, true);
	Door doorRoom1(0, 2);
	Door doorRoom2(1, 3);
	Door doorRoom3(2, 4, 5);
	Door doorRoom4(3, 5, 0, 1);
	Door doorRoom5(4,6); //i think it will crash
	//

	std::vector<Room> rooms;

	//make 2 rooms

	for (int i = 0; i < 6; i++)
	{
		rooms.push_back(room);
	}
	//first room 
	//have first exit 0
	//have secund exit 1
	rooms[0].AddDoor(&doorRoom0); //take the address of door
	rooms[1].AddDoor(&doorRoom1); 
	rooms[2].AddDoor(&doorRoom2); 
	rooms[3].AddDoor(&doorRoom3); 
	rooms[4].AddDoor(&doorRoom4); 
	rooms[5].AddDoor(&doorRoom5); 

	std::cout << "Welcome to Diablo Game" << std::endl;
	std::cout << 
		R"(
 __     __     ______     __         ______     ______     __    __     ______    
/\ \  _ \ \   /\  ___\   /\ \       /\  ___\   /\  __ \   /\ "-./  \   /\  ___\   
\ \ \/ ".\ \  \ \  __\   \ \ \____  \ \ \____  \ \ \/\ \  \ \ \-./\ \  \ \  __\   
 \ \__/".~\_\  \ \_____\  \ \_____\  \ \_____\  \ \_____\  \ \_\ \ \_\  \ \_____\ 
  \/_/   \/_/   \/_____/   \/_____/   \/_____/   \/_____/   \/_/  \/_/   \/_____/ 
                                                                                  
 )";
	std::cout << R"(
 ___  _       _    _      
| . \<_> ___ | |_ | | ___ 
| | || |<_> || . \| |/ . \
|___/|_|<___||___/|_|\___/
                          )";

	std::cout << std::endl;
	SharedFunctions::DrawLine();
	std::cout << "Info:" << std::endl;
	std::cout << "You win if you can reach room 6" << std::endl;
	std::cout << "Your defense resets when you enter a new room" << std::endl;

	system("pause");


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

