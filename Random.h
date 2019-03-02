#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Item.h"
#include "Date.h"
#include "Utility.h"

using namespace std;

class Random
{
public:
	Random();
	void RandomEvent(Player &a_player, Date &a_date, int a_weather);

private:
	void FindWildFruit(Player &a_player);
	void StolenGoods(Player &a_player);
	void BrokenWagonPart(Player &a_player);
	void RainWashedPath();
	void BadTrail();
	void Blizzard(Player &a_player, Date &a_date);
	void Thunderstorm(Player &a_player, Date &a_date);
	void DevelopDisease();
	void BrokenWagonPartHelper(Player &a_player, string a_itemName);

	vector<Item>m_itemsLost;
	Utility m_utility;
};

