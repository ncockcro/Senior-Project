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
	DepartingStore();
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
			m_utility.DisplayError("That is an incorrect option.");
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
		m_utility.DisplayError("ERROR: Trail class did not know which position the player chose!");
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

/*
Trail::PromptStartingMonth()

NAME

	Oregon_Trail::PromptStartingMonth - Prompts the user for which month to start from

SYNOPSIS

	void Trail::PromptStartingMonth()

DESCRIPTION

	This function will prompt the user for the month to start from and will have an impact on how the game will play out.
	If the user starts the game too early, there won't be any grass for the oxen to eat. If they start the game too late,
	then they will be playing the game during winter.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:07am 1/10/2019
*/
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

		// If they pick a valid choice, break out of the loop
		if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5") {
			break;
		}
		// If they want to see a description, print it out and still continue the loop
		else if (choice == "6") {
			cout << endl << "\t You attend a public meeting held for \"folks with the California - Oregon fever.\"" << endl;
			cout << "\t You're told:" << endl << endl;
			cout << "\t If you leave too early, there won't be any grass for your oxen to eat. If you leave " << endl;
			cout << "\t too late, you may not get to Oregon before winter comes. If you " << endl;
			cout << "\t leave at just the right time, there will be green grass and the weather " << endl;
			cout << "\t will still be cool." << endl << endl;
		}
		// If it is anything else, output an error message and continure the loop
		else {
			m_utility.DisplayError("Invalid option");
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
		m_utility.DisplayError("ERROR: Trail class doesn't know which month is starting!");
	}
}

/*
Trail::LeavingMessage()

NAME

	Oregon_Trail::LeavingMessage - Outputs all of the dialougue for when the player is leaving Independence

SYNOPSIS

	void Trail::LeavingMessage()

DESCRIPTION

	This function will output all of the dialouge after they picked the month they are starting at.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:10am 1/10/2019
*/
void Trail::LeavingMessage() {
	cout << endl << "\t Before leaving Independence you should buy equipment and supplies." << endl;
	cout << "\t You have " << m_playerMoney << ".00 in cash, but you don't have to spend it all now" << endl << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl << "\t How will you cross the rivers? If you have money, " << endl;
	cout << "\t you might take a ferry (if there is a ferry)." << endl;
	cout << "\t Or, you can ford the river and hope you and your" << endl;
	cout << "\t wagon aren't swallowed alive!" << endl << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl << "\t What about supplies? Well, if" << endl;
	cout << "\t you're low on food you can hunt. You might get a buffalo..." << endl;
	cout << "\t you might. And there are bear in the mountains." << endl << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl << "\t At the Dalles, you can try" << endl;
	cout << "\t navigating the Columbia River," << endl;
	cout << "\t but if running the rapids with" << endl;
	cout << "\t a makeshift raph makes you queasy," << endl;
	cout << "\t better take the Barlow Road." << endl << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl << "\t If for some reason you don't" << endl;
	cout << "\t survive -- your wagon burns," << endl;
	cout << "\t or thieves steal your oxen, or" << endl;
	cout << "\t you run out of provisions, or" << endl;
	cout << "\t you die of cholera -- don't" << endl;
	cout << "\t give up! Try again... and again..." << endl;
	cout << "\t until your name is up with the others" << endl;
	cout << "\t on the Oregon Top Ten." << endl << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl << "\t You can buy whatever you need at" << endl;
	cout << "\t Matt's General Store." << endl << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl << "\t Hello I'm Matt. So you're going" << endl;
	cout << "\t to Oregon! I can fix you up with what you need:" << endl;
	cout << endl << "\t \t - a team of oxen to pull your wagon" << endl;
	cout << endl << "\t \t - clothing for both summer and winter" << endl;
	cout << endl << "\t \t - plenty of food for the trip" << endl;
	cout << endl << "\t \t - ammunition for your rifles" << endl;
	cout << endl << "\t \t - spare parts for your wagon" << endl;
	cout << "\t ";
	m_utility.Wait();
}

/*
	Trail::DepartingStore()

NAME

	Oregon_Trail::DepartingStore - Initialize the store for the player when they are leaving Independence

SYNOPSIS

	void Trail::DepartingStore()

DESCRIPTION

	This function initializes the items and the store for when the player is departing from Independence, Missouri

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	3:32pm 1/14/2019
*/
void Trail::DepartingStore() {

	vector<Item> storeItems;

	storeItems.push_back(Item("Oxen", 40.0, "\t There are 2 oxen in a yoke; \n \t I recommend at least 3 yoke. \n \t I charge $40 a yoke."));
	storeItems.push_back(Item("Food", 0.2, "\t I recommend you take at \n \t least 200 pounds of food \n \t for each person in your \n \t "
		"family. I see that you have \n \t 5 people in all. You'll need \n \t flour, sugar, bacon,"
		"and \n \t coffee. My price is 20 \n \t cents a pound."));
	storeItems.push_back(Item("Clothing", 10.0, "\t You'll need warm clothing in \n \t the mountains. I recommend \n \t taking at least \n \t "
		"2 sets of \n \t clothes per person. Each \n \t set is $10.00"));
	storeItems.push_back(Item("Ammunition", 2.0, "\t I sell amunition in boxes \n \t of 20 bullets. Each box \n \t costs $2.00."));
	storeItems.push_back(Item("Spare parts - wagon wheel", 10.0, "\t It's a good idea to have a \n \t few spare wheels for your \n \t wagon:"));
	storeItems.push_back(Item("Spare parts - wagon axle", 10.0, "\t It's a good idea to have a \n \t few spare axles for your \n \t wagon:"));
	storeItems.push_back(Item("Spare parts - wagon tongue", 10.0, "\t It's a good idea to have a \n \t few spare tongues for your \n \t wagon:"));

	Store departingStore = Store();
	departingStore.SetDate("March 1, 1848");
	departingStore.SetLocation("Independence, Missouri");
	departingStore.SetPlayerMoney(m_playerMoney);
	departingStore.DisplayStore(storeItems);
	

}