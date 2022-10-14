#include "Player.h"

Player::Player()
	:myCurrentRoom(0)
	, myStrength(15), myAgility(15), myPhysics(5)
	, myDefense(myPhysics + (myAgility * 5))
	, myAttackValue(myStrength* myAgility)
	, myHealth(myPhysics + (myStrength * 10) + (myAgility * 10))
	, myCarryingCapacity(myStrength + myAgility)
	, myItemWaight(10)
	, myHaveSpill(false)
	,mySpillIndex(0)
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
	if (myHaveSpill)
	{
		myItemsVector[mySpillIndex]->UpdateTurnsLeftOnSpell();
		if (myItemsVector[mySpillIndex]->GetRoundsOnSpellLeft() <= 0)
		{
			myHaveSpill = false;
			myCarryingCapacity += amountOfWaight;
			DecreasePlayerStat(mySpillIndex);
		}
	}
}



void Player::AddItem(std::shared_ptr<Items> aItem)
{
	myItemsVector.push_back(aItem);
	int ItemIndex = static_cast<int>(myItemsVector.size() - 1);

	if (aItem->IsSpell())
	{
		myHaveSpill = true;
		mySpillIndex = ItemIndex;
	}

	IncreasePlayerStat(ItemIndex);
}

void Player::IncreasePlayerStat(int itemIndex)
{
	switch (myItemsVector[itemIndex]->GetWhatItChange())
	{
	case SharedFunctions::PlayerStats::Defense:
		myDefense += myItemsVector[itemIndex]->GetValue();
		break;
	case SharedFunctions::PlayerStats::Health:
		myHealth += myItemsVector[itemIndex]->GetValue();
		break;
	case SharedFunctions::PlayerStats::AttackValue:
		myAttackValue += myItemsVector[itemIndex]->GetValue();
		break;
	default:
		break;
	}
}
void Player::DecreasePlayerStat(int itemIndex)
{
	switch (myItemsVector[itemIndex]->GetWhatItChange())
	{
	case SharedFunctions::PlayerStats::Defense:
		myDefense -= myItemsVector[itemIndex]->GetValue();
		break;
	case SharedFunctions::PlayerStats::Health:
		myHealth -= myItemsVector[itemIndex]->GetValue();
		break;
	case SharedFunctions::PlayerStats::AttackValue:
		myAttackValue -= myItemsVector[itemIndex]->GetValue();
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
			std::cout << myItemsVector[i]->GetName();
			std::cout << "  -->  ";
			myItemsVector[i]->GetItemInfo();
			SharedFunctions::DrawLine();
		}
	}
	else
	{
		std::cout << " EMPTY!!!  " << std::endl;
	}
	SharedFunctions::DrawLine();
}

