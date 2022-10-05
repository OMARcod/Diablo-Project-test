#include "Room.h"

Room::Room(Player& player)
	:myPlayer(&player), myDoor(nullptr), myChest(nullptr), myItmeID(noItme)
{
}

Room::~Room()
{
}

void Room::EnterRoom()
{
	system("cls");
	int currentRoom = myPlayer->GetCurrentRoom();
	std::cout << "You are in Room Nr: " << currentRoom << std::endl;
	SharedFunctions::DorrAscii();
	int input = DispalyOptionFightOrDoor();

	if (myPlayer->IsAlive())
	{
		system("cls");
		UseDoor();
	}
	if (input == 2 || (input == 1 && myEnemies.size() > 0))
	{
		if (currentRoom != myPlayer->GetCurrentRoom())
		{
			system("cls");
			int damage = static_cast<int>((myEnemies.size() * myEnemies[0].GetAttackValue()));
			std::cout << "The Enimes have damaged you while you trying to escape the room" << std::endl;
			std::cout << "Your healt before: ";
			myPlayer->DisplayPlayreHpAndDefence();
			myPlayer->LoseLife(damage);
			SharedFunctions::DrawLine();
			std::cout << "Total Damage : " << damage << std::endl;
			std::cout << "Your healt after: ";
			myPlayer->DisplayPlayreHpAndDefence();
			system("pause");
			myPlayer->ResetDefence();
		}
	}
}

void Room::AddDoor(Door* door)
{
	myDoor = door;

	int nrOfEnemies = SharedFunctions::GetRandomRandom(2, 3);
	for (int i = 0; i < nrOfEnemies; i++)
	{
		myEnemies.push_back(myEnemy);
	}
}

void Room::AddChest(Chest* chest)
{
	myChest = chest;
}

void Room::AddItemToRoom(int itmeID)
{
	myItmeID = itmeID;
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
			myEnemies[i].GetHealth() << " || Attack Value: " << myEnemies[i].GetAttackValue() << "\n";
	}
	SharedFunctions::DrawLine();

	myPlayer->DisplayPlayreCharacteristics();

	SharedFunctions::DrawLine();

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

	for (int i = 0; i < myEnemies.size(); i++)
	{
		if (myEnemies[i].IsAlive() == false)
		{
			myEnemies[i] = myEnemies.back();
			myEnemies.pop_back();
		}
	}
}

void Room::DisplayAfterFightInfo(int oldEnemySize)
{

	std::cout << "You Killed " << oldEnemySize - myEnemies.size() << std::endl;
	if (myEnemies.size() > 0)
	{
		std::cout << myEnemies.size() << " Enemy has attacked you ||";
		std::cout << "Total Damage = " << (myEnemies.size() * myEnemies[0].GetAttackValue()) << std::endl;
	}
	else
	{
		std::cout << "All enemies are dead!" << std::endl;
		std::cout << "Total Damage = 0" << std::endl;


		std::cout << "\n\n You got 50 Hp extra" << std::endl;
		myPlayer->AddLive();

	}

	system("pause");
}

int Room::DispalyOptionFightOrDoor()
{
	int input = 0;
	if (myEnemies.size() > 0)
	{
		std::cout << "1. Fight The Enemies || total enimes = " << myEnemies.size() << std::endl;
		std::cout << "2. Use the doors" << std::endl;
		input = SharedFunctions::ReadInputInt(1, 2);
		if (input == 1)
		{
			FightEnemies();
		}
	}
	else
	{
		std::cout << "1. Use the doors" << std::endl;
		input = SharedFunctions::ReadInputInt(1, 1);
	}
	return input;
}

void Room::DisplayItem()
{
	if (!(myEnemies.size() > 0))
	{
		//if chest display
		//if item drop display
		//if itme in room display

		//Display the item
		if (myItmeID != noItme)
		{
			int input = noItme;

			bool itemIsNotTaken = true;

			while (input != 0)
			{
				system("cls");
				if (itemIsNotTaken)
				{
					std::cout << "There is an Itme in the room:" << std::endl;
					std::cout << myItems.GetItmeName(myItmeID);
					std::cout << "  -->  " << myItems.GetItmeInfo(myItmeID) << std::endl;;
					SharedFunctions::DrawLine();
					std::cout << "1. Take the itme" << std::endl;
					std::cout << "2. Skip it" << std::endl;
				}
				if (isThereAChest())
				{
					std::cout << "4. Open The Chest" << std::endl;
				}
				std::cout << "3. Display Inventory" << std::endl;
				std::cout << "0. Exit" << std::endl;
				input = SharedFunctions::ReadInputInt(0, 4);
				if (input == 1)
				{
					if (itemIsNotTaken)
					{
						itemIsNotTaken = false;
						std::cout << std::endl;
						AddItemToInentory(myItmeID);
					}
				}
				if (input == 4)
				{
					if (isThereAChest())
					{
						if (!(myChest->isChestEmpty()))
						{
							int chestItem = myChest->EnterChest();
							AddItemToInentory(chestItem);
						}
						else
						{
							std::cout << "Empty!!" << std::endl;
						}
					}
				}
				if (input == 3)
				{
					myPlayer->DisplayInventory();
				}
				if (input == 2)
				{
					itemIsNotTaken = false;
				}

				system("pause");
			}

		}
	}
}

void Room::FightEnemies()
{
	system("cls");
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
		int oldSize = static_cast<int>(myEnemies.size());
		DeleteEnemyIfDead();
		DisplayAfterFightInfo(oldSize);
		DisplayItem();
	}

	if (myEnemies.size() <= 0)
	{
		system("cls");
		std::cout << "The Room Nr: " << myPlayer->GetCurrentRoom() << " is Empty!" << std::endl;
		SharedFunctions::DrawLine();
		system("pause");
		system("cls");
	}

	myPlayer->ResetDefence();
}

void Room::UseDoor()
{
	if (myPlayer->IsAlive())
	{
		myDoor->StoreThePlayerStringth(myPlayer->GetAttackValue());
	}
	myPlayer->SetCurrentRoom(myDoor->EnterDoor(myPlayer->GetCurrentRoom()));
}

void Room::AddItemToInentory(int ItemID)
{
	if (ItemID != static_cast<int>(SharedFunctions::MyItems::NoItem))
	{
		if (myPlayer->isCapacityNotFull())
		{
			myPlayer->AddItem(ItemID);
			myPlayer->DisplayPlayreCharacteristics();
		}
		else
		{
			std::cout << "Your Inventroy Is Full" << std::endl;
			system("pause");
		}
	}
}

bool Room::isThereAChest()
{
	return myChest != nullptr;
}

