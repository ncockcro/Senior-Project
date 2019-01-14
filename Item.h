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
#include "Error.h"

using namespace std;

class Item
{
public:
	Item();
	Item(string a_name, double a_price, string a_description);

	string GetName();
	void SetName(string a_name);
	double GetPrice();
	void SetPrice(double a_price);
	string GetDescription();
	void SetDescription(string a_description);

private:
	string m_name;
	double m_price;
	string m_description;
	Error error;
};

