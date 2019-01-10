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

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class Store
{
public:
	Store();
	~Store();

	void DisplayStore();
	void SetItems(string a_items[]);

private:
	double CalculatePrice(string a_item, int a_quantity);
	int m_color;
	string m_date;
	string m_location;
	vector<string> m_items;
	int m_itemQuantitys[20] = { 0 };
	int m_playerMoney;

};

