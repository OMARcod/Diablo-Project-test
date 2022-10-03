#pragma once
class Items
{
public:
	Items();
	~Items();

	enum class MyItems
	{
		Heart,
		Strength,
		Knife,
		Defense

	};


	void SetItems(const MyItems itemType);

private:

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







//Vg should be like doors locked
//Vg player can throw items that he have

