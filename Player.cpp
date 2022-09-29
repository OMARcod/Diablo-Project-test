#include "Player.h"



int Player::GetAttackValue()
{
	return this->myAttackValue;
}

int Player::GetHealth()
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
		int tempAttack = anAttackValue;
		if (myDefense > 0)
		{
			anAttackValue -= myDefense;
			myDefense -= tempAttack;
		}

		if (anAttackValue > 0)
		{
			myHealth -= anAttackValue;
		}
	}
	else
	{
		myHealth = 0;
	}

	assert(myHealth >= 0);
}

Player::Player()
	:myCurrentRoom(0)
	, myStrength(5), myAgility(5), myPhysics(5)
	, myDefense(myPhysics + (myAgility * 5)) //30
	, myAttackValue(myStrength* myAgility) //25
	, myHealth(myPhysics + (myStrength * 10) + (myAgility * 10)) //105
	, myCarryingCapacity(myStrength + myAgility) //10  
	, myOriginalDefense(myDefense)
{

}

void Player::SetCurrentRoom(int aCurrentRoom) //??
{
	this->myCurrentRoom = aCurrentRoom;
}

void Player::DisplayPlayreCharacteristics()
{
	std::cout << "Player Hp : " << this->GetHealth() << " || Strength: " << this->myStrength
		<< " || Agility: " << myAgility << " || Physics: " << this->myPhysics << std::endl;

	std::cout << "Defence : " << this->myDefense 
		<< " || Attack value: " << this->myAttackValue << std::endl;
}

void Player::ResetDefence()
{
	this->myDefense = myOriginalDefense;
}
