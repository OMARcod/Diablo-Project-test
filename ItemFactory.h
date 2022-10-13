#pragma once
#include "Items.h"
#include "ItemType.h"
#include <array>
#include "SharedFunctions.h"
#include <memory>

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
	std::shared_ptr<Items> CreatItem(const eItemTypes aItemType) const;

private:
	std::array<ItemType, static_cast<int>(eItemTypes::ItemTypeCount)> myItemTypes;


	std::vector<eItemTypes>	myItemsCategory;
};

