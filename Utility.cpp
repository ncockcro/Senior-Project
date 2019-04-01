#include "Utility.h"

/*
	Utility:Utility()

NAME

	Utility::Utility - Default constructor

SYNOPSIS

	Utility::Utility()

DESCRIPTION

	Default constructor for the Utility class.

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	10:28pm 2/6/2019
*/
Utility::Utility() {
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

/*
	Utility:DisplayError(string a_error)

NAME

	Utility::DisplayError - Overloaded constructor

SYNOPSIS

	void Utility::DisplayError(string a_error)

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

	void Utility::Wait()

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

	bool Utility::IsDigits(string &a_input)

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

	void Utility::OutputMessage(string a_message)

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
	Utility:HasElement(int a_vectorSize, int a_element)

NAME

	Utility::HasElement - Checks if a vector has the element passed in

SYNOPSIS

	bool Utility::HasElement(int a_vectorSize, int a_element)

	a_vectorSize --> size of a vector
	a_element --> the element to be checked

DESCRIPTION

	This function checks if a specific element is in a vector. It will return true if it is, otherwise, false.

RETURNS

	Bool

AUTHOR

	Nicholas Cockcroft

Date

	3:14pm 3/3/2019
*/
bool Utility::HasElement(int a_vectorSize, int a_element) {

	if (a_element < a_vectorSize) {
		return true;
	}
	else {
		return false;
	}
}

/*
	Utility:CheckInput(string a_input)

NAME

	Utility::CheckInput - Checks if input is all numbers or not

SYNOPSIS

	bool Utility::CheckInput(string a_input)

	a_input  --> input from the user

DESCRIPTION

	This function will take in user input as an argument and check if all of the characters are numbers.
	If they are, this function will return true, otherwise, false.

RETURNS

	Bool

AUTHOR

	Nicholas Cockcroft

Date

	3:22pm 3/3/2019
*/
bool Utility::CheckInput(string a_input) {

	// Cycle through the string passed in and return false if any of the
	// characters are not a number
	for (size_t i = 0; i < a_input.size(); i++) {
		if (!isdigit(a_input[i])) {
			return false;
		}
	}

	return true;
}

/*
	Utility:GetWeatherName(int a_weather)

NAME

	Utility::GetWeatherName - Default constructor

SYNOPSIS

	string Utility::GetWeatherName(int a_weather)

	a_weather  --> the current weather in the trail

DESCRIPTION

	Takes in the integer value of the weather and returns the string equivalent of it.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	10:40pm 2/6/2019
*/
string Utility::GetWeatherName(int a_weather) {

	if (a_weather == 4) {
		return "Hot";
	}
	else if (a_weather == 3) {
		return "Warm";
	}
	else if (a_weather == 2) {
		return "Mild";
	}
	else if (a_weather == 1) {
		return "Cool";
	}
	else if (a_weather == 0) {
		return "Cold";
	}
	else {
		DisplayError("Error: Could not determine weather.");
		return "NULL";
	}
}

/*
	Utility:GetHealthName(int a_health)

NAME

	Utility::GetHealthName - Returns the string name of the player's health

SYNOPSIS

	string Utility::GetHealthName(int a_health)

	a_health  --> the int version of the player's health

DESCRIPTION

	This function takes in the integer version of the player's health and returns the actual name
	of the player's current health.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	3:26pm 3/3/2019
*/
string Utility::GetHealthName(int a_health) {

	if (a_health == 3) {
		return "Good";
	}
	else if (a_health == 2) {
		return "Fair";
	}
	else if (a_health == 1) {
		return "Poor";
	}
	else if (a_health == 0) {
		return "Very Poor";
	}
	else {
		DisplayError("Error: Could not determine health.");
		return "NULL";
	}
}

void Utility::BlueText(string a_text) {

	SetConsoleTextAttribute(m_hConsole, 11);
	cout << "\t " << a_text << endl;
	SetConsoleTextAttribute(m_hConsole, 7);

}

string Utility::GetExtraPartSimpleName(string a_partName) {

	if (a_partName == "Spare parts - wagon wheel") {
		return "wagon wheel";
	}
	else if (a_partName == "Spare parts - wagon axle") {
		return "wagon axle";
	}
	else if (a_partName == "Spare parts - wagon tongue") {
		return "wagon tongue";
	}
	else {
		cerr << "ERROR: Unknown wagon part in utility class." << endl;
		return "NULL";
	}
}

string Utility::toStringWithPrecision(const double a_value, const int n) {

	ostringstream out;
	out.precision(n);
	out << fixed << a_value;
	return out.str();
}

string Utility::LowerCaseString(string a_string) { 

	string lowerCaseString;

	for (size_t i = 0; i < a_string.size(); i++) {
		lowerCaseString += tolower(a_string[i]);
	}

	return lowerCaseString;
}

void Utility::SaveAndUpdateLevel(int &a_level, int &a_playerXP, int a_locationsVisited) {

	int increaseScore;

	// Increment the player's xp
	increaseScore = (100 * (a_locationsVisited + 1));
	a_playerXP += increaseScore;

	// Output amount of xp the player earned and if they leveled up
	OutputWithColor("You gained " + to_string(increaseScore) + " points.", 15);
	CheckForLevelUp(a_level, a_playerXP);
	cout << endl;


	// Save the players level and xp to the level.txt
	fstream playerLevelFile;

	playerLevelFile.open("level.txt", fstream::out);

	playerLevelFile << "\t Level: " << a_level << endl << endl;
	playerLevelFile << "\t XP: " << a_playerXP << endl;

	playerLevelFile.close();
}

void Utility::CheckForLevelUp(int &a_level, int a_playerXP) {
	
	int currentLevel = a_level;

	if (a_playerXP >= 10000000) {
		a_level = 10;
	}
	else if (a_playerXP >= 5000000) {
		a_level = 9;
	}
	else if (a_playerXP >= 2500000) {
		a_level = 8;
	}
	else if (a_playerXP >= 1000000) {
		a_level = 7;
	}
	else if (a_playerXP >= 500000) {
		a_level = 6;
	}
	else if (a_playerXP >= 250000) {
		a_level = 5;
	}
	else if (a_playerXP >= 100000) {
		a_level = 4;
	}
	else if (a_playerXP >= 35000) {
		a_level = 3;
	}
	else if (a_playerXP >= 10000) {
		a_level = 2;
	}
	else {
		a_level = 1;
	}

	// If the player leveled up, output it to the screen
	if (currentLevel != a_level) {
		OutputWithColor("Congratulations, you are now level " + to_string(a_level) + ".", 14);
	}
}

void Utility::OutputWithColor(string a_text, int a_color, bool a_tab, bool a_endl) {

	if (a_tab && !a_endl) {
		SetConsoleTextAttribute(m_hConsole, a_color);
		cout << a_text << endl;
		SetConsoleTextAttribute(m_hConsole, 7);
	}
	else if (a_tab && a_endl) {
		SetConsoleTextAttribute(m_hConsole, a_color);
		cout << a_text;
		SetConsoleTextAttribute(m_hConsole, 7);
	}
	else if (!a_tab && a_endl) {
		SetConsoleTextAttribute(m_hConsole, a_color);
		cout << "\t " << a_text;
		SetConsoleTextAttribute(m_hConsole, 7);
	}
	else {
		SetConsoleTextAttribute(m_hConsole, a_color);
		cout << "\t " << a_text << endl;
		SetConsoleTextAttribute(m_hConsole, 7);
	}
}