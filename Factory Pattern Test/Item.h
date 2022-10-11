#pragma once
#include "sharedFunction.h"
#include "ItemType.h"


enum class ItemTypes
{
	Heart,
	Sword,
	Milk,
	Defense,
	MaxHealthSpill,
	ItemTypeCount,
	NoItem = -1,
};

class Item
{
public:
	Item() = delete;
	Item(const ItemTypes& aEnemyType);
	~Item();

	std::string GetName() const;
	int GetValue();
	int GetWhatItChange(); //return what it can change health strength ?? 


	void TakeDamage(const int aDamage);
	

	

private:
	int myHealth;
};



