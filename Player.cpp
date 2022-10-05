#include "Player.h"

Player::Player()
	:myCurrentRoom(0)
	, myStrength(5), myAgility(5), myPhysics(5)
	, myDefense(myPhysics + (myAgility * 5))
	, myAttackValue(myStrength* myAgility)
	, myHealth(myPhysics + (myStrength * 10) + (myAgility * 10))
	, myCarryingCapacity(myStrength + myAgility)
	, myOriginalDefense(myDefense)
{

}

Player::~Player()
{
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
		if (myDefense < 0)
		{
			myDefense = 0;
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
	this->myHealth += 50;
}

int Player::GetCurrentRoom()
{
	return this->myCurrentRoom;
}

void Player::SetCurrentRoom(int aCurrentRoom) 
{
	this->myCurrentRoom = aCurrentRoom;
}

void Player::AddItem(int itmeID)
{
	switch (itmeID)
	{
	case static_cast<int>(SharedFunctions::MyItems::Defense):
		myDefense += 1000;
		break;
	case static_cast<int>(SharedFunctions::MyItems::Heart):
		myHealth += 1000;
		break;
	case static_cast<int>(SharedFunctions::MyItems::Knife):
		myStrength += 1000;
		break;
	case static_cast<int>(SharedFunctions::MyItems::Sword):
		myStrength += 1000;
		break;

	default:
		break;
	}
}

void Player::DisplayPlayreCharacteristics()
{
	std::cout << "Player Hp : " << this->GetHealth() << " || Strength: " << this->myStrength
		<< " || Agility: " << myAgility << " || Physics: " << this->myPhysics << std::endl;

	std::cout << "Defence : " << this->myDefense 
		<< " || Attack value: " << this->myAttackValue << std::endl;
}

void Player::DisplayPlayreHpAndDefence()
{
	std::cout << "Player Hp : " << this->GetHealth() << " || Defence : " << this->myDefense
		<< std::endl;
}

void Player::ResetDefence()
{
	this->myDefense = myOriginalDefense;
}
