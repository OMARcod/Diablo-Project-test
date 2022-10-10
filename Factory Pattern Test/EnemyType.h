#pragma once
#include "sharedFunction.h"
class EnemyType
{
public:
	EnemyType();
	~EnemyType();

	const int& GetMaxHealth() const;
	const int& GetStrength() const;
	const int& GetDexterity() const;
	const int& GetStamina() const;
	const std::string& GetName() const;


	void SetMaxHealth(const int& aMaxHealth);
	void SetStrength(const int& aStrength);
	void SetDexterityh(const int& aDexterity);
	void SetStamina(const int& aStamina);
	void SetName(const std::string& aName);

private:
	int myMaxHealth;
	int myStrength;
	int myDexterity;
	int myStamina;
	
	std::string myName;
};

