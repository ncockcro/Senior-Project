#include "Utility.h"

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

	None

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

void Utility::Wait() {

	cout << "Press enter to continue...";
	_getch();
	cout << endl;
}

bool Utility::IsDigits(string &a_input) {
	return all_of(a_input.begin(), a_input.end(), ::isdigit);
}

void Utility::OutputMessage(string a_message) {
	cout << "\t " << a_message << endl;
}