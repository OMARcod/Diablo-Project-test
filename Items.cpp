#include "Items.h"

Items::Items()
	:myItmeID(0)
{
}

Items::~Items()
{
}


void Items::SetType(int itemType)
{
	switch (itemType)
	{
	case static_cast<int>(SharedFunctions::MyItems::Defense):
		myItmeID = static_cast<int>(SharedFunctions::MyItems::Defense);
		break;
	case static_cast<int>(SharedFunctions::MyItems::Heart):
		myItmeID = static_cast<int>(SharedFunctions::MyItems::Heart);
		break;
	case static_cast<int>(SharedFunctions::MyItems::Knife):
		myItmeID = static_cast<int>(SharedFunctions::MyItems::Knife);
		break;
	case static_cast<int>(SharedFunctions::MyItems::Sword):
		myItmeID = static_cast<int>(SharedFunctions::MyItems::Sword);
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

std::string Items::GetItmeName()
{
	switch (myItmeID)
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

std::string Items::GetItmeInfo()
{
	switch (myItmeID)
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

