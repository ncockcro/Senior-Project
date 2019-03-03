#include "Player.h"

/*
	Player::Player()

NAME

	Player::Player - Default constructor

SYNOPSIS

	Player::Player

DESCRIPTION

	This function initializes the items for the player and seeds the random number generator

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:51pm 2/6/2019
*/
Player::Player()
{
	InitializePartyItems();
	srand((unsigned int)time(0));

	m_pace = "steady";
	m_foodRate = "filling";
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

/*
	Player::SetPlayerMoney(double a_money)

NAME

	Player::SetPlayerMoney - Sets the amount of money the player has

SYNOPSIS

	void Player::SetPlayerMoney(double a_money)

	a_money --> money the player should have

DESCRIPTION

	This function takes in a double which represents how much money the player should have and assigns it
	to the player.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:52pm 2/6/2019
*/
void Player::SetPlayerMoney(double a_money) {
	m_playerMoney = a_money;
}

/*
	Player::SetPlayerPosition(string a_position)

NAME

	Player::SetPlayerPosition - assigns the position of the player

SYNOPSIS

	void Player::SetPlayerPosition(string a_position)

	a_position --> the position the player is supposed to be

DESCRIPTION

	This function takes in the position of the player (banker, carpenter, or farmer) and assigns it to the
	player.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:55pm 2/6/2019
*/
void Player::SetPlayerPosition(string a_position) {
	m_playerPosition = a_position;
}

/*
	Player::SetItemQuantity

NAME

	Player::SetItemQuantity - Sets the quantity of an item

SYNOPSIS

	void Player::SetItemQuantity(string a_itemName, int a_quantity)

	a_itemName --> name of the item
	a_quantity --> amount of a specific item

DESCRIPTION

	This function takes in an item name and the quantity and will set that quantity to the item for the
	player.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:58pm 2/6/2019
*/
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

/*
	Player::GetItem(string a_itemName)

NAME

	Player::GetItem - Returns a copy of an item

SYNOPSIS

	void Player::GetItem(string a_itemName)

	a_itemName --> name of the item to be retrieved

DESCRIPTION

	This function takes in the name of an item and returns the item object.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	9:03pm 2/6/2019
*/
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
	else if (a_itemName == "Spare parts - wagon wheel") {
		return m_ExtraWheel;
	}
	else if (a_itemName == "Spare parts - wagon axle") {
		return m_ExtraAxle;
	}
	else if (a_itemName == "Spare parts - wagon tongue") {
		return m_ExtraTongue;
	}
	else {
		m_utility.DisplayError("ERROR: Uknown item name in player class in getting item quantity.");
		return m_Oxen;
	}
}

/*
	Player::GetPlayerMoney()

NAME

	Player::GetPlayerMoney - Returns the amount of money the player has

SYNOPSIS

	void Player::GetPlayerMoney()

DESCRIPTION

	This function returns the amount of money that player currently has.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	9:05pm 2/6/2019
*/
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

/*
	Player::DeductFood()

NAME

	Player::DeductFood - Decrements food for food object

SYNOPSIS

	void Player::DeductFood()

DESCRIPTION

	This function will deduct food from the player based on the rate of decrementing.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	1:49pm 3/3/2019
*/
void Player::DeductFood() {
	m_Food.DecrementFood(m_foodRate);
}

