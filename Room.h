#pragma once

#include "SharedFunctions.h"
#include "Player.h"
#include "Enemy.h"
#include "Door.h"

class Room
{
public:
	Room(Player& player);
	void EnterRoom();
	void AddDoor(Door *door); //slide 26

private:
	std::vector<Enemy> myEnemies;
	Enemy myEnemy;
	Player *myPlayer;
	Door* myDoor;
	

	void DisplayEnemiesWithNumbersAndHealth();
	int SelectEnemyToAttack();
	bool IsAllEnemAlive();
	void DeleteEnemyIfDead(); //my func


	void FightEnemies();
	void UseDoor();


};

