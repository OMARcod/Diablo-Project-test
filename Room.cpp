#include "Room.h"

Room::Room(Player&player)
	:myPlayer(&player),myDoor(nullptr),nrOfEnemies(3)
{	
	for (size_t i = 0; i < nrOfEnemies; i++)
	{
		myEnemies.push_back(myEnemy);
	}
}

void Room::EnterRoom()
{
	FightEnemies();
	if (myPlayer->IsAlive())
	{
		UseDoor();
	}
}

void Room::AddDoor(Door* door)
{
	myDoor = door;  //need to be fixed
}



void Room::DisplayEnemiesWithNumbersAndHealth()
{
	if (myEnemies.size() == 2)
	{
		SharedFunctions::EnemyAsciiTow();
	}
	else if (myEnemies.size() == 3)
	{
		SharedFunctions::EnemyAsciiThree();
	}
	else
	{
		SharedFunctions::EnemyAscii();
	}
		SharedFunctions::DrawLine();

	for (int i = 0; i < myEnemies.size(); i++)
	{
		std::cout << "Enemy Nr: " << i << " || Enemy Hp: " <<
			myEnemies[i].GetHealth()  << " || Attack Value: " << myEnemies[i].GetAttackValue() << "\n";
	}
	SharedFunctions::DrawLine();

	myPlayer->DisplayPlayreCharacteristics();

	SharedFunctions::DrawLine();

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
		system("cls");
	}

	myPlayer->ResetDefence(); //reset defence value 
	//??
}

void Room::UseDoor() //go to next room
{
	//make the player chose where to go
	//in Add door we have a pointer to the current door 
	if (myPlayer->IsAlive()) //store the player attack value in the door class 
	{
		myDoor->SetMyPlayerStringth(myPlayer->GetAttackValue()); // need to be fixed .. get strignth
	}
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
