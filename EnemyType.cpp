#include "EnemyType.h"

EnemyType::EnemyType()
	:myMaxHealth(0), myStrength(0)
	, myName("")
{
}

EnemyType::~EnemyType()
{
}

const int& EnemyType::GetMaxHealth() const
{
	return myMaxHealth;
}

const int& EnemyType::GetStrength() const
{
	return myStrength;
}



const std::string& EnemyType::GetName() const
{
	return myName;
}

void EnemyType::SetMaxHealth(const int& aMaxHealth)
{
	myMaxHealth = aMaxHealth;
}

void EnemyType::SetStrength(const int& aStrength)
{
	myStrength = aStrength;
}


void EnemyType::SetName(const std::string& aName)
{
	myName = aName;
}
