#include "ItemType.h"

namespace Diablo
{

	ItemType::ItemType()
		:myValue(0)
		, myName("")
	{
	}

	ItemType::~ItemType()
	{
	}


	const std::string& ItemType::GetName() const
	{
		return myName;
	}

	void ItemType::SetName(const std::string& aName)
	{
		myName = aName;
	}



	const int& ItemType::GetValue() const
	{
		return myValue;
	}

	void ItemType::SetValue(const int& aMaxHealth)
	{
		myValue = aMaxHealth;
	}

}