#pragma once
#include "SharedFunctions.h"
#include "EnemyType.h"

enum class eEnemyType
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

	bool IsAlive();
	int GetAttackValue();
	int GetHealth();
	void TakeDamage(int anAttackValue);
	std::string GetName() const;


private:

	int myHealth;
	const EnemyType* myEnemyType;
};