/*
	Player::LoseItems()

NAME

	Player::LoseItems - Randomly deducts items from the player

SYNOPSIS

	void Player::LoseItems()

DESCRIPTION

	This function will randomly generate a percentage between 1 and 50 percent and then deduct that by some of
	the items in the player's inventory. A new random number gets generate each time this function is called.

RETURNS

	Vector<Item>

AUTHOR

	Nicholas Cockcroft

Date

	2:10pm 2/06/2019
*/
vector<Item> Player::LoseItems() {

	// Generate a random number between 1 and 50
	int randomNum = (rand() % 50) + 1;
	int randomNumForItems = rand() % 3;
	double percentRandNum;
	int tempNumber;
	vector<Item> lostItems;

	GenerateItemRandNums();

	// Convert random number to a percentage
	percentRandNum = (double)randomNum / 100;

	// Amount being lost for "Oxen"
	if (randomNumForItems == m_Oxen.GetLoseItemNum()) {

		// If the percentage of Oxen being lost is greater than zero, use the percentage...
		if ((int)(m_Oxen.GetQuantity() * percentRandNum) > 0) {
			tempNumber = (int)(m_Oxen.GetQuantity() * percentRandNum);
			m_Oxen.SetQuantity(m_Oxen.GetQuantity() - (int)(m_Oxen.GetQuantity() * percentRandNum));
			//cout << "\t \t " << tempNumber << " oxen" << endl;
			lostItems.push_back(Item("Oxen", tempNumber));
		}
		// If the number of Oxen is greater than 0 but the percentage was too low, deduct 1 oxen
		else if(m_Oxen.GetQuantity() > 0) {
			m_Oxen.SetQuantity(m_Oxen.GetQuantity() - 1);
			tempNumber = 1;
			//cout << "\t \t " << tempNumber << " oxen" << endl;
			lostItems.push_back(Item("Oxen", tempNumber));
		}
	}

	randomNum = (rand() % 50) + 1;
	percentRandNum = (double)randomNum / 100;

	// Amount being lost for "Food"
	if (randomNumForItems == m_Food.GetLoseItemNum()) {
		if ((int)(m_Food.GetQuantity() * percentRandNum) > 0) {
			tempNumber = (int)(m_Food.GetQuantity() * percentRandNum);
			m_Food.SetQuantity(m_Food.GetQuantity() - (int)(m_Food.GetQuantity() * percentRandNum));
			//cout << "\t \t " << tempNumber << " pounds of food" << endl;
			lostItems.push_back(Item("Food", tempNumber));
		}
		else if (m_Food.GetQuantity() > 0) {
			m_Food.SetQuantity(m_Food.GetQuantity() - 1);
			tempNumber = 1;
			//cout << "\t \t " << tempNumber << " pounds of food" << endl;
			lostItems.push_back(Item("Food", tempNumber));
		}
	}

	randomNum = (rand() % 50) + 1;
	percentRandNum = (double)randomNum / 100;

	// Amount being lost for "Clothing"
	if (randomNumForItems == m_Clothing.GetLoseItemNum()) {
		if ((int)(m_Clothing.GetQuantity() * percentRandNum) > 0) {
			tempNumber = (int)(m_Clothing.GetQuantity() * percentRandNum);
			m_Clothing.SetQuantity(m_Clothing.GetQuantity() - (int)(m_Clothing.GetQuantity() * percentRandNum));
			//cout << "\t \t " << tempNumber << " sets of clothing" << endl;
			lostItems.push_back(Item("Clothing", tempNumber));
		}
		else if (m_Clothing.GetQuantity() > 0) {
			m_Clothing.SetQuantity(m_Clothing.GetQuantity() - 1);
			tempNumber = 1;
			//cout << "\t \t " << tempNumber << " sets of clothing" << endl;
			lostItems.push_back(Item("Clothing", tempNumber));
		}
	}

	randomNum = (rand() % 50) + 1;
	percentRandNum = (double)randomNum / 100;

	// Amount being lost for "Ammunition"
	if (randomNumForItems == m_Ammunition.GetLoseItemNum()) {
		if ((int)(m_Ammunition.GetQuantity() * percentRandNum) > 0) {
			tempNumber = (int)(m_Ammunition.GetQuantity() * percentRandNum);
			m_Ammunition.SetQuantity(m_Ammunition.GetQuantity() - (int)(m_Ammunition.GetQuantity() * percentRandNum));
			//cout << "\t \t " << tempNumber << " bullets" << endl;
			lostItems.push_back(Item("Ammuniton", tempNumber));
		}
		else if (m_Ammunition.GetQuantity() > 0) {
			m_Ammunition.SetQuantity(m_Ammunition.GetQuantity() - 1);
			tempNumber = 1;
			//cout << "\t \t " << tempNumber << " bullets" << endl;
			lostItems.push_back(Item("Ammunition", tempNumber));
		}
	}

	randomNum = (rand() % 50) + 1;
	percentRandNum = (double)randomNum / 100;

	// Losing 2 "Extra wheels"
	if (randomNumForItems == m_ExtraWheel.GetLoseItemNum() && randomNum > 25 && m_ExtraWheel.GetQuantity() >= 2) {
		m_ExtraWheel.SetQuantity(m_ExtraWheel.GetQuantity() - 2);
		//cout << "\t \t 2 wagon wheel" << endl;
		lostItems.push_back(Item("Spare parts - wagon wheel", 2));
	}
	// Losing 1 "Extra wheel"
	else if (randomNumForItems == m_ExtraWheel.GetLoseItemNum() && randomNum < 25 && m_ExtraWheel.GetQuantity() >= 1) {
		m_ExtraWheel.SetQuantity(m_ExtraWheel.GetQuantity() - 1);
		//cout << "\t \t 1 wagon wheel" << endl;
		lostItems.push_back(Item("Spare parts - wagon wheel", 1));
	}

	randomNum = (rand() % 50) + 1;
	percentRandNum = (double)randomNum / 100;

	// Losing 2 "Extra axles"
	if (randomNumForItems == m_ExtraAxle.GetLoseItemNum() && randomNum > 25 && m_ExtraAxle.GetQuantity() >= 2) {
		m_ExtraAxle.SetQuantity(m_ExtraAxle.GetQuantity() - 2);
		//cout << "\t \t 2 wagon axle" << endl;
		lostItems.push_back(Item("Spare parts - wagon axle", 2));
	}
	// Losing 1 "Extra Axle"
	else if (randomNumForItems == m_ExtraAxle.GetLoseItemNum() && randomNum < 25 && m_ExtraAxle.GetQuantity() >= 1) {
		m_ExtraAxle.SetQuantity(m_ExtraAxle.GetQuantity() - 1);
		//cout << "\t \t 1 wagon axle" << endl;
		lostItems.push_back(Item("Spare parts - wagon axle", 1));
	}

	randomNum = (rand() % 50) + 1;
	percentRandNum = (double)randomNum / 100;

	// Losing 2 "Extra Tongues"
	if (randomNumForItems == m_ExtraTongue.GetLoseItemNum() && randomNum > 25 && m_ExtraTongue.GetQuantity() >= 2) {
		m_ExtraTongue.SetQuantity(m_ExtraTongue.GetQuantity() - 2);
		//cout << "\t \t 2 wagon tongue" << endl;
		lostItems.push_back(Item("Spare parts - wagon tongue", 2));
	}
	// Losing 1 "Extra Tongue"
	else if (randomNumForItems == m_ExtraTongue.GetLoseItemNum() && randomNum < 25 && m_ExtraTongue.GetQuantity() >= 1) {
		m_ExtraTongue.SetQuantity(m_ExtraTongue.GetQuantity() - 1);
		//cout << "\t \t 1 wagon tongue" << endl;
		lostItems.push_back(Item("Spare parts - wagon tongue", 1));
	}

	return lostItems;
}

