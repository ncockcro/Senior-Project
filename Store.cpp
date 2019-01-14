#include "Store.h"


/*
	Store::Store()

NAME

	Store::Store - Default constructor

SYNOPSIS

	Store::Store()

DESCRIPTION

	This is the default constructor for the Store class. Sets default values for the member variables

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	2:23pm 1/14/2019
*/
Store::Store()
{
	m_date = "December 31, 9999";
	m_location = "NULL, NULL";
	m_color = 12;
}

/*
	Store::DisplayStore()

NAME

	Store::DisplayStore - Outputs to the console the items and prices of a store object

SYNOPSIS

	Store::DisplayStore()

DESCRIPTION

	The function is used for showing what is in a store object with the different items and prices.
	When a user tpyes in a number for one of the items, the description of the items is displayed and
	the user is able to purchase a certain amount of that item. 

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	2:41pm 1/14/2019
*/
void Store::DisplayStore() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string choice;

	SetConsoleTextAttribute(hConsole, m_color);
	cout << "----------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << m_date << endl;
	cout << m_location << endl;
	SetConsoleTextAttribute(hConsole, m_color);
	cout << "----------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	for (int i = 0; i < m_items.size(); i++) {
		cout << i << ". " << m_items[i] << "      " << CalculatePrice(m_items[i], m_itemQuantitys[i]) << endl;
	}
	SetConsoleTextAttribute(hConsole, m_color);
	cout << "----------------------------" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << "\t \t Total bill: ";

	cout << "Amount you have: $" << m_playerMoney << ".00" << endl;

	cout << "Which item would you like to buy? ";
	cin >> choice;
}

double Store::CalculatePrice(string a_item, int a_quantity) {
	if (a_item == "Oxen") {
		return 40 * a_quantity;
	}
}

void Store::SetItems(string a_items[]) {

}
