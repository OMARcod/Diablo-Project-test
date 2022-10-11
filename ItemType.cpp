#include "ItemType.h"

ItemType::ItemType()
	:myIsSpell(false),mySpellLength(0),myValue(0),myName("")
	,myWhatItCanChange(SharedFunctions::PlayerStats::AttackValue)
{
}

ItemType::~ItemType()
{
}

bool ItemType::isSpell() const
{
	return myIsSpell;
}

int ItemType::GetSpellStartLength() const
{
	return mySpellLength;
}

void ItemType::SetName(const std::string& aName)
{
	myName = aName;
}

void ItemType::MakeSpell(const int aSpellLength)
{
	myIsSpell = true;
	mySpellLength = aSpellLength;
}

void ItemType::SetWhatItChange(SharedFunctions::PlayerStats statToChange)
{
	myWhatItCanChange = statToChange;
}

std::string ItemType::GetName()
{
	return myName;
}

SharedFunctions::PlayerStats ItemType::GetWhatItChange() const
{
	return myWhatItCanChange;
}

void ItemType::SetValue(int aValue)
{
	myValue = aValue;
}

int ItemType::GetValue() const
{
	return myValue;
}


