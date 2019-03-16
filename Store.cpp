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
	m_month = "NULL";
	m_year = 9999;
	m_day = 31;
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
void Store::DisplayStore(vector<Item> a_items, Player a_player) {

	m_userItems = a_items;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string choice;

	while (m_utility.CheckInput(m_choice) && stoi(m_choice) != a_items.size() + 1) {

		// Printing the date and location of the store
		SetConsoleTextAttribute(hConsole, m_color);
		cout << "-----------------------------------------------" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\t        " << m_month << " " << m_day << ", " << m_year << endl;
		cout << "\t   " << m_location << endl;
		SetConsoleTextAttribute(hConsole, m_color);
		cout << "-----------------------------------------------" << endl;
		SetConsoleTextAttribute(hConsole, 7);

		// Printing out the items that are being sold in the store
		for (size_t i = 0; i < a_items.size(); i++) {
			cout << "\t " << i + 1 << ". " << left << setw(30) << a_items[i].GetName() << fixed << setprecision(2) << m_itemPrices[i] << endl;
		}
		cout << "\t " << a_items.size() + 1 << ". to leave the store." << endl;
		SetConsoleTextAttribute(hConsole, m_color);
		cout << "-----------------------------------------------" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\t \t Total bill: $" << CalculateTotal() << endl;

		cout << "\t \t Amount you have: $" << m_playerMoney << endl;

		// Have the user make a choice for what they want to do
		MakeChoice(a_player);
	}
}

/*
	Store::MakeChoice(Player a_player)

NAME

	Store::MakeChoice - Prompts the user for the amount of items they want to buy

SYNOPSIS

	Store::MakeChoice(Player a_player)

	a_player --> the player with all of their item quantitys

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
void Store::MakeChoice(Player a_player) {

	string amount;
	bool validChoice = false;

	cout << "Which item would you like to buy? ";
	cin >> m_choice;

	// Cycle through the list of items being sold to find which one the user selected...
	for (size_t i = 0; i < m_userItems.size(); i++) {
		// If the user chose a valid item, then show the description and prompt for how many they want to buy
		if (m_utility.CheckInput(m_choice) && (stoi(m_choice) - 1) == i) {
			cout << fixed << setprecision(2) << m_userItems[i].GetDescription() << endl;

			while (1) {
				cout << "How many would you like to buy? ";
				cin >> amount;

				if (!m_utility.CheckInput(amount)) {
					m_utility.DisplayError("Invalid input.");
					continue;
				}
					
				m_userItems[i].SetQuantity(stoi(amount));
				m_itemPrices[i] = stoi(amount) * m_userItems[i].GetPrice();

				// If the user tries to buy more of an item when they already have some in their inventory, this will
				// deny them
				if (a_player.GetItem(m_userItems[i].GetName()).GetQuantity() + stoi(amount) > m_userItems[i].GetCapNumber()) {
					m_utility.DisplayError("Your wagon does not support that many.");
				}
				// If the user tries to buy more than the limited amount...
				else if (stoi(amount) > m_userItems[i].GetCapNumber()) {
					m_utility.DisplayError(m_userItems[i].GetCapDescription());
				}
				// If the user tries to buy more of a product than the amount of money they have...
				else if (m_itemPrices[i] > m_playerMoney) {
					m_utility.DisplayError("You don't have enough money for that.");
				}
				else if (stoi(amount) < 0) {
					m_utility.DisplayError("You can not buy a negative amount.");
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
		if (m_utility.CheckInput(m_choice) && stoi(m_choice) == m_userItems.size() + 1) {

			// If the player doesn't have any oxen already...
			if (a_player.GetItem("Oxen").GetQuantity() == 0) {

				// Cycle through the list of items the player is buying and check if they bought any
				for (size_t i = 0; i < m_userItems.size(); i++) {

					// If the player didn't buy any, than tell the user that they need to buy oxen before
					// leaving
					if (m_userItems[i].GetName() == "Oxen" && m_userItems[i].GetQuantity() == 0) {
						cout << endl;
						m_utility.DisplayError("Don't forget, you'll need");
						m_utility.DisplayError("oxen to pull your wagon.");
						cout << endl;
						m_choice = "0";
						return;
					}
				}
			}
			validChoice = true;
		}

	}

	// If the user typed in a number other than the ones listed for items, this will output
	// an invalid option error
	if (!validChoice) {
		m_utility.DisplayError("Invalid Option!");
		m_choice = "0";
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

	m_totalPrice = 0.0;
	
	for (size_t i = 0; i < m_userItems.size(); i++) {
		m_totalPrice += m_itemPrices[i];
	}

	return m_totalPrice;
}

/*
	Store::SetDate(string a_date)

NAME

	Store::SetDate - Sets the date for the store

SYNOPSIS

	Store::CalculateTotal(string a_date)

	a_date --> the date that should be displayed at the store.

DESCRIPTION

	This function will take in a string which is the date of the store and will be displayed at the top when
	the store is outputted.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	9:42am 1/25/2019
*/
void Store::SetDate(int a_year, string a_month, int a_day) {

	if (a_year > 0 && a_day > 0) {
		m_year = a_year;
		m_day = a_day;
	}
	else {
		m_utility.DisplayError("ERROR: Year or day passed in was negative.");
	}
	m_month = a_month;
}

/*
	Store::SetLocation(string a_location)

NAME

	Store::SetLocation - Sets the location of a store object

SYNOPSIS

	Store::SetLocation(string a_location)

	a_location --> a string that represents the location of the store

DESCRIPTION

	This function will take in a string that represents the location of a store object and is displayed when
	the store gets outputted.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	9:45am 1/25/2019
*/
void Store::SetLocation(string a_location) {
	m_location = a_location;
}

/*
	Store::SetPlayerMoney(double a_money)

NAME

	Store::SetPlayerMoney - Sets player money for the store to what was passed in

SYNOPSIS

	Store::SetPlayerMoney(string a_money)

	a_money --> the player's current money that is passed in

DESCRIPTION

	This function will take the money the player currently has and store it in the store object
	to be displayed with the store.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	9:46am 1/25/2019
*/
void Store::SetPlayerMoney(double a_money) {
	m_playerMoney = a_money;
}

/*
	Store::GetTotalPrice()

NAME

	Store::GetTotalPrice - Returns the total price the player spent

SYNOPSIS

	Store::GetTotalPrice()

DESCRIPTION

	This function will retrieve the total price the player spent at the store and return it.

RETURNS

	Double

AUTHOR

	Nicholas Cockcroft

Date

	9:54am 1/25/2019
*/
double Store::GetTotalPrice() {
	return m_totalPrice;
}

/*
	Store::GetItemQuantitys()

NAME

	Store::GetItemQuantitys - Returns the quantities of the items bought

SYNOPSIS

	Store::GetItemQuantitys()

DESCRIPTION

	This function will return the vector of item quantitys of what the player purchased from the store object.

RETURNS

	Vector<Item>

AUTHOR

	Nicholas Cockcroft

Date

	9:55am 1/25/2019
*/
vector<Item> Store::GetItemQuantitys() {
	return m_userItems;
}