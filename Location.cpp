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
	m_hasStore = false;
}

void Location::CrossLocation(Player a_player, Date &a_date, int a_weather) {

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

void Location::SetHasStore(bool a_has) {
	m_hasStore = a_has;
}

bool Location::GetHasStore() {
	return m_hasStore;
}