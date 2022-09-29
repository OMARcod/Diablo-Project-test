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

//add room map  
//after you finish

//// room 0//////------room1-------/////room2/////
////room3//////-----room4--------/////room5/////
