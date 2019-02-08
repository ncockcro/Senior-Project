/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	1/30/2019

CLASS
	River

DESCRIPTION
	The prupose of this class is to give further functionality to a location, specifically a river, and provides
	further functions and variables that are needed for when a player is crossing a river.
*/
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Location.h"
#include "Utility.h"
#include "Player.h"
#include "Date.h"

using namespace std;

class River: public Location
{
public:
	River();
	void CrossLocation(Player a_player, Date &a_date, int a_weather);
	double GetRiverWidth();
	double GetRiverDepth();
	void SetHasFerry(bool a_hasFerry);

private:
	void OpeningDialogue();
	void ShowRiverMenu(string a_weather);
	void FordRiver(Player &a_player);
	void FloatRiver(Player &a_player);
	bool TakeFerry(Player &a_player);
	void WaitADay(Date &a_date);
	void RiverMoreInfoDialogue();
	bool GenerateRandomNum(double a_percent);

	double m_randomNum;
	double m_riverWidth;
	double m_riverDepth;
	Utility m_utility = Utility();
	bool m_hasFerry;
};

