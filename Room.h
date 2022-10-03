#pragma once

#include "SharedFunctions.h"
#include "Player.h"
#include "Enemy.h"
#include "Door.h"

class Room
{
public:
	Room() = delete;
	~Room();


	Room(Player& player);

	void EnterRoom();
	void AddDoor(Door *door);

private:
	std::vector<Enemy> myEnemies;
	Enemy myEnemy;
	Player *myPlayer;
	Door* myDoor;

	void DisplayEnemiesWithNumbersAndHealth();
	int SelectEnemyToAttack();
	bool IsAllEnemAlive();
	void DeleteEnemyIfDead(); 
	void DisplayAfterFightInfo(int oldEnemySize);


	void FightEnemies();
	void UseDoor();


};
