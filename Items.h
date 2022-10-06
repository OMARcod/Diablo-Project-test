#pragma once
#include "SharedFunctions.h"
class Items
{
public:
	Items();
	~Items();

	
	void SetType(int itemType);



	std::string GetItmeName();
	std::string GetItmeInfo();

	int GetHeartValue();
	int GetDefenseValue();
	int GetMilkValue();
	int GetSwordValue();
	int GetMaxHealthSpillValue();

private:
	int myItmeID;


	int myHeartValue;
	int myDefenseValue;
	int myMilkValue;
	int mySwordValue;
	int myMaxHealthSpillValue;
};





























//player can pick them 
//should be in the room.. when player come in
//should be in chest ... 
//should be in enime when die // random
//add bonuses to player character .. health or other.. only when picked
//every item has a weight


//should be spells to //its temprory


//Items
//item like spells 
//item like wepons
//items like extra health/ damage/ defence

//when creating a room
//add items 
//Room.AddItems(health,knife)
//Room.AddChest(Chest &chest)
//Chest chest1(ture,damage,defence)
// 
// Room.AddEnimes(nrOfEnimes,Items(health))
// 
// Room
//	//roomItems[] 
//	//add
// 
//{ the same way that you add door

//display after fight info // you got 50 hp
// //display if the enemy has dropped somthing 
// 
// //pause
// //delete screen
// 
// display the player items and ability 
//
//add other fucntion 
//after figth option
//in this fucniton 
//show the itme that are in the room or that hs droped from the enemy
//show the chechst 
//let the player chose 
//1. pick up sowrd  //only if enemy 
//2. open the chest //only if there is 
//3. pick up extra defence item
//
//close when the player hitt exit
//dipslay the afterowrd result


//for the spells items 
//the player can only use them in one room 


//Vg should be like doors locked
//Vg player can throw items that he have

