#pragma once

#include "SharedFunctions.h"
#include "Player.h"
#include "Enemy.h"
#include "Door.h"
#include "Items.h"
#include "Chest.h"
class Room
{
public:
	Room() = delete;
	~Room();


	Room(Player& player);

	void EnterRoom();
	void AddDoor(Door *door);
	void AddChest(Chest *chest);
	void AddItemToRoom(int anItemType);

private:
	static const int noItme = -1;
	int myItemType;


	std::vector<Enemy> myEnemies;
	Enemy myEnemy;
	Player *myPlayer;
	Door* myDoor;
	Chest* myChest;
	Items myItems;


	void DisplayEnemiesWithNumbersAndHealth();
	int SelectEnemyToAttack();
	bool IsAllEnemAlive();
	void DeleteEnemyIfDead(); 
	void DisplayAfterFightInfo(const int anOldEnemySize, const int anOldHealth, const int anOldDefence);
	int DispalyOptionFightOrDoor();
	void DisplayItem();
	void FightEnemies();
	void UseDoor();
	void AddItemToInentory(int anItemType);
	bool isThereAChest();
};
