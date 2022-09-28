#include "Player.h"



int Player::GetAttackValue()
{
    return this->myAttackValue;
}

int Player::GetLive()
{
	return this->myHealth;
}

void  Player::AddLive()
{
	this->myHealth += 100;
}

int Player::GetCurrentRoom()
{
	return this->myCurrentRoom;
}


void Player::GoToNextRoom()
{
	this->myCurrentRoom++;
}

bool Player::IsAlive()
{
	assert(myHealth >= 0);

	if (myHealth > 0)
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

Player::Player()
	:myHealth(100),myAttackValue(25),myCurrentRoom(0)
{

}

void Player::SetCurrentRoom(int aCurrentRoom) //??
{
	this->myCurrentRoom = aCurrentRoom;
}
