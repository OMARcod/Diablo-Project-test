#pragma once
#include "sharedFunction.h"
#include <array>

namespace Diablo
{
	class Stats
	{

	public:
		enum class StatIndex
		{
			Strength,
			Value,
			StatCoutnt,
		};

		int GetStat(const StatIndex aStartIndex);
		int SetStat(const StatIndex aStartIndex, const int aValue);
		void ChangeStat(const StatIndex aStartIndex, const int aMOdifier);
		void SetName(const std::string& aName);


	private:
		std::string myName;
		std::array<int, static_cast<int>(StatIndex::StatCoutnt)> myValues;
	};

}
