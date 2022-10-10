#pragma once
#include "SharedFunctions.h"
class EnemyType
{
public:
	EnemyType();
	~EnemyType();

	const int& GetMaxHealth() const;
	const int& GetStrength() const;

	const std::string& GetName() const;


	void SetMaxHealth(const int& aMaxHealth);
	void SetStrength(const int& aStrength);
	void SetName(const std::string& aName);

private:
	int myMaxHealth;
	int myStrength;

	std::string myName;
};

