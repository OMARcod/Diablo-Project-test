#include "Enemy.h"

bool Enemy::IsAlive()
{
	assert( myLive >= 0, "Error life is less than 0");

	if (myLive > 0)
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

	if (myLive - anAttackValue >= 0)
	{
		myLive -= anAttackValue;
	}
	else
	{
		myLive = 0;
	}

	assert(myLive >= 0, "Error life is less than 0");
}

int Enemy::GetAttackValue()
{
	return this->myAttackValue;
}

int Enemy::GetLive()
{
	return this->myLive;
}

Enemy::Enemy()
	:myLive(50),myAttackValue(10)
{	
}
