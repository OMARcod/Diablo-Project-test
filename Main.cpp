#include <iostream>
#include "Game.h"

int main()
{
	Game diabloGame;

	SharedFunctions::DrawWelcomeAscii();
	diabloGame.GameLoop();
}

