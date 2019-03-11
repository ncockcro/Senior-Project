/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	1/9/2019

CLASS
	Main

DESCRIPTION
	This is the main entry into my program. This simply calls the function from my Oregon Trail class
	to start the game and everything is handled through self made classes.
*/

#include "Oregon_Trail.h"

int main() {
	
	Oregon_Trail MainGame = Oregon_Trail();

	MainGame.StartGame();
	return 0;
}