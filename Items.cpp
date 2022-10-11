#include "Items.h"

Items::Items(const ItemType& aItemType)
	:myItemType(&aItemType)
{
	myRoundsOnSpellLeft = myItemType->GetSpellStartLength();
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
	return myItemType->isSpell();
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
	return myItemType->GetValue();
}
