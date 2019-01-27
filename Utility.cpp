#include "Utility.h"

Utility::Utility() {
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

/*
	Utility:DisplayError(string a_error)

NAME

	Utility::DisplayError - Default constructor

SYNOPSIS

	Utility::DisplayError(string a_error)

	a_error  --> the error that wants to be outputted

DESCRIPTION

	When an error needs to be thrown, this function will output the error message passed in

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	2:23pm 1/14/2019
*/
void Utility::DisplayError(string a_error) {

	SetConsoleTextAttribute(m_hConsole, 12);
	cout << "\t " << a_error << endl;
	SetConsoleTextAttribute(m_hConsole, 7);
}

/*
	Utility:Wait()

NAME

	Utility::Wait - Waits for the user to press a key

SYNOPSIS

	Utility::Wait()

DESCRIPTION

	When the user is reading a description or doing something in the application where they need time to think about what they
	want to do, this function is called to wait for the player to press a key to continue. This serves as a better option 
	compared to using System("pause") which is platform dependent.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:38am 1/25/2019
*/
void Utility::Wait() {

	cout << "\t Press any key to continue..." << endl;
	_getch();
	cout << endl;
}

/*
	Utility:IsDigits(string &a_input)

NAME

	Utility::IsDigits - Checks if a string is a number

SYNOPSIS

	Utility::IsDigits(string &a_input)

	a_input  --> a string to be checked if it is a number

DESCRIPTION

	When a string is passed in, this will return true if the string is a number, or false if the string is not
	a number

RETURNS

	Bool

AUTHOR

	Nicholas Cockcroft

Date

	10:39am 1/25/2019
*/
bool Utility::IsDigits(string &a_input) {
	return all_of(a_input.begin(), a_input.end(), ::isdigit);
}

/*
	Utility:OutputMessage(string a_message)

NAME

	Utility::OutputMessage - Outputs a specially formatted message with what was passed in

SYNOPSIS

	Utility::OutputMessage(string a_message)

	a_message  --> the message to be outputed

DESCRIPTION

	Outputs a specially formatted message with whatever was passed in to match the overall output of the application.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:43am 1/25/2019
*/
void Utility::OutputMessage(string a_message) {
	cout << "\t " << a_message << endl;
}

/*
	Utility:NextDay(int &a_year, string &a_month, int &a_day)

NAME

	Utility::NextDay - Increments the in game date by a day

SYNOPSIS

	Utility::NextDay(int &a_year, string &a_month, int &a_day)

	a_year  --> the year in game
	a_month --> the month in game
	a_day --> the day in game

DESCRIPTION

	Takes in the year, month, and day as function parameters and will increment the date by one day. If it is
	December 31, it will increment the year and set it to be January 1. If it is the last day in a month,
	then it will increment the month and start the day at 1. Otherwise, it will just increment the day.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:08am 1/26/2019
*/
void Utility::NextDay(int &a_year, string &a_month, int &a_day) {

	int monthNum = ConvertMonth(a_month);

	// If the next day is going to be a new year...
	if (monthNum == 12 && a_day == m_lastDays[monthNum - 1]) {
		a_year++;
		a_month = "January";
		a_day = 1;
	}
	// If it is the last day of the month...
	else if (a_day == m_lastDays[monthNum - 1]) {
		monthNum++;
		a_month = ConvertMonth(monthNum);
		a_day = 1;
	}
	// Otherwise, just increase the current day they are on
	else {
		a_day++;
	}
}

/*
	Utility:ConvertMonth(string a_month)

NAME

	Utility::ConvertMonth - Converts the string of a month to an int

SYNOPSIS

	Utility::ConvertMonth(string a_month)

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
int Utility::ConvertMonth(string a_month) {

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
		DisplayError("Error: Was not a proper month in utility class.");
		return -1;
	}
}

/*
	Utility:ConvertMonth(int a_month)

NAME

	Utility::ConvertMonth - Converts the number of a month to a string

SYNOPSIS

	Utility::ConvertMonth(int a_month)

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
string Utility::ConvertMonth(int a_month) {

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
		DisplayError("ERROR: Invalid month given for conversion in utility class.");
	}
}

/*
	Utility:ShowLocation(string a_location, a_year, a_month, a_day)

NAME

	Utility::ShowLocation - Shows the location and date splash screen

SYNOPSIS

	Utility::ShowLocation(string a_location, a_year, a_month, a_day)

	a_location --> location the player is in
	a_year --> the current year in game
	a_month --> the current month in game
	a_day --> the current day in game

DESCRIPTION

	Outputs the splash screen of showing the location the player is in and the date

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:29pm 1/26/2019
*/
void Utility::ShowLocation(string a_location, int a_year, string a_month, int a_day) {

	SetConsoleTextAttribute(m_hConsole, 2);
	cout << "-----------------------------------------------" << endl;
	cout << "\t \t " << a_location << endl;
	cout << "\t \t " << a_month << " " << a_day << ", " << a_year << endl;

	cout << "-----------------------------------------------" << endl << endl;

	Wait();
	SetConsoleTextAttribute(m_hConsole, 7);
}