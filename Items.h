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
	std::string GetName();
	void GetItemInfo();
	
	
private:
	int myRoundsOnSpellLeft;
	const ItemType* myItemType;
	std::string myName;
	int value;
	SharedFunctions::PlayerStats myWhatItCanChange;
	bool isSpell;
	
};

//ToDo
//make the logic of displaying and getting the items and change the player defence based on items...
//fix chest items
//make it shared ptr
