#pragma once
#include "Item.h"
#include "ItemType.h"
#include <array>

namespace Diablo
{
	class ItemFactory
	{
	public:
		ItemFactory() ;
		~ItemFactory();

		void InitItemTypes();
		Item CreatItem(const ItemTypes aItemType) const;

	private:
		std::array<ItemType, static_cast<int>(ItemTypes::ItemTypeCount)> myItemTypes;

		void InitItemTypes();
		void InitSpellType();

		std::vector<ItemTypes>	myItem;
		std::vector<ItemTypes>	mySpellCategory;
	};

}