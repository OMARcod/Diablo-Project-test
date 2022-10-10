#pragma once
#include "sharedFunction.h"
#include "EnemyType.h"

enum class eEnemyType //public
{
	Skeleton,
	Slime, 
	Dragon,
	Count
};

class Enemy
{
public:
	Enemy() = delete;
	Enemy(const EnemyType& aEnemyType);
	~Enemy();

	bool IsAlive() const;

	int GetHealth() const;
	int GetMaxHealth() const;
	std::string GetName() const;

	void TakeDamage(const int aDamage);

private:
	int myHealth;
	const EnemyType* myEnemyType;
};

