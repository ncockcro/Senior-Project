/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	1/9/2019

CLASS
	Trail

DESCRIPTION
	The purpose of this class is to serve as an active game running in Oregon Trail. This is when the player is playing
	an active game of Oregon Trail and traversing the trail. Everything that is defined in this class is for when the player
	is playing an active game of Oregon Trail.
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Error.h"

using namespace std;

class Trail
{
public:
	Trail();
	~Trail();
	void ActiveGame();

private:
	void PromptPosition();
	void PromptCharacterNames();

	Error error = Error();
	int playerMoney;
	string playerPosition;

	string wagonLeader;
	string wagonParty[4];
};

