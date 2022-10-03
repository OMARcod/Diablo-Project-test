#include "Enemy.h"
Enemy::Enemy()
	:myHealth(25),myAttackValue(35)
{	
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

int Enemy::GetHealth()
{
	return this->myHealth;
}

int Enemy::GetAttackValue()
{
	return this->myAttackValue;
}


void Enemy::LoseLife(int anAttackValue)
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

