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
	void AddItemToRoom(int itmeID);

private:
	std::vector<Enemy> myEnemies;
	Enemy myEnemy;
	Player *myPlayer;
	Door* myDoor;
	Chest* myChest; //new

	Items myItems; //new

	int myItmeID;
	static const int noItme = -1;
	void DisplayEnemiesWithNumbersAndHealth();
	int SelectEnemyToAttack();
	bool IsAllEnemAlive();
	void DeleteEnemyIfDead(); 
	void DisplayAfterFightInfo(const int oldEnemySize, const int oldHealth, const int oldDefence);
	int DispalyOptionFightOrDoor();

	void DisplayItem();
	
	void FightEnemies();
	void UseDoor();
	
	void AddItemToInentory(int ItemID);
	bool isThereAChest();
};
