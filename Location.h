/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	1/30/2019

CLASS
	Location

DESCRIPTION
	The purpose of this class is to represent locations in the game and have basic functionality such as the
	name of the location, distance needed to travel to the location, and any other useful information about
	a place.
*/
#pragma once

#include <iostream>
#include <string>
#include "Utility.h"
#include "Player.h"
#include "Date.h"

using namespace std;

class Location
{
public:
	Location();
	virtual void CrossLocation(Player &a_player, Date &a_date);
	void SetName(string a_name);
	string GetName();
	void SetMilesNeeded(int a_miles);
	int GetMilesNeeded();
	void SetHasStore(bool a_has);
	bool GetHasStore();

private:

	string m_name;
	int m_milesNeeded;
	Utility m_utility;
	bool m_hasStore;

};

