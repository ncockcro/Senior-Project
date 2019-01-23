#include "Oregon_Trail.h"

Oregon_Trail::Oregon_Trail()
{
}

/*
Oregon_Trail::StartGame()

NAME

	Oregon_Trail::StartGame - Runs the main game with a start menu and is the default process in between game sessions.

SYNOPSIS

	void Oregon_Trail::StartGame()

DESCRIPTION

	This function is the only function called by main and serves to be the main running of Oregon Trail. It will
	show a title which is saved to a local file, and run in an infinite loop to prompt the user with options for
	the game.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:24am 1/8/2019
*/
void Oregon_Trail::StartGame() {

	ShowTitle();

	while (1) {
		ShowChoices();
		PickDecision();
	}
}

/*
Oregon_Trail::ShowTitle()

NAME

	Oregon_Trail::ShowTitle - Shows a custom made title from an external txt file

SYNOPSIS

	void Oregon_Trail::ShowTitle()

DESCRIPTION

	This function is to open the "title.txt" file and output everything that is inside which is for the title of the game.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:10am 1/8/2019
*/
void Oregon_Trail::ShowTitle() {

	ifstream file;
	string input;
	file.open("title.txt");

	while (getline(file, input)) {

		cout << input;
		cout << endl;
	}
	cout << endl;
}

/*
	Oregon_Trail::ShowChoices()

NAME

	Oregon_Trail::ShowChoices - Show the available menu options to the player.

SYNOPSIS

	void Oregon_Trail::ShowChoices()

DESCRIPTION

	This function will output the several menu choices to the console.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:24am 1/8/2019
*/
void Oregon_Trail::ShowChoices() {
	cout << "     You may:" << endl;
	cout << "\t 1. Travel the trail" << endl;
	cout << "\t 2. Learn about the trail" << endl;
	cout << "\t 3. See the Oregon Top Ten" << endl;
	cout << "\t 4. End" << endl;
}

/*
Oregon_Trail::PickDecision()

NAME

	Oregon_Trail::PickDecision - Lets the user pick a decision from the start menu

SYNOPSIS

	void Oregon_Trail::PickDecision()

DESCRIPTION

	This function has the user enter in a decision for the start menu and will cycle through to find the choice that
	they picked. If they didn't pick one of the choices, then an error message will be outputted

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:48am 1/8/2019
*/
void Oregon_Trail::PickDecision() {

	string choice;

	cout << "\t What is your choice: ";
	cin >> choice;

	if (choice == "1") {
		m_trailGame.ActiveGame();
	}
	else if (choice == "2") {
		ShowDescription();
	}
	else if (choice == "3") {
		ShowLeaderBoard();
	}
	else if (choice == "4") {
		exit(1);
	}
	else {
		m_utility.DisplayError("\t That was an incorrect option.");
	}
}

/*
Oregon_Trail::ShowDescription()

NAME

	Oregon_Trail::ShowDescription - When the user wants to see the description for the game, this will output it

SYNOPSIS

	void Oregon_Trail::ShowDescription()

DESCRIPTION

	This function will show the description of the game when the user picks the choice from the main menu

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:24am 1/8/2019
*/
void Oregon_Trail::ShowDescription() {

	cout << endl << "\t Try taking a journey by covered wagon across 2000" << endl;
	cout << "\t miles of plains, rivers, and mountains. Try!" << endl;
	cout << "\t On the plains, will you slosh your oxen through mud" << endl;
	cout << "\t and water - filled ruts or will you plod through" << endl;
	cout << "\t dust six inches deep?" << endl << endl;
	cout << "\t ";
	m_utility.Wait();
}

/*
Oregon_Trail::ShowLeaderboard()

NAME

	Oregon_Trail::ShowLeaderboard - When the user wants to see the leaderboards for the game

SYNOPSIS

	void Oregon_Trail::ShowLeaderboard()

DESCRIPTION

	This function will show the leaderboards from a text file. If there is no text file, this function will initialize it, otherwise,
	it will be read from.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	9:45am 1/9/2019
*/
void Oregon_Trail::ShowLeaderBoard() {

	system("cls");

	fstream outputLeaderboardFile("leaderboard.txt");
	string input;

	// If there is no leaderboard file, this will initialize it
	if (!outputLeaderboardFile) {
		outputLeaderboardFile.open("leaderboard.txt", fstream::out);
		
		outputLeaderboardFile << "\t" << "Leaderboard" << endl;
		for (int i = 0; i < 10; i++) {
			outputLeaderboardFile << "\t" << i + 1 << "." << endl;
		}
	}

	// After the leaderboard file was  initialized or if it already existed, this will output
	// the contents of the file
	ifstream inputLeaderboardFile;
	inputLeaderboardFile.open("leaderboard.txt");
	while (getline(inputLeaderboardFile, input)) {
		cout << input << endl;
	}
	inputLeaderboardFile.close();

	outputLeaderboardFile.close();

	m_utility.Wait();
	system("cls");
}
