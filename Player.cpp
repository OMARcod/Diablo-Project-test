#include "Player.h"



int Player::GetAttackValue()
{
    return this->myAttackValue;
}

int Player::GetLive()
{
	return this->myLive;
}

void  Player::AddLive()
{
	this->myLive += 100;
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
	assert(myLive >= 0);

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

	assert(myLive >= 0);
}

Player::Player()
	:myLive(100),myAttackValue(25),myCurrentRoom(0)
{

}

void Player::SetCurrentRoom(int aCurrentRoom) //??
{
	this->myCurrentRoom = aCurrentRoom;
}
