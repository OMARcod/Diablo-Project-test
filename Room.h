#pragma once

#include "SharedFunctions.h"
#include "Player.h"
#include "Enemy.h"
#include "Door.h"
#include "Items.h"
#include "Chest.h"
#include "EnemyFactory.h"
#include "ItemFactory.h"

class Room
{
public:
	Room() = delete;
	~Room();


	Room(Player& player);

	void EnterRoom();
	void AddDoor(Door *door);
	void AddChest(Chest *chest);
	//void AddItemToRoom(int anItemType);
	//void AddItem(const Items& aItem);
	void AddItem(std::shared_ptr<Items> aItem);

private:
	//static const int noItme = -1;
	//int myItemType;
	

	std::vector<std::shared_ptr<Enemy>> myEnemies;
	Player *myPlayer;
	Door* myDoor;
	Chest* myChest;
	//Items myItems;

	std::shared_ptr<Items> myItems;

	EnemyFactory enemyFactory;
	

	void DisplayEnemiesWithNumbersAndHealth();
	int SelectEnemyToAttack();
	bool IsAllEnemAlive();
	void DeleteEnemyIfDead(); 
	void DisplayAfterFightInfo(const int anOldEnemySize, const int anOldHealth, const int anOldDefence);
	int DispalyOptionFightOrDoor();
	void DisplayItem();
	void FightEnemies();
	void UseDoor();
	//void AddItemToInentory(const Items& aItem);
	void AddItemToInentory(std::shared_ptr<Items> aItem);
	bool isThereAChest();
};
