#include "Utility.h"

Utility::Utility() {
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

/*
	Error:DisplayError(string a_error)

NAME

	Error::DisplayError - Default constructor

SYNOPSIS

	Error::DisplayError(string a_error)

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
	Error:Wait()

NAME

	Error::Wait - Waits for the user to press a key

SYNOPSIS

	Error::Wait()

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

	cout << "Press any key to continue...";
	_getch();
	cout << endl;
}

/*
	Error:IsDigits(string &a_input)

NAME

	Error::IsDigits - Checks if a string is a number

SYNOPSIS

	Error::IsDigits(string &a_input)

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
	Error:OutputMessage(string a_message)

NAME

	Error::OutputMessage - Outputs a specially formatted message with what was passed in

SYNOPSIS

	Error::OutputMessage(string a_message)

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