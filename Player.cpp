#include "Player.h"



Player::Player()
{
	InitializePartyItems();
}


Player::~Player()
{
}

/*
	Player::IntializePartyItems()

NAME

	Player::InitializePartyItems - Initialize the items in the player's inventory

SYNOPSIS

	void Player::InitializePartyItems

DESCRIPTION

	This function initializes the player's items by setting each item's name, description, default price, default
	cap price, and cap price description. This initializes all of the items in the game for the player.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:25pm 1/23/2019
*/
void Player::InitializePartyItems() {
	m_Oxen = Item("Oxen", 0.1, "\t There are 2 oxen in a yoke; \n \t I recommend at least 3 yoke. \n \t I charge $40 a yoke.",
		"You can not bring more than 9 oxen with you.", 9);
	m_Oxen.SetQuantity(0);

	m_Food = Item("Food", 0.1, "\t I recommend you take at \n \t least 200 pounds of food \n \t for each person in your \n \t "
		"family. I see that you have \n \t 5 people in all. You'll need \n \t flour, sugar, bacon,"
		"and \n \t coffee. My price is 20 \n \t cents a pound.",
		"Your wagon may only carry \n \t 2000 pounds of food.", 2000);
	m_Food.SetQuantity(0);

	m_Clothing = Item("Clothing", 0.1, "\t You'll need warm clothing in \n \t the mountains. I recommend \n \t taking at least \n \t "
		"2 sets of \n \t clothes per person. Each \n \t set is $10.00", "NULL", INT_MAX);
	m_Clothing.SetQuantity(0);

	m_Ammunition = Item("Ammunition", 0.1, "\t I sell amunition in boxes \n \t of 20 bullets. Each box \n \t costs $2.00.", "NULL", INT_MAX);
	m_Ammunition.SetQuantity(0);

	m_ExtraWheel = Item("Spare parts - wagon wheel", 0.1, "\t It's a good idea to have a \n \t few spare wheels for your \n \t wagon:",
		"Your wagon may only carry 3 \n \t wagon wheels.", 3);
	m_ExtraWheel.SetQuantity(0);

	m_ExtraAxle = Item("Spare parts - wagon axle", 0.1, "\t It's a good idea to have a \n \t few spare axles for your \n \t wagon:",
		"Your wagon may only carry 3 \n \t wagon axles.", 3);
	m_ExtraAxle.SetQuantity(0);

	m_ExtraTongue = Item("Spare parts - wagon tongue", 0.1, "\t It's a good idea to have a \n \t few spare tongues for your \n \t wagon:",
		"Your wagon may only carry 3 \n \t wagon tongues", 3);
	m_ExtraTongue.SetQuantity(0);
}

void Player::SetPlayerMoney(double a_money) {
	m_playerMoney = a_money;
}

void Player::SetPlayerPosition(string a_position) {
	m_playerPosition = a_position;
}

void Player::SetItemQuantity(string a_itemName, int a_quantity) {

	if (a_itemName == "Oxen") {
		m_Oxen.SetQuantity(a_quantity);
	}
	else if (a_itemName == "Food") {
		m_Food.SetQuantity(a_quantity);
	}
	else if (a_itemName == "Clothing") {
		m_Clothing.SetQuantity(a_quantity);
	}
	else if (a_itemName == "Ammunition") {
		m_Ammunition.SetQuantity(a_quantity);
	}
	else if (a_itemName == "Spare parts - wagon wheel") {
		m_ExtraWheel.SetQuantity(a_quantity);
	}
	else if (a_itemName == "Spare parts - wagon axle") {
		m_ExtraAxle.SetQuantity(a_quantity);
	}
	else if (a_itemName == "Spare parts - wagon tongue") {
		m_ExtraTongue.SetQuantity(a_quantity);
	}
	else {
		m_utility.DisplayError("ERROR: Uknown item name in player class.");
	}
}

Item Player::GetItem(string a_itemName) {
	
	if (a_itemName == "Oxen") {
		return m_Oxen;
	}
	else if (a_itemName == "Food") {
		return m_Food;
	}
	else if (a_itemName == "Clothing") {
		return m_Clothing;
	}
	else if (a_itemName == "Ammunition") {
		return m_Ammunition;
	}
	else if (a_itemName == "Spare parts - extra wheel") {
		return m_ExtraWheel;
	}
	else if (a_itemName == "Spare parts - extra axle") {
		return m_ExtraAxle;
	}
	else if (a_itemName == "Spare parts - extra tongue") {
		return m_ExtraTongue;
	}
	else {
		m_utility.DisplayError("ERROR: Uknown item name in player class in getting item quantity.");
		return m_Oxen;
	}
}

double Player::GetPlayerMoney() {
	return m_playerMoney;
}

/*
	Player::DeductMoney(double a_money)

NAME

	Player::DepartingStore - Deduct money that is passed in from the player's cash stack

SYNOPSIS

	void Player::DepartingStore(double a_money)

	a_money --> money to deduct

DESCRIPTION

	This function will deduct the amount of money passed in from the money the player has in a game of
	Oregon Trail.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:18pm 1/24/2019
*/
void Player::DeductMoney(double a_money) {

	// If the player's money subtracted with what was passed in was greater than 0, subtract the money
	if (m_playerMoney - a_money > 0) {
		m_playerMoney = m_playerMoney - a_money;
	}
	// Otherwise, report an error since there should never be subtracting of more money than the player has
	else {
		m_utility.DisplayError("ERROR: Tried to subtract more money than player had.");
	}
}

void Player::DeductFood(string a_rate) {
	m_Food.DecrementFood(a_rate);
}