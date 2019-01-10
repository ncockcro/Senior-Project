#include "Trail.h"



Trail::Trail()
{
}


Trail::~Trail()
{
}

/*
Trail::ActiveGame()

NAME

	Oregon_Trail::ActiveGame - Plays through an active game of Oregon Trail

SYNOPSIS

	void Trail::ActiveGame()

DESCRIPTION

	This function handles the main playthrough of an active game from the start of prompting them for wagon party members
	to the end when they reach the end of the trail.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:30am 1/9/2019
*/
void Trail::ActiveGame() {

	PromptPosition();
	PromptCharacterNames();
	PromptStartingMonth();
	LeavingMessage();
}

/*
Trail::PromptPosition()

NAME

	Oregon_Trail::PromptPosition - Prompts the user for which position they want (difficulty)

SYNOPSIS

	void Trail::PromptPosition()

DESCRIPTION

	This function will prompt the user for which position they want to play as and save it so the appropriate amount of money
	will be applied to the player

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:10am 1/9/2019
*/
void Trail::PromptPosition() {
	
	string positionChoice;

	cout << endl << "\t Many kinds of people made the trip to Oregon." << endl;
	cout << "\t You may:" << endl;

	while (1) {

		cout << "\t 1. Be a banker from Boston" << endl;
		cout << "\t 2. Be a carpenter from Ohio" << endl;
		cout << "\t 3. Be a farmer from Illinois" << endl;
		cout << "\t 4. Find out the differences between these choices" << endl << endl;
		cout << "\t What is your choice? ";
		cin >> positionChoice;

		if (positionChoice == "1" || positionChoice == "2" || positionChoice == "3") {
			break;
		}
		else if (positionChoice == "4") {
			cout << endl << "\t Traveling to Oregon isn't easy! But if you're a banker, " << endl;
			cout << "\t you'll have more money for supplies than a carpenter or a farmer." << endl << endl;
			cout << "\t However, the harder you have to try, the more points you deserve!" << endl;
			cout << "\t Therefore, the farmer earns the greatest number of points " << endl;
			cout << "\t and the banker earns the least." << endl << endl;
		}
		else {
			m_error.DisplayError("\t That is an incorrect option.");
		}
	}

	if (positionChoice == "1") {
		m_playerMoney = 1600;
		m_playerPosition = "Banker";
	}
	else if (positionChoice == "2") {
		m_playerMoney = 800;
		m_playerPosition = "Carpenter";
	}
	else if (positionChoice == "3") {
		m_playerMoney = 400;
		m_playerPosition = "Farmer";
	}
	else {
		m_error.DisplayError("ERROR: Trail class did not know which position the player chose!");
	}
	
}

/*
Trail::PromptCharacterNames()

NAME

	Oregon_Trail::PromptCharacterNames - Prompts the user for the names of their characters

SYNOPSIS

	void Trail::PromptCharacterNames

DESCRIPTION

	This function will prompt the user for the names of their party and ask to confirm if those are correct.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	1:20pm 1/9/2019
*/
void Trail::PromptCharacterNames() {

	string verify;

	while (1) {
		cout << "\t What is the first name of the wagon leader? ";
		cin >> m_wagonLeader;

		cout << "\t What are the names of the four other members?" << endl;

		string temp;
		// Cycling through four times to get the names of the four other members of the wagon party
		for (int i = 0; i < 4; i++) {
			cout << "\t " << i + 1 << ". ";
			cin >> m_wagonParty[i];
		}

		cout << "\t Are these names correct? Verify with yes or no. ";
		cin >> verify;

		if (verify == "yes") {
			break;
		}
	}
}

