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

	m_choice = "1";
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
void Store::DisplayStore(vector<Item> a_items) {

	m_items = a_items;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string choice;

	while (stoi(m_choice) != a_items.size() + 1) {
		SetConsoleTextAttribute(hConsole, m_color);
		cout << "-----------------------------------------------" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\t        " << m_date << endl;
		cout << "\t   " << m_location << endl;
		SetConsoleTextAttribute(hConsole, m_color);
		cout << "-----------------------------------------------" << endl;
		SetConsoleTextAttribute(hConsole, 7);

		for (size_t i = 0; i < a_items.size(); i++) {
			cout << "\t " << i + 1 << ". " << a_items[i].GetName() << m_itemPrices[i] << endl;
		}
		cout << "\t " << a_items.size() + 1 << ". to leave the store." << endl;
		SetConsoleTextAttribute(hConsole, m_color);
		cout << "-----------------------------------------------" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\t \t Total bill: $" << CalculateTotal() << endl;

		cout << "\t \t Amount you have: $" << m_playerMoney << ".00" << endl;

		MakeChoice();
	}
}

/*
	Store::MakeChoice(vector<Item> a_items)

NAME

	Store::MakeChoice - Prompts the user for the amount of items they want to buy

SYNOPSIS

	Store::MakeChoice()

DESCRIPTION

	This function is designed for prompting the user to make a choice from the list of items in the store.
	Once an option has been selected, this will cycle through and make sure that the choice the user picks
	is a valid one. It will then set the quantity of how much of an item a user wants and will calculate
	the price to be shown on the main view of the store.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	6:31pm 1/22/2019
*/
void Store::MakeChoice() {

	string amount;
	bool validChoice = false;

	cout << "Which item would you like to buy? ";
	cin >> m_choice;

	for (size_t i = 0; i < m_items.size(); i++) {
		try {
			if (m_utility.IsDigits(m_choice) && (stoi(m_choice) - 1) == i) {
				cout << m_items[i].GetDescription() << endl;

				while (1) {
					cout << "How many would you like to buy? ";
					cin >> amount;

					m_itemQuantitys[i] = stoi(amount);
					m_itemPrices[i] = stoi(amount) * m_items[i].GetPrice();

					// If the user tries to buy more than the limited amount...
					if (stoi(amount) > m_items[i].GetCapNumber()) {
						m_utility.DisplayError(m_items[i].GetCapDescription());
					}
					// If the user tries to buy more of a product than the amount of money they have...
					else if (m_itemPrices[i] > m_playerMoney) {
						m_utility.DisplayError("You don't have enough money for that.");
					}
					// Otherwise everything is good
					else {
						validChoice = true;
						break;
					}
				}
			}
		}
		catch (exception e) {
			m_utility.DisplayError("Invalid Option");
			m_choice = "0";
			return;
		}
	}

	if (!validChoice) {
		m_utility.DisplayError("Invalid Option!");
	}

}

double Store::CalculateTotal() {
	
	for (size_t i = 0; i < m_items.size(); i++) {
		m_totalPrice += m_itemPrices[i];
	}

	return m_totalPrice;
}

void Store::SetItems(string a_items[]) {

}

void Store::SetDate(string a_date) {
	m_date = a_date;
}

void Store::SetLocation(string a_location) {
	m_location = a_location;
}

void Store::SetPlayerMoney(double a_money) {
	m_playerMoney = a_money;
}

double Store::GetTotalPrice() {
	return m_totalPrice;
}
