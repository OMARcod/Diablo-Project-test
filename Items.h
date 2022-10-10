#pragma once
#include "SharedFunctions.h"
class Items
{
public:
	Items();
	~Items();

	
	void SetType(int anItemType);

	std::string GetItmeName();
	std::string GetItmeInfo();

	int GetHeartValue();
	int GetDefenseValue();
	int GetMilkValue();
	int GetSwordValue();
	int GetMaxHealthSpillValue();
	//omard
	//omar
	//omar
private:

	int myItemType;
	int myHeartValue;
	int myDefenseValue;
	int myMilkValue;
	int mySwordValue;
	int myMaxHealthSpillValue;
};