// 10:07am
void Trail::PromptStartingMonth() {

	string choice;

	while (1) {
		cout << endl << "\t It is 1848. Your jumping off place for Oregon Independence, Missouri. You must " << endl;
		cout << "\t decide which month to leave Independence." << endl;
		cout << "\t 1. March" << endl;
		cout << "\t 2. April" << endl;
		cout << "\t 3. May" << endl;
		cout << "\t 4. June" << endl;
		cout << "\t 5. July" << endl;
		cout << "\t 6. Ask for advice" << endl << endl;
		cout << "\t What is your choice? ";
		cin >> choice;

		if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5") {
			break;
		}
		else if (choice == "6") {
			cout << endl << "\t You attend a public meeting held for \"folks with the California - Oregon fever.\"" << endl;
			cout << "\t You're told:" << endl << endl;
			cout << "\t If you leave too early, there won't be any grass for your oxen to eat. If you leave " << endl;
			cout << "\t too late, you may not get to Oregon before winter comes. If you " << endl;
			cout << "\t leave at just the right time, there will be green grass and the weather " << endl;
			cout << "\t will still be cool." << endl << endl;
		}
		else {
			m_error.DisplayError("Invalid option");
		}
	}

	if (choice == "1") {
		m_startingMonth = "March";
	}
	else if (choice == "2") {
		m_startingMonth = "April";
	}
	else if (choice == "3") {
		m_startingMonth = "May";
	}
	else if (choice == "4") {
		m_startingMonth == "June";
	}
	else if (choice == "5") {
		m_startingMonth == "July";
	}
	else {
		m_error.DisplayError("ERROR: Trail class doesn't know which month is starting!");
	}
}

void Trail::LeavingMessage() {
	cout << endl << "\t Before leaving Independence you should buy equipment and supplies." << endl;
	cout << "\t You have " << m_playerMoney << ".00 in cash, but you don't have to spend it all now" << endl << endl;
	cout << "\t ";
	system("pause");

	cout << endl << "\t How will you cross the rivers? If you have money, " << endl;
	cout << "\t you might take a ferry (if there is a ferry)." << endl;
	cout << "\t Or, you can ford the river and hope you and your" << endl;
	cout << "\t wagon aren't swallowed alive!" << endl << endl;
	cout << "\t ";
	system("pause");

	cout << endl << "\t What about supplies? Well, if" << endl;
	cout << "\t you're low on food you can hunt. You might get a buffalo..." << endl;
	cout << "\t you might. And there are bear in the mountains." << endl << endl;
	cout << "\t ";
	system("pause");

	cout << endl << "\t At the Dalles, you can try" << endl;
	cout << "\t navigating the Columbia River," << endl;
	cout << "\t but if running the rapids with" << endl;
	cout << "\t a makeshift raph makes you queasy," << endl;
	cout << "\t better take the Barlow Road." << endl << endl;
	cout << "\t ";
	system("pause");

	cout << endl << "\t If for some reason you don't" << endl;
	cout << "\t survive -- your wagon burns," << endl;
	cout << "\t or thieves steal your oxen, or" << endl;
	cout << "\t you run out of provisions, or" << endl;
	cout << "\t you die of cholera -- don't" << endl;
	cout << "\t give up! Try again... and again..." << endl;
	cout << "\t until your name is up with the others" << endl;
	cout << "\t on the Oregon Top Ten." << endl << endl;
	cout << "\t ";
	system("pause");

	cout << endl << "\t You can buy whatever you need at" << endl;
	cout << "Matt's General Store." << endl << endl;
	cout << "\t ";
	system("pause");

	cout << endl << "\t Hello I'm Matt. So you're going" << endl;
	cout << "\t to Oregon! I can fix you up with what you need:" << endl;
	cout << endl << "\t \t - a team of oxen to pull your wagon" << endl;
	cout << endl << "\t \t - clothing for both summer and winter" << endl;
	cout << endl << "\t \t - plenty of food for the trip" << endl;
	cout << endl << "\t \t - ammunition for your rifles" << endl;
	cout << endl << "\t \t - spare parts for your wagon" << endl;
	cout << "\t ";
	system("pause");
}