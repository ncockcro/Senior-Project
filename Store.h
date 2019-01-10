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

