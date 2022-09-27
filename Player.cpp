#include "Player.h"

int Player::GetAttackValue()
{
    return this->myAttackValue;
}

int Player::GetLive()
{
	return this->myLive;
}

bool Player::IsAlive()
{
	assert(myLive > 0, "Error life is less than 0");

	if (myLive > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::LoseLife(int anAttackValue)
{

	if (myLive - anAttackValue >= 0)
	{
		myLive -= anAttackValue;
	}
	else
	{
		myLive = 0;
	}

	assert(myLive > 0, "Error life is less than 0");
}

Player::Player()
	:myLive(100),myAttackValue(25)
{
}
