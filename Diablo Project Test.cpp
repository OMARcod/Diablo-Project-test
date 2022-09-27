// Diablo Project Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include <vector>

int anArraySize = 3;
Player player;
std::vector<Enemy> enemies(anArraySize);




//void DisplayEnemiesWithNumbersAndHealth(Enemy* aEnemey, Player aPlayer, int anArraySize);
void DisplayEnemiesWithNumbersAndHealth();
bool AllEnemisAlive();
int SelectEnemyToAttack();  // add check condtion

int main()
{
	while (AllEnemisAlive() == true && player.IsAlive() == true)
	{
		system("cls");
		DisplayEnemiesWithNumbersAndHealth();
		int selectedEnemy = SelectEnemyToAttack();

		enemies[selectedEnemy].LoseLife(player.GetAttackValue());
		for (int enemyIndex = 0; enemyIndex < enemies.size(); enemyIndex++)
		{
			if (enemies[enemyIndex].IsAlive() == true)
			{
				player.LoseLife(enemies[enemyIndex].GetAttackValue());
			}
		}
	}

	if (player.IsAlive() == true)
	{
		std::cout << "Diablo defated!" << std::endl;
	}
	else
	{
		std::cout << "You burn in hell!" << std::endl;
	}


}

void DisplayEnemiesWithNumbersAndHealth()
{
	for (int i = 0; i < anArraySize; i++)
	{
		if (enemies[i].IsAlive())
		{
			std::cout << "Enemy Nr: " << i << " || Enemy Hp: " <<
				enemies[i].GetLive() << "\t|| Player Hp: " << player.GetLive() << std::endl;
		}
	}
}

bool AllEnemisAlive()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].IsAlive())
		{
			return true;
		}
	}
	return false;
}

int SelectEnemyToAttack()
{
	int selectedEnemy = 0;
	std::cout << "There is " << enemies.size() << " enemies!!" << std::endl;
		std::cout << "Attack Enemy -> " << std::endl;
	for (int i = 0; i < enemies.size(); i++)
	{
		std::cout << "\tNr: " << i << std::endl;
	}
	
	std::cin >> selectedEnemy;

	return selectedEnemy;
}

