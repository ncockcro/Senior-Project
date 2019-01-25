#include "Item.h"

/*
	Item::Item()

NAME

	Item::Item - Default constructor

SYNOPSIS

	void Item::Item()

DESCRIPTION

	This function is the default constructor for Item class

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	1:40pm 1/14/2019
*/
Item::Item() {
	m_name = "NULL";
	m_price = 0.0;
	m_description = "NULL";
	m_capDescription = "NULL";
	m_capNumber = INT_MAX;
	m_quantity = 0;
}

/*
	Item::Item(string a_name, double a_price, string a_description)

NAME

	Item::Item - Overloaded constructor

SYNOPSIS

	void Item::Item(string a_name, double, a_price, string a_description)
		a_name        --> the name of an object
		a_price       --> the price of an object
		a_description --> the description of an object

DESCRIPTION

	This function will set the name of an item object.

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	2:15pm 1/14/2019
*/
Item::Item(string a_name, double a_price, string a_description, string a_capDescription, int a_capNumber) {

	try {
		m_name = a_name;
		m_description = a_description;
		m_capDescription = a_capDescription;
	}
	catch (exception e) {
		m_utility.DisplayError("ERROR: in setting name/description in item constructor class.");
	}

	if (a_price > 0.0) {
		m_price = a_price;
		m_capNumber = a_capNumber;
	}
	else {
		m_utility.DisplayError("ERROR: in setting price of item in item constructor.");
	}

	m_quantity = 0;
}

/*
	Item::GetName()

NAME

	Item::GetName - Get the name of an object

SYNOPSIS

	void Item::GetName()

DESCRIPTION

	This function will retrieve the name of an object.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	1:46pm 1/14/2019
*/
string Item::GetName() {
	return m_name;
}

/*
	Item::SetName(string a_name)

NAME

	Item::SetName - Set the name of an item object to what is passed in

SYNOPSIS

	void Item::SetName(string a_name)
		a_name      --> the name of an object

DESCRIPTION

	This function will set the name of an item object.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	1:50pm 1/14/2019
*/
void Item::SetName(string a_name) {
	try {
		m_name = a_name;
	}
	catch (exception e) {
		m_utility.DisplayError("ERROR: Could not set the name of an object in the item class.");
	}
}

/*
	Item::GetPrice()

NAME

	Item::GetPrice - Retrieve the price of an item

SYNOPSIS

	void Item::GetPrice()

DESCRIPTION

	This function will return the price of an item object

RETURNS

	Double

AUTHOR

	Nicholas Cockcroft

Date

	1:51pm 1/14/2019
*/
double Item::GetPrice() {
	return m_price;
}

/*
	Item::SetPrice(double a_price)

NAME

	Item::SetPrice - Set the price of an item object to what is passed in

SYNOPSIS

	void Item::SetPrice(string a_price)
		a_price      --> the price of an object

DESCRIPTION

	This function will set the price of an item object

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	1:52pm 1/14/2019
*/
void Item::SetPrice(double a_price) {

	// So long as the price is not negative nor 0, set the price
	if (a_price > 0.0) {
		m_price = a_price;
	}
	else {
		m_utility.DisplayError("ERROR: The price of the item was negative and could not be set in item class.");
	}
}

/*
	Item::GetDescription()

NAME

	Item::GetDescription - Get the description of an item object

SYNOPSIS

	void Item::GetDescription()

DESCRIPTION

	This function will retrieve the description of an item object.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	1:55pm 1/14/2019
*/
string Item::GetDescription() {
	return m_description;
}

/*
	Item::SetDescription(string a_description)

NAME

	Item::SetDescription - Set the description of an item object to what was passed in

SYNOPSIS

	void Item::SetDescription(string a_description)
		a_description      --> the description of an object

DESCRIPTION

	This function will set the description of an item object.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	1:57pm 1/14/2019
*/
void Item::SetDescription(string a_description) {
	try {
		m_description = a_description;
	}
	catch (exception e) {
		m_utility.DisplayError("ERROR: The description of an item could not be set in item class.");
	}
}

