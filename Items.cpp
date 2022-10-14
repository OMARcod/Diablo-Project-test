#include "Items.h"

Items::Items()
	:myRoundsOnSpellLeft(0),myItemType(nullptr),myName(""),myValue(0),myIsSpell(false)
	,myWhatItCanChange(SharedFunctions::PlayerStats::AttackValue)
{
}

Items::Items(const ItemType& aItemType)
	:myItemType(&aItemType)
{
	myRoundsOnSpellLeft = aItemType.GetSpellStartLength();
	myName = aItemType.GetName();
	myValue = aItemType.GetValue();
	myWhatItCanChange = aItemType.GetWhatItChange();
	myIsSpell = aItemType.isSpell();
}


Items::~Items()
{
}

bool Items::SpellHasEnded() const
{
	return myRoundsOnSpellLeft == 0;
}

bool Items::IsSpell() const
{
	return myIsSpell;
}

int Items::GetRoundsOnSpellLeft() const
{
	return myRoundsOnSpellLeft;
}

int Items::GetValue()
{
	return myValue;
}

void Items::UpdateTurnsLeftOnSpell()
{
	myRoundsOnSpellLeft--;
	assert(myRoundsOnSpellLeft >= 0);
}

SharedFunctions::PlayerStats Items::GetWhatItChange()
{
	return myItemType->GetWhatItChange();
}

std::string Items::GetName()
{
	return myItemType->GetName();
}

void Items::GetItemInfo()
{
	switch (myWhatItCanChange)
	{
	case SharedFunctions::PlayerStats::AttackValue:
		std::cout << "Attack Value" << " +" << myItemType->GetValue() << std::endl;
		break;
	case SharedFunctions::PlayerStats::Defense:
		std::cout << "Defense" << " +" << myItemType->GetValue() << std::endl;
		break;
	case SharedFunctions::PlayerStats::Health:
		std::cout << "Health" << " +" << myItemType->GetValue() << std::endl;
		break;
	default:
		break;
	}
}
