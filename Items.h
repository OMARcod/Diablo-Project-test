#pragma once
#include "SharedFunctions.h"
#include "ItemType.h"
class Items
{
public:
	Items();
	Items(const ItemType& aItemType);
	~Items();

	void UpdateTurnsLeftOnSpell();
	bool SpellHasEnded() const;
	bool IsSpell() const;
	int GetRoundsOnSpellLeft() const;
	SharedFunctions::PlayerStats GetWhatItChange();
	int GetValue();
	
	
private:
	int myRoundsOnSpellLeft;
	const ItemType* myItemType;
	
};

