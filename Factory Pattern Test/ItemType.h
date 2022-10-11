#pragma once
#include "sharedFunction.h"
#include "Stats.h"
namespace Diablo
{
	class ItemType
	{
	public:
		ItemType();
		~ItemType();

		const Stats& GetStats() const;
		bool isSpell() const;
		int GetSpellStartLength() const;
		void SetName(const std::string& aName);
		void MakeSpell(const int aSpellLength);

		void SetStat(const Stats::StatIndex aStatIndex, const int aValue);
		void SetName(const std::string& aName);

	private:
		Stats myStats;
		bool myIsSpell;
		int mySpellLength;
	};
}