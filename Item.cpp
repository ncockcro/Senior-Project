#include "Item.h"



Item::Item()
{
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
		error.DisplayError("ERROR: Could not set the name of an object in the item class.");
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
		error.DisplayError("ERROR: The price of the item was negative and could not be set in item class.");
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
		error.DisplayError("ERROR: The description of an item could not be set in item class.");
	}
}