/*
	Player::GeneratItemRandNums()

NAME

	Player::GenerateItemRandNums - Randomly assigns a number to each item

SYNOPSIS

	void Player::GenerateItemRandNums()

DESCRIPTION

	This function will randomly generate a number between 0 and 2 and assign it to each of the items
	for a player object.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:47pm 2/06/2019
*/
void Player::GenerateItemRandNums() {

	int randNum = rand() % 3;
	m_Oxen.SetLoseItemNum(randNum);

	randNum = rand() % 3;
	m_Food.SetLoseItemNum(randNum);

	randNum = rand() % 3;
	m_Clothing.SetLoseItemNum(randNum);

	randNum = rand() % 3;
	m_Ammunition.SetLoseItemNum(randNum);

	randNum = rand() % 3;
	m_ExtraWheel.SetLoseItemNum(randNum);

	randNum = rand() % 3;
	m_ExtraAxle.SetLoseItemNum(randNum);

	randNum = rand() % 3;
	m_ExtraTongue.SetLoseItemNum(randNum);
}

/*
	Player::AddItemQuantity(string a_itemName, int a_quantity)

NAME

	Player::AddItemQuantity - Adds to the quantity of an item

SYNOPSIS

	void Player::AddItemQuantity(string a_itemName, int a_quantity)

	a_itemName --> name of an item
	a_quantity --> quanatity to be added to the item

DESCRIPTION

	This function will take in an item name and quantity and cycle through the list of items that exist
	in the game, once the item is found, it will add the quantity to the item.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	2:43pm 3/3/2019
*/
void Player::AddItemQuantity(string a_itemName, int a_quantity) {

	if (a_itemName == "Oxen") {
		m_Oxen.AddToQuantity(a_quantity);
	}
	else if (a_itemName == "Food") {
		m_Food.AddToQuantity(a_quantity);
	}
	else if (a_itemName == "Clothing") {
		m_Clothing.AddToQuantity(a_quantity);
	}
	else if (a_itemName == "Ammunition") {
		m_Ammunition.AddToQuantity(a_quantity);
	}
	else if (a_itemName == "Spare parts - wagon wheel") {
		m_ExtraWheel.AddToQuantity(a_quantity);
	}
	else if (a_itemName == "Spare parts - wagon axle") {
		m_ExtraAxle.AddToQuantity(a_quantity);
	}
	else if (a_itemName == "Spare parts - wagon tongue") {
		m_ExtraTongue.AddToQuantity(a_quantity);
	}
	else {
		m_utility.DisplayError("ERROR: Uknown item name in player class.");
	}
}

