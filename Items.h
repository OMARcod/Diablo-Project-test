#pragma once
#include "SharedFunctions.h"
#include "ItemType.h"
class Items
{
public:
	Items();
	Items(const ItemType& aItemType);
	~Items();

	bool SpellHasEnded() const;
	bool IsSpell() const;
	int GetRoundsOnSpellLeft() const;
	int GetValue();
	void UpdateTurnsLeftOnSpell();
	SharedFunctions::PlayerStats GetWhatItChange();
	std::string GetName();
	void GetItemInfo();
	
	
private:
	bool myIsSpell;
	int myRoundsOnSpellLeft;
	int myValue;

	std::string myName;

	SharedFunctions::PlayerStats myWhatItCanChange;

	const ItemType* myItemType;
	
};
