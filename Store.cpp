#include "Store.h"



Store::Store()
{
	m_date = "December 31, 9999";
	m_location = "NULL, NULL";
	m_color = 12;
}


Store::~Store()
{
}

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
