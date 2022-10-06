#include "Player.h"

Player::Player()
	:myCurrentRoom(0)
	, myStrength(15), myAgility(15), myPhysics(5)
	, myDefense(myPhysics + (myAgility * 5))
	, myAttackValue(myStrength* myAgility)
	, myHealth(myPhysics + (myStrength * 10) + (myAgility * 10))
	, myCarryingCapacity(myStrength + myAgility)
	, myItemWaight(10)
	, mySpillIsActive(false)
	, myMaxSpillDuration(3)
	, myCurrentSpillDuration(0)
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
int Player::GetDefence()
{
	return this->myDefense;
}

int Player::GetCurrentRoom()
{
	return this->myCurrentRoom;
}

void Player::SetCurrentRoom(int aCurrentRoom) 
{
	this->myCurrentRoom = aCurrentRoom;
}

void Player::DisableTheSpill()
{
	int amountOfWaight = 10;
	if (mySpillIsActive)
	{
		myCurrentSpillDuration++;
		if (myCurrentSpillDuration >= myMaxSpillDuration)
		{
			myCurrentSpillDuration = 0;
			mySpillIsActive = false;
			myHealth -= myItem.GetMaxHealthSpillValue();
			assert(myHealth >= 0);
			myCarryingCapacity += amountOfWaight;
		}
	}
}

void Player::AddItem(int anItemType)
{
	myItemsVector.push_back(myItem);
	myItemsVector[(myItemsVector.size()-1)].SetType(anItemType);


	switch (anItemType)
	{
	case static_cast<int>(SharedFunctions::MyItems::Defense):
		myDefense += myItem.GetDefenseValue();
		break;
	case static_cast<int>(SharedFunctions::MyItems::Heart):
		myHealth += myItem.GetHeartValue();
		break;
	case static_cast<int>(SharedFunctions::MyItems::Milk):
		myAttackValue += myItem.GetMilkValue();
		break;
	case static_cast<int>(SharedFunctions::MyItems::Sword):
		myAttackValue += myItem.GetSwordValue();
		break;
	case static_cast<int>(SharedFunctions::MyItems::MaxHealthSpill):
	{
		if (!mySpillIsActive)
		{
			myHealth += myItem.GetMaxHealthSpillValue();
			mySpillIsActive = true;
		}
	}
	default:
		break;
	}
}

bool Player::isCapacityNotFull()
{
	return (myItemsVector.size() * myItemWaight) < myCarryingCapacity;
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






void Player::DisplayInventory()
{
	SharedFunctions::DrawLine();
	std::cout << "----INVINTORY------" << std::endl;
	if (myItemsVector.size() > 0)
	{
		for (int i = 0; i < myItemsVector.size(); i++)
		{
			std::cout << myItemsVector[i].GetItmeName();
			std::cout << "  -->  " << myItemsVector[i].GetItmeInfo() << std::endl;
			SharedFunctions::DrawLine();
		}
	}
	else
	{
		std::cout << " EMPTY!!!  " << std::endl;
	}
	SharedFunctions::DrawLine();
}