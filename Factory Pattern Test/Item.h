#pragma once
#include "sharedFunction.h"
#include "ItemType.h"
enum class eItemType //public
{
	Heart,
	Sword,
	Milk,
	Defense,
	MaxHealthSpill,
	Count
};

class Item
{
public:
	Item() = delete;
	Item(const ItemType& aEnemyType);
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

