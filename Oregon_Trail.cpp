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

		if (m_choice == "1") {
			AddToLeaderBoard();
		}
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

	// If title file doesn't exist, show a simple title instead
	if (!file) {
		cout << "Welcome to Oregon Trail" << endl << endl;
	}
	else {
		while (getline(file, input)) {

			cout << input;
			cout << endl;
		}
		cout << endl;
	}
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
	m_utility.OutputMessage("1. Travel the trail");
	m_utility.OutputMessage("2. Learn about the trail");
	m_utility.OutputMessage("3. See the Oregon Top Ten");
	m_utility.OutputMessage("4. End");
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

	cout << "\t What is your choice: ";
	cin >> m_choice;

	// Play the actual game
	if (m_choice == "1") {
		m_trailGame.ActiveGame();
	}
	// Show the description of what the game is about
	else if (m_choice == "2") {
		ShowDescription();
	}
	// Show the leaderboards
	else if (m_choice == "3") {
		ShowLeaderBoard();
	}
	// Exit out of the game
	else if (m_choice == "4") {
		exit(1);
	}
	else {
		m_utility.DisplayError("That was an incorrect option.");
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

	cout << endl;
	m_utility.OutputMessage("Try taking a journey by covered wagon across 2000");
	m_utility.OutputMessage("miles of plains, rivers, and mountains. Try!");
	m_utility.OutputMessage("On the plains, will you slosh your oxen through mud");
	m_utility.OutputMessage("and water - filled ruts or will you plod through");
	m_utility.OutputMessage("dust six inches deep?");
	cout << endl;
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

void Oregon_Trail::AddToLeaderBoard() {

	fstream outputLeaderboardFile("leaderboard.txt");
	string input;
	ifstream inputLeaderboardFile;
	string word;
	string tempName;
	int count = -1;
	int structCount = 0;
	string name;
	LeaderBoardEntry gameScore;

	// If there is no leaderboard file after finishing a game, this will initialize it
	if (!outputLeaderboardFile) {
		outputLeaderboardFile.open("leaderboard.txt", fstream::out);

		outputLeaderboardFile << "\t" << "Leaderboard" << endl;
		for (int i = 0; i < 10; i++) {
			outputLeaderboardFile << "\t" << i + 1 << "." << endl;
		}
	}

	outputLeaderboardFile.close();


	// ***** Reading from leaderboards file *****
	inputLeaderboardFile.open("leaderboard.txt");

	// While we are not at the end of file...
	while (inputLeaderboardFile >> word) {

		count++;
		// If there are players in the leaderboard, this will pull the names and scores from
		// the leaderboards.txt file and save them to a vector
		if (count % 3 == 0 && count != 0 && !IsPosition(word)) {
			m_entries.push_back(LeaderBoardEntry());
			m_entries[structCount].name = tempName;
			m_entries[structCount].score = stoi(word);
			structCount++;
		}

		tempName = word;
	}

	gameScore.score = m_trailGame.GetTotalScore();

	// Cycle through leaderboard scores and if the player's is higher, insert it into the leaderboard
	for (size_t i = 0; i < m_entries.size(); i++) {
		if (m_trailGame.GetTotalScore() > m_entries[i].score) {

			cout << "\t Enter your name: ";
			cin >> name;
			gameScore.name = name;
			m_entries.insert(m_entries.begin() + i, gameScore);
			break;
		}
	}

	inputLeaderboardFile.close();

	// ***** Opening the leaderboards file to overwrite with the new leaderboards high scores *****
	outputLeaderboardFile.open("leaderboard.txt", fstream::out);

	outputLeaderboardFile << "\t" << "Leaderboard" << endl;
	// Only outputting the top ten players to be saved
	for (int i = 0; i < 10; i++) {

		if (m_utility.HasElement(m_entries.size(), i)) {
			outputLeaderboardFile << "\t" << i + 1 << ". " << m_entries[i].name << " " << m_entries[i].score << endl;
		}
		else {
			outputLeaderboardFile << "\t" << i + 1 << "." << endl;
		}
	}

	outputLeaderboardFile.close();

	m_utility.Wait();

}

bool Oregon_Trail::IsPosition(string a_word) {

	if (a_word == "10." || a_word == "9." || a_word == "8." || a_word == "7." || a_word == "6." || a_word == "5." ||
		a_word == "4." || a_word == "3." || a_word == "2." || a_word == "1.") {
		return true;
	}
	else {
		return false;
	}
}