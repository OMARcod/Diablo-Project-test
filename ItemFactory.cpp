#include "ItemFactory.h"
ItemFactory::~ItemFactory()
{
}

Items ItemFactory::CreatItem(const eItemTypes aItemType) const
{
	int itemIndex = static_cast<int>(aItemType);
	return myItemTypes[itemIndex];
}
void ItemFactory::InitItemTypes()
{
	myItemTypes[static_cast<int>(eItemTypes::Heart)].SetWhatItChange(SharedFunctions::PlayerStats::Health);
	myItemTypes[static_cast<int>(eItemTypes::Heart)].SetValue(100);
	myItemTypes[static_cast<int>(eItemTypes::Heart)].SetName("Heart");


	myItemTypes[static_cast<int>(eItemTypes::Shield)].SetWhatItChange(SharedFunctions::PlayerStats::Defense);
	myItemTypes[static_cast<int>(eItemTypes::Shield)].SetValue(200);
	myItemTypes[static_cast<int>(eItemTypes::Shield)].SetName("Shield");


	myItemTypes[static_cast<int>(eItemTypes::Milk)].SetWhatItChange(SharedFunctions::PlayerStats::Health);
	myItemTypes[static_cast<int>(eItemTypes::Milk)].SetValue(500);
	myItemTypes[static_cast<int>(eItemTypes::Milk)].SetName("Milk");

	myItemTypes[static_cast<int>(eItemTypes::Sword)].SetWhatItChange(SharedFunctions::PlayerStats::AttackValue);
	myItemTypes[static_cast<int>(eItemTypes::Sword)].SetValue(500);
	myItemTypes[static_cast<int>(eItemTypes::Sword)].SetName("Sword");


	myItemTypes[static_cast<int>(eItemTypes::MaxHealthSpill)].SetWhatItChange(SharedFunctions::PlayerStats::Health);
	myItemTypes[static_cast<int>(eItemTypes::MaxHealthSpill)].SetValue(2000);
	myItemTypes[static_cast<int>(eItemTypes::MaxHealthSpill)].SetName("Max Health Spill");
}

