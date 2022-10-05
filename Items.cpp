#include "Items.h"

Items::Items()
{
}

Items::~Items()
{
}

void Items::SetItems(const SharedFunctions::MyItems itemType)
{
	switch (itemType)
	{
	case SharedFunctions::MyItems::Heart:

		break;
	case SharedFunctions::MyItems::Sword:

		break;
	case SharedFunctions::MyItems::Knife:

		break;
	case SharedFunctions::MyItems::Defense:

		break;
	default:
		break;
	}
}

std::string Items::GetItmeName(int itemID)
{
	switch (itemID)
	{
	case static_cast<int>(SharedFunctions::MyItems::Defense):
		return "Shield";
		break;
	case static_cast<int>(SharedFunctions::MyItems::Heart):
		return "Heart";
		break;
	case static_cast<int>(SharedFunctions::MyItems::Knife):
		return "Knife";
		break;
	case static_cast<int>(SharedFunctions::MyItems::Sword):
		return "Sword";
		break;

	default:
		return "ERROR";
		break;
	}
}

std::string Items::GetItmeInfo(int itemID)
{
	switch (itemID)
	{
	case static_cast<int>(SharedFunctions::MyItems::Defense):
		return "20+ defence";
		break;
	case static_cast<int>(SharedFunctions::MyItems::Heart):
		return "50+ health";
		break;
	case static_cast<int>(SharedFunctions::MyItems::Knife):
		return "10+ strength";
		break;
	case static_cast<int>(SharedFunctions::MyItems::Sword):
		return "30+ strenght";
		break;
	default:
		return "ERROR";
		break;
	}
}