/*
	Player::GetPlayerPosition()

NAME

	Player::GetPlayerPosition - return the position the player chose

SYNOPSIS

	string Player::GetPlayerPosition()

DESCRIPTION

	This function will return the position the player chose at the beginning of the game. Either a
	banker, carpenter, or farmer.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	2:45pm 3/3/2019
*/
string Player::GetPlayerPosition() {

	return m_playerPosition;
}

/*
	Player::SetPace(string a_pace)

NAME

	Player::SetPace - Sets the pace to what was passed in

SYNOPSIS

	void Player::GetPace(string a_pace)

	a_pace --> the pace the player is moving at

DESCRIPTION

	This function will take in a string and set it to be the pace the player moves at.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	2:47pm 3/3/2019
*/
void Player::SetPace(string a_pace) {

	if (a_pace == "steady") {
		m_pace = a_pace;
	}
	else if (a_pace == "strenuous") {
		m_pace = a_pace;
	}
	else if (a_pace == "grueling") {
		m_pace = a_pace;
	}
	else {
		m_utility.DisplayError("ERROR: Invalid pace to move at in player class.");
	}
}

/*
	Player::GetPace()

NAME

	Player::GetPace - Returns the pace the player moves at

SYNOPSIS

	string Player::GetPace()

DESCRIPTION

	This function will return the pace the player moves at.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	2:50pm 3/3/2019
*/
string Player::GetPace() {
	return m_pace;
}

/*
	Player::SetFoodRate(string a_foodRate)

NAME

	Player::SetFoodRate - Sets the rate the player eats food to what was passed in

SYNOPSIS

	void Player::SetFoodRate(string a_foodRate)

	a_foodRate --> rate the player eats food

DESCRIPTION

	This function will take in a string which represents the rate the player eats food and sets it
	to the member variable.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	2:54pm 3/3/2019
*/
void Player::SetFoodRate(string a_foodRate) {

	if (a_foodRate == "filling") {
		m_foodRate = a_foodRate;
	}
	else if (a_foodRate == "meager") {
		m_foodRate = a_foodRate;
	}
	else if (a_foodRate == "bare bones") {
		m_foodRate = a_foodRate;
	}
	else {
		m_utility.DisplayError("ERROR: invalid rate of food depletion in player class.");
	}
}

/*
	Player::GetFoodRate()

NAME

	Player::GetFoodRate - Returns the rate the player eats food

SYNOPSIS

	string Player::GetFoodRate()

DESCRIPTION

	This function will return the rate the player eats food

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	2:55pm 3/3/2019
*/
string Player::GetFoodRate() {
	return m_foodRate;
}