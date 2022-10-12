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

void Player::TakeDamage(int anAttackValue)
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
			//myToChange -= //myspill.value;
			//assert(myToChange >= 0);
			myCarryingCapacity += amountOfWaight;
		}
	}
}




void Player::AddItem(const Items& aItem)
{
	myItemsVector.push_back(aItem);
	//myItemsVector.push_back(itemFactory.CreatItem(anItemType));
	//brcause myitems vecotr is a vector of items

	//int to change  = myitem gettochange
	//int value   = myitem.getvalue

	//chsck if is spell 
	//if(myItem.isSpell())
	//myMaxSpillDuration = myItem.duration;
	// mySpillValue;
	// mySpillToChange;
	//is Active = true

	//TODO

	switch (myItemsVector[myItemsVector.size() - 1].GetWhatItChange())
	{
	case SharedFunctions::PlayerStats::Defense:
		myDefense += myItemsVector[myItemsVector.size() - 1].GetValue();
		break;
	case SharedFunctions::PlayerStats::Health:
		myHealth += myItemsVector[myItemsVector.size() - 1].GetValue();
		break;
	case SharedFunctions::PlayerStats::AttackValue:
		myAttackValue += myItemsVector[myItemsVector.size() - 1].GetValue();
		break;
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
			std::cout << myItemsVector[i].GetName();
			std::cout << "  -->  ";
			myItemsVector[i].GetItemInfo();
			SharedFunctions::DrawLine();
		}
	}
	else
	{
		std::cout << " EMPTY!!!  " << std::endl;
	}
	SharedFunctions::DrawLine();
}