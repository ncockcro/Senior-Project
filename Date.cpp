#include "Date.h"

/*
	Date::Date()

NAME

	Date::Date - Default constructor

SYNOPSIS

	Date::Date()

DESCRIPTION

	Default constructor for intializing Date values.

AUTHOR

	Nicholas Cockcroft

Date

	9:18pm 2/6/2019
*/
Date::Date()
{
	m_month = "NULL";
	m_day = 0;
	m_year = 0;
	m_weather = 0;
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

/*
	Date::NextDay()

NAME

	Date::NextDay - Increments the in game date by a day

SYNOPSIS

	void Date::NextDay()

DESCRIPTION

	Takes in the year, month, and day as function parameters and will increment the date by one day. If it is
	December 31, it will increment the year and set it to be January 1. If it is the last day in a month,
	then it will increment the month and start the day at 1. Otherwise, it will just increment the day.

AUTHOR

	Nicholas Cockcroft

Date

	10:08am 1/26/2019
*/
void Date::NextDay() {

	int monthNum = ConvertMonth(m_month);

	// If the next day is going to be a new year...
	if (monthNum == 12 && m_day == m_lastDays[monthNum - 1]) {
		m_year++;
		m_month = "January";
		m_day = 1;
	}
	// If it is the last day of the month...
	else if (m_day == m_lastDays[monthNum - 1]) {
		monthNum++;
		m_month = ConvertMonth(monthNum);
		m_day = 1;
	}
	// Otherwise, just increase the current day they are on
	else {
		m_day++;
	}

	CheckAndChangeWeather();
}

/*
	Date:ConvertMonth(string a_month)

NAME

	Date::ConvertMonth - Converts the string of a month to an int

SYNOPSIS

	int Date::ConvertMonth(string a_month)

	a_month  --> string version of a month

DESCRIPTION

	Takes in the string of a month and converts it to its integer counterpart.

RETURNS

	Int

AUTHOR

	Nicholas Cockcroft

Date

	10:18pm 1/26/2019
*/
int Date::ConvertMonth(string a_month) {

	if (a_month == "January") {
		return 1;
	}
	else if (a_month == "February") {
		return 2;
	}
	else if (a_month == "March") {
		return 3;
	}
	else if (a_month == "April") {
		return 4;
	}
	else if (a_month == "May") {
		return 5;
	}
	else if (a_month == "June") {
		return 6;
	}
	else if (a_month == "July") {
		return 7;
	}
	else if (a_month == "August") {
		return 8;
	}
	else if (a_month == "September") {
		return 9;
	}
	else if (a_month == "October") {
		return 10;
	}
	else if (a_month == "November") {
		return 11;
	}
	else if (a_month == "December") {
		return 12;
	}
	else {
		m_utility.DisplayError("Error: Was not a proper month in utility class.");
		return -1;
	}
}

/*
	Date::ConvertMonth(int a_month)

NAME

	Date::ConvertMonth - Converts the number of a month to a string

SYNOPSIS

	string Date::ConvertMonth(int a_month)

	a_month  --> integer version of a month

DESCRIPTION

	Overloaded function for converting an integer month to a string counterpart.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	10:23pm 1/26/2019
*/
string Date::ConvertMonth(int a_month) {

	if (a_month == 1) {
		return "January";
	}
	else if (a_month == 2) {
		return "February";
	}
	else if (a_month == 3) {
		return "March";
	}
	else if (a_month == 4) {
		return "April";
	}
	else if (a_month == 5) {
		return "May";
	}
	else if (a_month == 6) {
		return "June";
	}
	else if (a_month == 7) {
		return "July";
	}
	else if (a_month == 8) {
		return "August";
	}
	else if (a_month == 9) {
		return "September";
	}
	else if (a_month == 10) {
		return "October";
	}
	else if (a_month == 11) {
		return "November";
	}
	else if (a_month == 12) {
		return "December";
	}
	else {
		m_utility.DisplayError("ERROR: Invalid month given for conversion in utility class.");
		return "NULL";
	}
}

/*
	Date::GetYear()

NAME

	Date::GetYear - Retrieves the year

SYNOPSIS

	int Date::GetYear()

DESCRIPTION

	This function will return the year of a Date object.

RETURNS

	Int

AUTHOR

	Nicholas Cockcroft

Date

	9:20pm 2/6/2019
*/
int Date::GetYear() {
	return m_year;
}

/*
	Date::SetYear(int a_year)

NAME

	Date::SetYear - Sets the year of a Date object

SYNOPSIS

	void Date::NextDay(int a_year)

	a_year  --> the year in game

DESCRIPTION

	Takes in the year and sets it to the member variable of the Date object.

AUTHOR

	Nicholas Cockcroft

Date

	9:24pm 2/6/2019
*/
void Date::SetYear(int a_year) {
	m_year = a_year;
}

/*
	Date::GetMonth()

NAME

	Date::GetMonth - Retrieves the month of a Date object

SYNOPSIS

	String Date::GetMonth()

DESCRIPTION

	Returns the month of a Date object.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	9:25pm 2/6/2019
*/
string Date::GetMonth() {
	return m_month;
}

/*
	Date::SetMonth(string a_month)

NAME

	Date::SetMonth - Sets the month of a Date object

SYNOPSIS

	void Date::SetMonth(string a_month)

	a_month --> the month in game

DESCRIPTION

	Takes in the month and sets it to the member function of the Date object.

AUTHOR

	Nicholas Cockcroft

Date

	9:33pm 2/6/2019
*/
void Date::SetMonth(string a_month) {
	m_month = a_month;
	CheckAndChangeWeather();
}

/*
	Date::GetDay()

NAME

	Date::GetDay - Returns the day of a Date object

SYNOPSIS

	void Date::GetDay()

DESCRIPTION

	Returns the day of a Date object.

RETURNS

	Int

AUTHOR

	Nicholas Cockcroft

Date

	9:39pm 2/6/2019
*/
int Date::GetDay() {
	return m_day;
}

/*
	Date::SetDay(int a_day)

NAME

	Date::SetDay - Sets the day to what was passed in

SYNOPSIS

	void Date::SetDay(int a_day)

	a_day --> the day in game

DESCRIPTION

	Takes in the day and sets the member variable to what was passed in for a Date object.

AUTHOR

	Nicholas Cockcroft

Date

	9:41pm 2/6/2019
*/
void Date::SetDay(int a_day) {
	m_day = a_day;
}

/*
	Date::ShowLocation(string a_location)

NAME

	Date::ShowLocation - Shows the location and date splash screen

SYNOPSIS

	void Date::ShowLocation(string a_location)

	a_location --> location the player is in

DESCRIPTION

	Outputs the splash screen of showing the location the player is in and the date

AUTHOR

	Nicholas Cockcroft

Date

	10:29pm 1/26/2019
*/
void Date::ShowLocation(string a_location) {

	SetConsoleTextAttribute(m_hConsole, 2);
	cout << "-----------------------------------------------" << endl;
	cout << "\t \t " << a_location << endl;
	cout << "\t \t " << m_month << " " << m_day << ", " << m_year << endl;

	cout << "-----------------------------------------------" << endl << endl;

	m_utility.Wait();
	SetConsoleTextAttribute(m_hConsole, 7);
}

/*
	Date::ShowDate()

NAME

	Date::ShowDate - Shows the date

SYNOPSIS

	Date::ShowDate()

DESCRIPTION

	Outputs the splash screen of showing the date.

AUTHOR

	Nicholas Cockcroft

Date

	10:29pm 1/26/2019
*/
void Date::ShowDate() {

	cout << "-----------------------------------------------" << endl;
	cout << "\t \t " << m_month << " " << m_day << ", " << m_year << endl;
	cout << "-----------------------------------------------" << endl << endl;
}

/*
	Date::GetWeather()

NAME

	Date::GetWeather - returns the weather

SYNOPSIS

	int Date::GetWeather()

DESCRIPTION

	Returns the value of the weather.

RETURNS

	Int

AUTHOR

	Nicholas Cockcroft

Date

	8:37am 3/11/2019
*/
int Date::GetWeather() {
	return m_weather;
}

/*
	Date::CheckAndChangeWeather()

NAME

	Date::CheckAndChangeWeather -  Adjusts weather based on season

SYNOPSIS

	void Date::CheckAndChangeWeather()

DESCRIPTION

	Checks which month range the current month is in and changes the weather type depending
	on which season of the year the game is in.

AUTHOR

	Nicholas Cockcroft

Date

	8:49am 3/11/2019
*/
void Date::CheckAndChangeWeather() {

	// Cold
	if (ConvertMonth(m_month) == 12 || ConvertMonth(m_month) < 4) {
		m_weather = 0;
	}
	// cool
	else if (ConvertMonth(m_month) < 5) {
		m_weather = 1;
	}
	// mild
	else if (ConvertMonth(m_month) < 6) {
		m_weather = 2;
	}
	// warm
	else if (ConvertMonth(m_month) < 7) {
		m_weather = 3;
	}
	// hot
	else if (ConvertMonth(m_month) < 9) {
		m_weather = 4;
	}
	// warm
	else if (ConvertMonth(m_month) < 10) {
		m_weather = 3;
	}
	// cool
	else if (ConvertMonth(m_month) < 11) {
		m_weather = 1;
	}
}