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

	cout << "\t Many kinds of people made the trip to Oregon." << endl;
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
			cout << endl << "\t The position that you choose for your journey will dictate the amount of money you start with and " << endl;
			cout << "\t the amount of experience points you will recieve throughout the playthrough. The banker starts with " << endl;
			cout << "\t $1600, the carpenter with $800, and the farmer with $400." << endl << endl;
		}
		else {
			error.DisplayError("\t That is an incorrect option.");
		}
	}

	if (positionChoice == "1") {
		playerMoney = 1600;
		playerPosition = "Banker";
	}
	else if (positionChoice == "2") {
		playerMoney = 800;
		playerPosition = "Carpenter";
	}
	else if (positionChoice == "3") {
		playerMoney = 400;
		playerPosition = "Farmer";
	}
	else {
		error.DisplayError("ERROR: Trail class did not know which position the player chose!");
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
		cin >> wagonLeader;

		cout << "\t What are the names of the four other members?" << endl;

		string temp;
		// Cycling through four times to get the names of the four other members of the wagon party
		for (int i = 0; i < 4; i++) {
			cout << "/t" << i + 1 << ". ";
			cin >> wagonParty[i];
		}

		cout << "\t Are these names correct? Verify with yes or no. ";
		cin >> verify;

		if (verify == "yes") {
			break;
		}
	}
}
