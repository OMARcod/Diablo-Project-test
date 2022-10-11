#include "ItemFactory.h"
namespace Diablo
{
	ItemFactory::ItemFactory()
	{
	}

	ItemFactory::~ItemFactory()
	{
	}

	void ItemFactory::InitItemTypes()
	{
		myItemTypes[static_cast<size_t>(eItemTypes::Heart)].SetStat(Stats::eStatIndex::eAttack, 3);
		myItemTypes[static_cast<size_t>(eItemTypes::eDagger)].SetStat(Stats::eStatIndex::eDexterity, 2);
		myItemTypes[static_cast<size_t>(eItemTypes::eDagger)].SetStat(Stats::eStatIndex::eMaxWeight, 1);
		myItemTypes[static_cast<size_t>(eItemTypes::eDagger)].SetName("dagger");

		myItemTypes[static_cast<size_t>(eItemTypes::eGreatSword)].SetStat(Stats::eStatIndex::eAttack, 10);
		myItemTypes[static_cast<size_t>(eItemTypes::eGreatSword)].SetStat(Stats::eStatIndex::eStrength, 4);
		myItemTypes[static_cast<size_t>(eItemTypes::eGreatSword)].SetStat(Stats::eStatIndex::eMaxWeight, 5);
		myItemTypes[static_cast<size_t>(eItemTypes::eGreatSword)].SetName("great sword");

		myItemTypes[static_cast<size_t>(eItemTypes::eSword)].SetStat(Stats::eStatIndex::eAttack, 6);
		myItemTypes[static_cast<size_t>(eItemTypes::eSword)].SetStat(Stats::eStatIndex::eDexterity, 1);
		myItemTypes[static_cast<size_t>(eItemTypes::eSword)].SetStat(Stats::eStatIndex::eStrength, 1);
		myItemTypes[static_cast<size_t>(eItemTypes::eSword)].SetName("sword");

		myWeaponCategory.push_back(eItemTypes::eDagger);
		myWeaponCategory.push_back(eItemTypes::eGreatSword);
		myWeaponCategory.push_back(eItemTypes::eSword);
	}

	void ItemFactory::InitSpellType()
	{
	}

	Item ItemFactory::CreatItem(const eItemTypes aItemType) const
	{
		int itemIndex = static_cast<int>(aItemType);
		const ItemType& itemType = myItemTypes[itemIndex];
		return Item(itemType);
	}
}