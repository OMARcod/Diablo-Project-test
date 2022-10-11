#pragma once
#include "Items.h"
#include "ItemType.h"
#include <array>
#include "SharedFunctions.h"

class ItemFactory
{
	
public:
	ItemFactory() = default;
	~ItemFactory();


	enum class eItemTypes
	{
		Heart,
		Sword,
		Milk,
		Shield,
		MaxHealthSpill,
		ItemTypeCount,
		NoItem = -1,
	};


	void InitItemTypes();
	Items CreatItem(const eItemTypes aItemType) const;

private:
	std::array<ItemType, static_cast<int>(eItemTypes::ItemTypeCount)> myItemTypes;

	void InitItemType();

	std::vector<eItemTypes>	myItemsCategory;
};

