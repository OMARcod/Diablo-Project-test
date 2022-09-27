// Diablo Project Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Enemy.h"
#include "Player.h"

int main()
{
	Enemy enemy;
	Player player;



	while (enemy.IsAlive() == true)
	{
		std::cout << "Enemy Hp: " << enemy.GetLive() << " || Player Hp: " << player.GetLive() << std::endl;
		std::cout << "Press enter to attack enemy!" << std::endl;
		system("pause");
		enemy.LoseLife(player.GetAttackValue());
	}
	std::cout << "Diablo defated!" << std::endl;
}
