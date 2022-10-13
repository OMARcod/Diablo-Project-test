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

void Items::UpdateTurnsLeftOnSpell()
{
	myRoundsOnSpellLeft--;
	assert(myRoundsOnSpellLeft >= 0);
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

SharedFunctions::PlayerStats Items::GetWhatItChange()
{
	return myItemType->GetWhatItChange();
}

int Items::GetValue()
{
	return myValue;
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