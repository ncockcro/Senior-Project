/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	2/6/2019

CLASS
	Player

DESCRIPTION
	The prupose of this class is to handle all of the functionality reguarding the player which involves
	their money, items, position they selected and any other functionality such as losing items when the
	player tries to traverse a river.
*/

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Utility.h"
#include "Item.h"
#include "Member.h"

using namespace std;
class Player
{
public:
	Player();

	void InitializePartyItems();
	void SetPlayerMoney(double a_money);
	void SetPlayerPosition(string a_position);
	void SetItemQuantity(string a_itemName, int a_quantity);
	void AddItemQuantity(string a_itemName, int a_quantity);
	Item GetItem(string a_itemName);
	double GetPlayerMoney();
	void DeductMoney(double a_money);
	void DeductFood();
	void DeductFood(bool a_isResting);
	vector<Item> LoseItems();
	string GetPlayerPosition();
	void SetPace(string a_pace);
	string GetPace();
	void SetFoodRate(string a_foodRate);
	string GetFoodRate();
	Member& GetWagonLeader();
	vector<Member>& GetWagonParty();
	int GetHealth();
	void SetHealt(int a_health);
	void RemovePlayer(int a_memberNumber);


private:
	Utility m_utility = Utility();
	void GenerateItemRandNums();
	void IncreaseHealthOutOfHundred(int a_increase);
	void DecreaseHealthOutOfHundred(int a_decrease);

	Member m_wagonLeader;
	vector <Member> m_wagonParty;

	double m_playerMoney;
	string m_playerPosition;

	int m_health; // 0 = very poor, 1 = poor, 2 = fair, 3 = good
	int m_healthOutOfHundred;

	// Player's items
	Item m_Oxen;
	Item m_Food;
	Item m_Clothing;
	Item m_Ammunition;
	Item m_ExtraWheel;
	Item m_ExtraAxle;
	Item m_ExtraTongue;

	string m_pace;
	string m_foodRate;
};

