#pragma once
#include "sharedFunction.h"
class ItemType
{
public:
	ItemType();
	~ItemType();

	const int& GetValue() const;
	const std::string& GetName() const;


	void SetValue(const int& aMaxHealth);
	void SetName(const std::string& aName);

private:
	int myValue;
	std::string myName;
};

