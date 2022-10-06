#pragma once
#include <assert.h>
#include <iostream>
#include <vector>
#include <random>

namespace SharedFunctions
{
	int ReadInputInt();
	int ReadInputInt(int aMinNr, int aMaxNr);

	void DeathAscii();
	void DorrAscii();
	void EnemyAscii();
	void DrawLine();
	void EnemyAsciiTow();
	void EnemyAsciiThree();
	void DrawThisString(std::string art, int nrOfTime);
	void DrawWelcomeAscii();

	int GetRandomNumber(int aMin, int aMax);

	enum class MyItems
	{
		Heart,
		Sword,
		Milk,
		Defense,
		MaxHealthSpill,
		NoItem = -1
	};
};

