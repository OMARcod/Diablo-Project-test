#pragma once
#include "Items.h"
#include "ItemType.h"
#include <array>
#include "SharedFunctions.h"

class ItemFactory
{
public:
	ItemFactory();
	~ItemFactory();

	void InitItemTypes();
	Items CreatItem(const ItemType aItemType) const;

private:
	std::array<ItemType, static_cast<int>(ItemTypes::ItemTypeCount)> myItemTypes;

	void InitItemType();
	void InitSpellType();

	std::vector<ItemType>	myItem;
	std::vector<ItemType>	mySpellCategory;
};

