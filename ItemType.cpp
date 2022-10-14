#include "ItemType.h"

ItemType::ItemType()
	:myIsSpell(false), mySpellLength(0), myValue(0), myName("")
	, myWhatItCanChange(SharedFunctions::PlayerStats::AttackValue)
{
}

ItemType::~ItemType()
{
}

bool ItemType::isSpell() const
{
	return myIsSpell;
}

void ItemType::MakeSpell(const int aSpellLength)
{
	myIsSpell = true;
	mySpellLength = aSpellLength;
}

void ItemType::SetName(const std::string& aName)
{
	myName = aName;
}

void ItemType::SetWhatItChange(SharedFunctions::PlayerStats statToChange)
{
	myWhatItCanChange = statToChange;
}

void ItemType::SetValue(int aValue)
{
	myValue = aValue;
}

std::string ItemType::GetName() const
{
	return myName;
}

int ItemType::GetValue() const
{
	return myValue;
}

int ItemType::GetSpellStartLength() const
{
	return mySpellLength;
}

SharedFunctions::PlayerStats ItemType::GetWhatItChange() const
{
	return myWhatItCanChange;
}








