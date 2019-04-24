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

#ifndef OREGON_TRAIL_H
#define OREGON_TRAIL_H

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "Trail.h"
#include "Utility.h"

using namespace std;

class Oregon_Trail
{

	struct LeaderBoardEntry {
		string name;
		int score;
	};

public:
	Oregon_Trail();
	void StartGame();

private:
	void ShowChoices();
	void PickDecision(Trail &a_trail);
	void ShowTitle();
	void ShowDescription();
	void ShowLeaderBoard();
	void AddToLeaderBoard(Trail a_trail);
	bool IsPosition(string a_word);
	void ReadInPlayerLevel();

	Utility m_utility;
	string m_choice;
	int m_playerLevel;
	int m_playerXP;

	vector<LeaderBoardEntry> m_entries;
};

#endif