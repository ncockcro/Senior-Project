#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Item.h"
#include "Utility.h"

using namespace std;

class Random
{
public:
	Random();
	void RandomEvent(Player &a_player);

private:
	void FindWildFruit(Player &a_player);
	void StolenGoods(Player &a_player);
	void BrokenWagonPart();
	void RainWashedPath();
	void BadTrail();
	void Blizzard();
	void DevelopDisease();

	vector<Item>m_itemsLost;
	Utility m_utility;
};

