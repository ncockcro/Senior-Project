#pragma once

#include <iostream>
#include <string>
#include "Utility.h"
#include "Item.h"

using namespace std;
class Player
{
public:
	Player();
	~Player();

	void InitializePartyItems();
	void SetPlayerMoney(double a_money);
	void SetPlayerPosition(string a_position);
	void SetItemQuantity(string a_itemName, int a_quantity);
	Item GetItem(string a_itemName);
	double GetPlayerMoney();
	void DeductMoney(double a_money);
	void DeductFood(string a_rate);


private:
	Utility m_utility = Utility();
	double m_playerMoney;
	string m_playerPosition;

	// Player's items
	Item m_Oxen;
	Item m_Food;
	Item m_Clothing;
	Item m_Ammunition;
	Item m_ExtraWheel;
	Item m_ExtraAxle;
	Item m_ExtraTongue;
};

