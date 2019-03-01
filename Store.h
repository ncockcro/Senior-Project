/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	1/10/2019

CLASS
	Store

DESCRIPTION
	The purpose of this class is to handle all functionality for the stores in the game. At the beginning of the game, the player
	has access to the store to buy various items and across their journey, there are other stores for them to visit. This class
	will serve as a template for all of the stores to share.
*/
#pragma once

#include <limits>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include "Item.h"
#include "Player.h"

using namespace std;

class Store
{
public:
	Store();

	void DisplayStore(vector<Item> a_items, Player a_player);
	void SetDate(int a_year, string a_month, int a_day);
	void SetLocation(string a_location);
	void SetPlayerMoney(double a_amount);
	double GetTotalPrice();
	vector<Item> GetItemQuantitys();

	

private:
	double CalculateTotal();
	void MakeChoice(Player a_player);


	int m_color;
	string m_month;
	int m_day;
	int m_year;
	string m_location;
	vector<Item> m_userItems;
	int m_itemQuantitys[20] = { 0 };
	double m_itemPrices[20] = { 0.0 };
	double m_playerMoney;
	string m_choice;
	double m_totalPrice;
	Utility m_utility;

};

