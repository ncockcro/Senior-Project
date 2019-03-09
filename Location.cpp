#include "Location.h"

/*
	Location:Location()

NAME

	Location::Location - Default constructor

SYNOPSIS

	Location::Location

DESCRIPTION

	Default constructor for the location class and sets default values for some of the member variables.

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	8:07pm 1/30/2019
*/
Location::Location()
{
	m_name = "NULL";
	m_milesNeeded = 0;
	m_hasStore = true;
}

/*
	Location:CrossLocation(Player &a_player, Date &a_date, int a_weather)

NAME

	Location::CrossLocation - virtual function used by the classes inherited from "Location"

SYNOPSIS

	Location::CrossLocation(Player &a_player, Date &a_date, int a_weather)

	a_player --> player object from main trail game
	a_date --> date object from main trail game
	a_weather --> current weather in the game

DESCRIPTION

	This is a virtual function which is primarily used for the class "River" that is inherited from this
	class. 

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	1:16pm 3/3/2019
*/
void Location::CrossLocation(Player &a_player, Date &a_date) {

}

/*
	Location::SetName(string a_name)

NAME

	Location::SetName - Sets the name of a location

SYNOPSIS

	void Location::SetName(string a_name)

	a_name --> the name of a location

DESCRIPTION

	Sets the name of a location to what was passed in

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:16pm 1/30/2019
*/
void Location::SetName(string a_name) {
	m_name = a_name;
}

/*
	Location::SetName(string a_name)

NAME

	Location::SetName - Sets the name of a location

SYNOPSIS

	void Location::SetName(string a_name)

	a_name --> the name of a location

DESCRIPTION

	Sets the name of a location to what was passed in

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:16pm 1/30/2019
*/
string Location::GetName() {
	return m_name;
}

/*
	Location::SetMilesNeeded(string a_miles)

NAME

	Location::SetMilesNeeded - Sets the amount of miles needed to get to a location

SYNOPSIS

	void Location::SetMilesNeeded(string a_miles)

	a_miles --> the amount of miles as an int

DESCRIPTION

	Sets the amount of miles needed to travel to a location.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:01pm 1/30/2019
*/
void Location::SetMilesNeeded(int a_miles) {
	m_milesNeeded = a_miles;
}

/*
	Location::GetMilesNeeded()

NAME

	Location::GetMilesNeeded - Returns the miles of a location

SYNOPSIS

	void Location::GetMilesNeeded()

DESCRIPTION

	Returns the amount of miles needed to travel to a location.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:05pm 1/30/2019
*/
int Location::GetMilesNeeded() {
	return m_milesNeeded;
}

/*
	Location::SetHasStore(bool a_has)

NAME

	Location::SetHasStore - Sets if a location has a store or not

SYNOPSIS

	void Location::SetHasStore(bool a_has)

	a_has --> true if there is a store, false otherwise

DESCRIPTION

	Sets the boolean value that represents if a location has a store or not.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	9:50pm 2/6/2019
*/
void Location::SetHasStore(bool a_has) {
	m_hasStore = a_has;
}

/*
	Location::GetHasStore()

NAME

	Location::GetHasStore - Returns if a location has a store or not

SYNOPSIS

	void Location::GetHasStore()

DESCRIPTION

	Returns the boolean whether a location has a store or not.

RETURNS

	Bool

AUTHOR

	Nicholas Cockcroft

Date

	10:02pm 2/6/2019
*/
bool Location::GetHasStore() {
	return m_hasStore;
}