/*
	Item::GetDescription()

NAME

	Item::GetDescription - Get the description of an item

SYNOPSIS

	void Item::GetDescription()

DESCRIPTION

	This function retrieve the description of an item.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	10:00am 1/25/2019
*/
string Item::GetCapDescription() {
	return m_capDescription;
}

/*
	Item::SetDescription(string a_description)

NAME

	Item::SetDescription - Set the description of an item object to what was passed in

SYNOPSIS

	void Item::SetDescription(string a_description)
		a_description      --> the description of an object

DESCRIPTION

	This function will set the cap description of an item object. The cap description is in place if the player tries
	to buy too much of an item. For example, a player tries to buy 10 oxen but the cap is 9 oxen, then this cap
	description is going to be shown.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:03am 1/25/2019
*/
void Item::SetCapDescription(string a_capDescription) {
	try {
		m_capDescription = a_capDescription;
	}
	catch (exception e) {
		m_utility.DisplayError("ERROR: The cap description of an item could not be set in item class.");
	}
}

/*
	Item::GetCapNumber()

NAME

	Item::GetCapNumber - Get the cap number of an item object

SYNOPSIS

	void Item::GetCapNumber()

DESCRIPTION

	This function will retrieve the cap number of an item object. The cap number is the max amount of an item
	that a player can purchase. For example, if the user tries to buy 10 oxen but the store can only sell 9,
	the cap number of the item, Oxen, is 9.

RETURNS

	Int

AUTHOR

	Nicholas Cockcroft

Date

	10:11am 1/25/2019
*/
int Item::GetCapNumber() {
	return m_capNumber;
}

/*
	Item::SetCapNumber(int a_capNumber)

NAME

	Item::SetCapNumber - Sets the cap number of an item

SYNOPSIS

	void Item::SetCapNumber(int a_capNumber)
		a_capNumber      --> the number that an item caps out at

DESCRIPTION

	This function will set the cap number of an item. That is, the max amount of a particular item a place can buy

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:13am 1/25/2019
*/
void Item::SetCapNumber(int a_capNumber) {

	if (a_capNumber > 0) {
		m_capNumber = a_capNumber;
	}
	else {
		m_utility.DisplayError("ERROR: Cap number was below 0 in item class.");
	}
}

/*
	Item::GetQuantity()

NAME

	Item::GetQuantity - Retrieves the quantity of an item

SYNOPSIS

	void Item::GetQuantity()

DESCRIPTION

	This function will retrieve how much of an item there is.

RETURNS

	Int

AUTHOR

	Nicholas Cockcroft

Date

	10:15am 1/25/2019
*/
int Item::GetQuantity() {
	return m_quantity;
}

/*
	Item::SetQuantity(int a_quantity)

NAME

	Item::SetQuantity - Set the quantity of an item

SYNOPSIS

	void Item::SetQuantity(string a_quantity)
		a_quantity     --> the quantity of an item

DESCRIPTION

	This function will set the amount of an item that is passed in.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:16am 1/25/2019
*/
void Item::SetQuantity(int a_quantity) {
	m_quantity = a_quantity;
}

/*
	Item::AddToQuantity(int a_quantity)

NAME

	Item::AddToQuantity - Add to the quantity of an item

SYNOPSIS

	void Item::AddToQuantity(int a_quantity)
		a_quantity      --> the amount to be added to 

DESCRIPTION

	This function will set the description of an item object.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:24am 1/25/2019
*/
void Item::AddToQuantity(int a_quantity) {

	if (a_quantity > 0) {
		m_quantity += a_quantity;
	}
	else {
		m_utility.DisplayError("ERROR: Tried ading a negative/zero number to item quantity in item class.");
	}
}