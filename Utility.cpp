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

string Utility::GetWeatherName(int a_weather) {

	if (a_weather == 0) {
		return "cold";
	}
	else if (a_weather == 1) {
		return "cool";
	}
	else if (a_weather == 2) {
		return "mild";
	}
	else if (a_weather == 3) {
		return "warm";
	}
	else if (a_weather == 4) {
		return "hot";
	}
	else {
		DisplayError("ERROR: Unknown weather code.");
		return "NULL";
	}
}