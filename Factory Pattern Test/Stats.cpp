#include "Stats.h"

int Stats::GetStat(const StatIndex aStartIndex)
{
    return myValues[static_cast<int>(aStartIndex)];
}

int Stats::SetStat(const StatIndex aStartIndex, const int aValue)
{
    assert(aValue > 0);
    return myValues[static_cast<int>(aStartIndex)] = aValue;
}

void Stats::ChangeStat(const StatIndex aStartIndex, const int aModifier)
{
    myValues[static_cast<int>(aStartIndex)] += aModifier;
}

void Stats::SetName(const std::string& aName)
{
    myName = aName;
}
