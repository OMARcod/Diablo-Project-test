#pragma once
#include "SharedFunctions.h"


	

class ItemType
{
public:
	ItemType();
	~ItemType();

	bool isSpell() const;
	void MakeSpell(const int aSpellLength);


	void SetName(const std::string& aName);
	void SetWhatItChange(SharedFunctions::PlayerStats statToChange);
	void SetValue(int aValue);

	std::string GetName();
	int GetValue() const;
	int GetSpellStartLength() const;
	SharedFunctions::PlayerStats GetWhatItChange() const;



private:

	bool myIsSpell;
	int mySpellLength;
	int myValue;
	std::string myName;
	SharedFunctions::PlayerStats myWhatItCanChange;
};
