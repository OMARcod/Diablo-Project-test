#include "Enemy.h"

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

int Enemy::GetAttackValue()
{
	return this->myAttackValue;
}

int Enemy::GetLive()
{
	return this->myHealth;
}

Enemy::Enemy()
	:myHealth(25),myAttackValue(1)
{	
}
