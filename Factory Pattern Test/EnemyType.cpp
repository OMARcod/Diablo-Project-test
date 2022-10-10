#include "EnemyType.h"

EnemyType::EnemyType()
	:myMaxHealth(0),myStrength(0),myStamina(0),myDexterity(0)
	,myName("")
{
}

EnemyType::~EnemyType()
{
}

const int& EnemyType::GetMaxHealth() const
{
	// TODO: insert return statement here
	return myMaxHealth;
}

const int& EnemyType::GetStrength() const
{
	return myStrength;
}

const int& EnemyType::GetDexterity() const
{
	return myDexterity;
}

const int& EnemyType::GetStamina() const
{
	return myStamina;
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

void EnemyType::SetDexterityh(const int& aDexterity)
{
	myDexterity = aDexterity;
}

void EnemyType::SetStamina(const int& aStamina)
{
	myStamina = aStamina;
}

void EnemyType::SetName(const std::string& aName)
{
	myName = aName;
}
