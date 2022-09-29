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
	void AddDoor(Door *door); //this room will have the address of a unic door


private:
	std::vector<Enemy> myEnemies;
	Enemy myEnemy;
	Player *myPlayer;
	Door* myDoor;

	void DisplayEnemiesWithNumbersAndHealth();
	int SelectEnemyToAttack();
	bool IsAllEnemAlive();
	void DeleteEnemyIfDead(); 


	void FightEnemies();
	void UseDoor();


};


//TODO
// 
//The player should have the option to leave the room 
//but he will be notist that he will take damage if he do so

//there is 3 enemys 
//fight or run to the other room

//if run
	//enemy attack the player

//
// The room can have have up to 4 doors
// 1 should leed you back					// DONE
// not all room should have enimes 
// you should know in which room you are in  // DONE
//