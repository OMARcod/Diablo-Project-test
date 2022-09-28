#include "Room.h"

Room::Room(Player&player)
	:myPlayer(&player),myDoor(nullptr)
{	
	for (size_t i = 0; i < 3; i++)
	{
		myEnemies.push_back(myEnemy);
	}
}

void Room::EnterRoom()
{
	FightEnemies();
	UseDoor();
}

void Room::AddDoor(Door* door)
{
	myDoor = door;  //need to be fixed
}

void Room::DisplayEnemiesWithNumbersAndHealth()
{
		SharedFunctions::EnemyAscii();
	for (int i = 0; i < myEnemies.size(); i++)
	{
		std::cout << "Enemy Nr: " << i << " || Enemy Hp: " <<
			myEnemies[i].GetLive() << "\n";
	}
	std::cout << "|| Player Hp: " << myPlayer->GetLive() << std::endl;
}

bool Room::IsAllEnemAlive()
{
	for (int i = 0; i < myEnemies.size(); i++)
	{
		if (myEnemies[i].IsAlive())
		{
			return true;
		}
	}
	return false;
}

void Room::DeleteEnemyIfDead()
{
	//if enemy is dead ... delete from array
	//but the last element in that place
	//delte the last element 
	for (int i = 0; i < myEnemies.size(); i++)
	{
		if (myEnemies[i].IsAlive() == false)
		{
			myEnemies[i] = myEnemies.back();
			myEnemies.pop_back();
		}
	}
}

void Room::FightEnemies()
{
	system("cls");
	std::cout << "You are in Room Nr: " << myPlayer->GetCurrentRoom() << std::endl;
	SharedFunctions::DorrAscii();
	system("pause");
	while (myEnemies.size() > 0 && myPlayer->IsAlive() == true)
	{
		system("cls");

		DisplayEnemiesWithNumbersAndHealth();
		int selectedEnemy = SelectEnemyToAttack();

		myEnemies[selectedEnemy].LoseLife(myPlayer->GetAttackValue());

		for (int enemyIndex = 0; enemyIndex < myEnemies.size(); enemyIndex++)
		{
			if (myEnemies[enemyIndex].IsAlive() == true)
			{
				myPlayer->LoseLife(myEnemies[enemyIndex].GetAttackValue());
			}
		}
		DeleteEnemyIfDead();
	}
	if (myEnemies.size() <= 0)
	{
		system("cls");
		std::cout << "The Room Nr: " << myPlayer->GetCurrentRoom() << " is Empty!" << std::endl;
		system("pause");

	}
	//??
}

void Room::UseDoor() //go to next room
{
	//make the player chose where to go
	//in Add door we have a pointer to the current door 

	myPlayer->SetCurrentRoom(myDoor->EnterDoor(myPlayer->GetCurrentRoom()));
}



int Room::SelectEnemyToAttack()
{
	assert(myEnemies.size() > 0);
	int selectedEnemy = 0;
	std::cout << "There is " << myEnemies.size() << " enemies!!" << std::endl;
	std::cout << "Attack Enemy -> " << std::endl;
	for (int i = 0; i < myEnemies.size(); i++)
	{
		std::cout << "\tNr: " << i << std::endl;
	}

	selectedEnemy = SharedFunctions::ReadInputInt(0, static_cast<int>(myEnemies.size() - 1));
	return selectedEnemy;
}
