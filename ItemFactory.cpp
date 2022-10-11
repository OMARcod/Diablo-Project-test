#include "ItemFactory.h"
void ItemFactory::InitItemType()
{
	myItemTypes[static_cast<int>(ItemTypes::Heart)].SetWhatItChange(SharedFunctions::PlayerStats::Health);
	myItemTypes[static_cast<int>(ItemTypes::Heart)].SetValue(1000);

}
