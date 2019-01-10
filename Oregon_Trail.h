/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	1/8/2019

CLASS
	Oregon_Trail

DESCRIPTION
	The purpose of this class is to serve as the main running environment for Oregon Trail. This holds the start menu, leaderboard
	functionality, and any other functions that handle taks outside of an active running game.
*/
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "Trail.h"
#include "Error.h"

using namespace std;

class Oregon_Trail
{
public:
	Oregon_Trail();
	void StartGame();

private:
	void ShowChoices();
	void PickDecision();
	void ShowTitle();
	void ShowDescription();
	void ShowLeaderBoard();

	Trail m_trailGame = Trail();
	Error m_error = Error();
};

