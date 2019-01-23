/*
WRITTEN BY
Nicholas Cockcroft

DATE
1/14/2019

CLASS
Item

DESCRIPTION
The purpose of this class is to make up all of the objects of an in game object. This includes things such as an object's name,
price, and description of the item which is used in the in game store. Some of the items of "Oregon Trail" include
oxen, food, clothing, ammunition, and many more. Item objects will be the basis of all of the items in the game.
*/
#pragma once

#include <iostream>
#include <string>
#include "Utility.h"

using namespace std;

class Item
{
public:
	Item();
	Item(string a_name, double a_price, string a_description, string a_capDescription, int a_capNumber);

	string GetName();
	void SetName(string a_name);
	double GetPrice();
	void SetPrice(double a_price);
	string GetDescription();
	void SetDescription(string a_description);
	string GetCapDescription();
	void SetCapDescription(string a_capDescription);
	int GetCapNumber();
	void SetCapNumber(int a_capNumber);
	int GetQuantity();
	void SetQuantity(int a_quantity);

private:
	string m_name;
	double m_price;
	string m_description;
	string m_capDescription;
	int m_capNumber;
	int m_quantity;
	Utility m_utility;
};

