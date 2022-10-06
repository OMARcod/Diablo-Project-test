#include "Items.h"

Items::Items()
	:myItmeID(0)
	, myHeartValue(50), myDefenseValue(100),myMilkValue(10),mySwordValue(30),myMaxHealthSpillValue(1000)
{
}



Items::~Items()
{
}

int Items::GetHeartValue()
{
	return myHeartValue;
}


int Items::GetDefenseValue()
{
	return myDefenseValue;
}

int Items::GetMilkValue()
{
	return myMilkValue;
}

int Items::GetSwordValue()
{
	return mySwordValue;
}

int Items::GetMaxHealthSpillValue()
{
	return myMaxHealthSpillValue;
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
	case static_cast<int>(SharedFunctions::MyItems::Milk):
		myItmeID = static_cast<int>(SharedFunctions::MyItems::Milk);
		break;
	case static_cast<int>(SharedFunctions::MyItems::Sword):
		myItmeID = static_cast<int>(SharedFunctions::MyItems::Sword);
		break;
	case static_cast<int>(SharedFunctions::MyItems::MaxHealthSpill):
		myItmeID = static_cast<int>(SharedFunctions::MyItems::MaxHealthSpill);
		break;
	default:
		break;
	}
}

std::string Items::GetItmeName()
{
	switch (myItmeID)
	{
	case static_cast<int>(SharedFunctions::MyItems::Defense):
	{
		return "Shield";
	}
	case static_cast<int>(SharedFunctions::MyItems::Heart):
	{
		return "Heart";
	}
	case static_cast<int>(SharedFunctions::MyItems::Milk):
	{
		return "Milk";
	}
	case static_cast<int>(SharedFunctions::MyItems::Sword):
	{
		return "Sword";
	}
	case static_cast<int>(SharedFunctions::MyItems::MaxHealthSpill):
	{
		return "Health Spill";
	}
	default:
	{
		return "ERROR";
	}

	}
}

std::string Items::GetItmeInfo()
{
	switch (myItmeID)
	{
	case static_cast<int>(SharedFunctions::MyItems::Defense):
		return "100+ defence";
		break;
	case static_cast<int>(SharedFunctions::MyItems::Heart):
		return "50+ health";
		break;
	case static_cast<int>(SharedFunctions::MyItems::Milk):
		return "10+ attack value";
		break;
	case static_cast<int>(SharedFunctions::MyItems::Sword):
		return "30+ attack value";
		break;
	case static_cast<int>(SharedFunctions::MyItems::MaxHealthSpill):
		return "1000+ health";
		break;
	default:
		return "ERROR";
		break;
	}
}

