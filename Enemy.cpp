#include "Enemy.h"
Enemy::Enemy(const EnemyType& aEnemyType)
	:myEnemyType(&aEnemyType)
{
	myHealth = myEnemyType->GetMaxHealth();
}

Enemy::~Enemy()
{
}

bool Enemy::IsAlive()
{
	assert( myHealth >= 0);

	if (myHealth > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Enemy::GetAttackValue()
{
	return myEnemyType->GetStrength();
}

int Enemy::GetHealth()
{
	return this->myHealth;
}

void Enemy::TakeDamage(int anAttackValue)
{

	if (myHealth - anAttackValue >= 0)
	{
		myHealth -= anAttackValue;
	}
	else
	{
		myHealth = 0;
	}

	assert(myHealth >= 0);
}

std::string Enemy::GetName() const
{
	return myEnemyType->GetName();
}



