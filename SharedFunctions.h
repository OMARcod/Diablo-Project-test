#pragma once
#include <assert.h>
#include <iostream>
#include <vector>

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


};

