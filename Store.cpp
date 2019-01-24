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

	m_userItems = a_items;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string choice;

	while (stoi(m_choice) != a_items.size() + 1) {

		// Printing the date and location of the store
		SetConsoleTextAttribute(hConsole, m_color);
		cout << "-----------------------------------------------" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\t        " << m_date << endl;
		cout << "\t   " << m_location << endl;
		SetConsoleTextAttribute(hConsole, m_color);
		cout << "-----------------------------------------------" << endl;
		SetConsoleTextAttribute(hConsole, 7);

		// Printing out the items that are being sold in the store
		for (size_t i = 0; i < a_items.size(); i++) {
			cout << "\t " << i + 1 << ". " << a_items[i].GetName() << "      " << fixed << setprecision(2) << m_itemPrices[i] << endl;
		}
		cout << "\t " << a_items.size() + 1 << ". to leave the store." << endl;
		SetConsoleTextAttribute(hConsole, m_color);
		cout << "-----------------------------------------------" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\t \t Total bill: $" << CalculateTotal() << endl;

		cout << "\t \t Amount you have: $" << m_playerMoney << endl;

		MakeChoice();
	}
}

/*
	Store::MakeChoice()

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

	// Cycle through the list of items being sold to find which one the user selected...
	for (size_t i = 0; i < m_userItems.size(); i++) {
		try {
			// If the user chose a valid item, then show the description and prompt for how many they want to buy
			if ((stoi(m_choice) - 1) == i) {
				cout << m_userItems[i].GetDescription() << endl;

				while (1) {
					cout << "How many would you like to buy? ";
					cin >> amount;

					m_userItems[i].SetQuantity(stoi(amount));
					m_itemPrices[i] = stoi(amount) * m_userItems[i].GetPrice();

					// If the user tries to buy more than the limited amount...
					if (stoi(amount) > m_userItems[i].GetCapNumber()) {
						m_utility.DisplayError(m_userItems[i].GetCapDescription());
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

			// If the user wanted to exit the store, this will set validChoice to true so it does not
			// trigger an invalid option error
			if (stoi(m_choice) == m_userItems.size() + 1) {
				validChoice = true;
			}
		}
		// If the user typed in something other then a number, this will catch the exception thrown by
		// stoi and display an invalid option error
		catch (exception e) {
			m_utility.DisplayError("Invalid Option");
			m_choice = "0";
			return;
		}
	}

	// If the user typed in a number other than the ones listed for items, this will output
	// an invalid option error
	if (!validChoice) {
		m_utility.DisplayError("Invalid Option!");
	}

}

/*
	Store::CalculateTotal()

NAME

	Store::CalculateTotal - Calculates the total cost of an item with the quantity

SYNOPSIS

	Store::CalculateTotal()

DESCRIPTION

	This function will take the cost of all of the items that the user has selected at the store
	and add them together to return the total price of everything the user is trying to buy.

RETURNS

	Double

AUTHOR

	Nicholas Cockcroft

Date

	6:31pm 1/22/2019
*/
double Store::CalculateTotal() {
	
	for (size_t i = 0; i < m_userItems.size(); i++) {
		m_totalPrice += m_itemPrices[i];
	}

	return m_totalPrice;
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

vector<Item> Store::GetItemQuantitys() {
	return m_userItems;
}