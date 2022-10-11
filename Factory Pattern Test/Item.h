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

	bool IsAlive() const;

	int GetHealth() const;
	int GetMaxHealth() const;
	std::string GetName() const;

	void TakeDamage(const int aDamage);

private:
	int myHealth;
	const EnemyType* myEnemyType;
};

