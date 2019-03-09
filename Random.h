/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	3/2/2019

CLASS
	Random

DESCRIPTION
	The prupose of this class is to handle all of the functionality surrounding random events that happen while
	the player is traveling the trail. Some of these events are good such as the player finding food in a wild
	fruit tree. However, some are bad such as getting stuck in a blizzard and constantly eating food without
	making any progress.
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Player.h"
#include "Item.h"
#include "Date.h"
#include "Utility.h"

using namespace std;

class Random
{
public:
	Random();
	void RandomEvent(Player &a_player, Date &a_date);

private:
	void FindWildFruit(Player &a_player);
	void FindAbandonedWagon(Player &a_player);
	void StolenGoods(Player &a_player);
	void BrokenWagonPart(Player &a_player);
	void BadTrail(Player &a_player, Date &a_date);
	void Blizzard(Player &a_player, Date &a_date);
	void Thunderstorm(Player &a_player, Date &a_date);
	void DevelopDisease(Player &a_player);
	void BrokenWagonPartHelper(Player &a_player, string a_itemName);
	string PickRandomDisease(vector<string> a_currentDiseases);

	vector<Item>m_itemsLost;
	Utility m_utility;
};

