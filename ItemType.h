#pragma once
#include "SharedFunctions.h"


	enum class ItemTypes
	{
		Heart,
		Sword,
		Milk,
		Defense,
		MaxHealthSpill,
		ItemTypeCount,
		NoItem = -1,
	};
class ItemType
{
public:
	ItemType();
	~ItemType();

	bool isSpell() const;
	int GetSpellStartLength() const;
	void SetName(const std::string& aName);
	void MakeSpell(const int aSpellLength);

	void SetName(const std::string& aName);
	void SetWhatItChange(SharedFunctions::PlayerStats statToChange);
	void SetValue(int aValue);

private:
	bool myIsSpell;
	int mySpellLength;
	int whatItChange;
	int value;
};
