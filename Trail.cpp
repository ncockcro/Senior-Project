#include "Trail.h"


/*
	Trail()

NAME

	Trail - Default constructor

SYNOPSIS

	Trail()

DESCRIPTION

	This is the default constructor for the Trail class. Anything that needs to be intialized at the start
	of an active game will be done so here.

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	11:00am 1/9/2019
*/
Trail::Trail()
{
	InitializePartyItems();
	m_location = "Independence";
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

	m_utility.ShowLocation(m_location, m_year, m_month, m_day);
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

	cout << endl;
	m_utility.OutputMessage("Many kinds of people made the trip to Oregon.");
	m_utility.OutputMessage("You may:");

	// keep looping through this menu until the user enters a correct option
	while (1) {

		m_utility.OutputMessage("1. Be a banker from Boston");
		m_utility.OutputMessage("2. Be a carpenter from Ohio");
		m_utility.OutputMessage("3. Be a farmer from Illinois");
		m_utility.OutputMessage("4. Find out the differences between these choices");
		cout << endl;
		cout << "\t What is your choice? ";
		cin >> positionChoice;

		if (positionChoice == "1" || positionChoice == "2" || positionChoice == "3") {
			break;
		}
		else if (positionChoice == "4") {
			cout << endl;
			m_utility.OutputMessage("Traveling to Oregon isn't easy! But if you're a banker,");
			m_utility.OutputMessage("you'll have more money for supplies than a carpenter or a farmer.");
			m_utility.OutputMessage("However, the harder you have to try, the more points you deserve!");
			m_utility.OutputMessage("Therefore, the farmer earns the greatest number of points");
			m_utility.OutputMessage("and the banker earns the least.");
			cout << endl;
			m_utility.Wait();
		}
		else {
			m_utility.DisplayError("That is an incorrect option.");
		}
	}

	// Player chose to be a banker
	if (positionChoice == "1") {
		m_playerMoney = 1600;
		m_playerPosition = "Banker";
	}
	// Player chose to be a carpenter
	else if (positionChoice == "2") {
		m_playerMoney = 800;
		m_playerPosition = "Carpenter";
	}
	// Player chose to be a farmer
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

		m_utility.OutputMessage("What are the names of the four other members?");

		string temp;
		bool sameName = false;
		// Cycling through four times to get the names of the four other members of the wagon party
		for (int i = 0; i < 4; i++) {
			cout << "\t " << i + 1 << ". ";
			cin >> temp;

			if (temp == m_wagonLeader) {
				sameName = true;
			}

			for (int j = 0; j < i; j++) {
				if (temp == m_wagonParty[j]) {
					sameName = true;
				}
			}

			if (sameName) {
				m_utility.DisplayError("Name already used, pick another.");
				i--;
				sameName = false;
			}
			else {
				m_wagonParty[i] = temp;
			}
		}

		cout << "\t Are these names correct? Verify with yes or no. ";
		cin >> verify;

		if (verify == "yes" || verify == "ye" || verify == "y") {
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
		m_utility.OutputMessage("It is 1848. Your jumping off place for Oregon Independence, Missouri. You must");
		m_utility.OutputMessage("decide which month to leave Independence.");
		m_utility.OutputMessage("1. March");
		m_utility.OutputMessage("2. April");
		m_utility.OutputMessage("3. May");
		m_utility.OutputMessage("4. June");
		m_utility.OutputMessage("5. July");
		m_utility.OutputMessage("6. Ask for advice");
		cout << endl;
		cout << "\t What is your choice? ";
		cin >> choice;
		cout << endl;

		// If they pick a valid choice, break out of the loop
		if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5") {
			break;
		}
		// If they want to see a description, print it out and still continue the loop
		else if (choice == "6") {
			cout << endl;
			m_utility.OutputMessage("You attend a public meeting held for \"folks with the California - Oregon fever.\"");
			m_utility.OutputMessage("You're told:");
			cout << endl;
			m_utility.OutputMessage("If you leave too early, there won't be any grass for your oxen to eat. If you leave");
			m_utility.OutputMessage("too late, you may not get to Oregon before winter comes. If you");
			m_utility.OutputMessage("leave at just the right time, there will be green grass and the weather ");
			m_utility.OutputMessage("will still be cool.");
			cout << endl;
			m_utility.Wait();
		}
		// If it is anything else, output an error message and continure the loop
		else {
			m_utility.DisplayError("Invalid option");
		}
	}

	if (choice == "1") {
		m_month = "March";
	}
	else if (choice == "2") {
		m_month = "April";
	}
	else if (choice == "3") {
		m_month = "May";
	}
	else if (choice == "4") {
		m_month = "June";
	}
	else if (choice == "5") {
		m_month = "July";
	}
	else {
		m_utility.DisplayError("ERROR: Trail class doesn't know which month is starting!");
	}

	m_day = 1;
	m_year = 1848;
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

	m_utility.OutputMessage("Before leaving Independence you should buy equipment and supplies.");
	cout << "\t You have " << m_playerMoney << ".00 in cash, but you don't have to spend it all now" << endl << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl;
	m_utility.OutputMessage("How will you cross the rivers? If you have money,");
	m_utility.OutputMessage("you might take a ferry (if there is a ferry).");
	m_utility.OutputMessage("Or, you can ford the river and hope you and your");
	m_utility.OutputMessage("wagon aren't swallowed alive!");
	cout << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl;
	m_utility.OutputMessage("What about supplies? Well, if");
	m_utility.OutputMessage("you're low on food you can hunt. You might get a buffalo...");
	m_utility.OutputMessage("you might. And there are bear in the mountains.");
	cout << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl;
	m_utility.OutputMessage("At the Dalles, you can try");
	m_utility.OutputMessage("navigating the Columbia River,");
	m_utility.OutputMessage("but if running the rapids with");
	m_utility.OutputMessage("a makeshift raph makes you queasy,");
	m_utility.OutputMessage("better take the Barlow Road.");
	cout << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl;
	m_utility.OutputMessage("If for some reason you don't");
	m_utility.OutputMessage("survive -- your wagon burns,");
	m_utility.OutputMessage("or thieves steal your oxen, or");
	m_utility.OutputMessage("you run out of provisions, or");
	m_utility.OutputMessage("you die of cholera -- don't");
	m_utility.OutputMessage("give up! Try again... and again...");
	m_utility.OutputMessage("until your name is up with the others");
	m_utility.OutputMessage("on the Oregon Top Ten.");
	cout << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl;
	m_utility.OutputMessage("You can buy whatever you need at");
	m_utility.OutputMessage("Matt's General Store.");
	cout << endl;
	cout << "\t ";
	m_utility.Wait();

	cout << endl;
	m_utility.OutputMessage("Hello I'm Matt. So you're going");
	m_utility.OutputMessage("to Oregon! I can fix you up with what you need:");
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

	// Initializing the items to be put into the departing store
	storeItems.push_back(Item("Oxen", 40.0, "\t There are 2 oxen in a yoke; \n \t I recommend at least 3 yoke. \n \t I charge $40 a yoke.", 
		"You can not bring more than 9 oxen with you.", 9));
	storeItems.push_back(Item("Food", 0.2, "\t I recommend you take at \n \t least 200 pounds of food \n \t for each person in your \n \t "
		"family. I see that you have \n \t 5 people in all. You'll need \n \t flour, sugar, bacon,"
		"and \n \t coffee. My price is 20 \n \t cents a pound.",
		"Your wagon may only carry \n \t 2000 pounds of food.", 2000));
	storeItems.push_back(Item("Clothing", 10.0, "\t You'll need warm clothing in \n \t the mountains. I recommend \n \t taking at least \n \t "
		"2 sets of \n \t clothes per person. Each \n \t set is $10.00", "NULL", INT_MAX));
	storeItems.push_back(Item("Ammunition", 2.0, "\t I sell amunition in boxes \n \t of 20 bullets. Each box \n \t costs $2.00.", "NULL", INT_MAX));
	storeItems.push_back(Item("Spare parts - wagon wheel", 10.0, "\t It's a good idea to have a \n \t few spare wheels for your \n \t wagon:", 
		"Your wagon may only carry 3 \n \t wagon wheels.", 3));
	storeItems.push_back(Item("Spare parts - wagon axle", 10.0, "\t It's a good idea to have a \n \t few spare axles for your \n \t wagon:", 
		"Your wagon may only carry 3 \n \t wagon axles.", 3));
	storeItems.push_back(Item("Spare parts - wagon tongue", 10.0, "\t It's a good idea to have a \n \t few spare tongues for your \n \t wagon:",
		"Your wagon may only carry 3 \n \t wagon tongues", 3));

	// Creating the store, setting the initial information, and sending the items to be sold there
	Store departingStore = Store();
	departingStore.SetDate(m_year, m_month, m_day);
	departingStore.SetLocation("Independence, Missouri");
	departingStore.SetPlayerMoney(m_playerMoney);
	departingStore.DisplayStore(storeItems);

	// Deduct the money that the player spent at the store
	DeductMoney(departingStore.GetTotalPrice());

	// Add the items that the player bought to their inventory
	AddItemsFromStore(departingStore.GetItemQuantitys());

	cout << endl << endl;
	m_utility.OutputMessage("Well then, you're ready");
	m_utility.OutputMessage("to start. Good luck!");
	m_utility.OutputMessage("You have a long and");
	m_utility.OutputMessage("difficult journey ahead");
	m_utility.OutputMessage("of you.");
	m_utility.Wait();

}

/*
	Trail::DeductMoney(double a_money)

NAME

	Oregon_Trail::DepartingStore - Deduct money that is passed in from the player's cash stack

SYNOPSIS

	void Trail::DepartingStore(double a_money)
	a_money --> money to deduct

DESCRIPTION

	This function will deduct the amount of money passed in from the money the player has in a game of
	Oregon Trail.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:18pm 1/24/2019
*/
void Trail::DeductMoney(double a_money) {

	// If the player's money subtracted with what was passed in was greater than 0, subtract the money
	if (m_playerMoney - a_money > 0) {
		m_playerMoney = m_playerMoney - a_money;
	}
	// Otherwise, report an error since there should never be subtracting of more money than the player has
	else {
		m_utility.DisplayError("ERROR: Tried to subtract more money than player had.");
	}
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
*//*
	Trail::AddItemsFromStore(vector<Item> a_storeItems)

NAME

	Oregon_Trail::AddItemsFromStore - Add the items the player bought from a store to their inventory

SYNOPSIS

	void Trail::AddItemsFromStore(vector<Item> a_storeItems)

	a_storeItems --> items from a store the player purchased

DESCRIPTION

	This function will cycle through all of the items in game and add to the player's pile if they bought
	any from the store.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:22pm 1/23/2019
*/
void Trail::AddItemsFromStore(vector<Item> a_storeItems) {
	
	// Cycling through each of the items and adding them to the player's pile
	for (size_t i = 0; i < a_storeItems.size(); i++) {

		if (a_storeItems[i].GetName() == "Oxen") {
			m_partyOxen.AddToQuantity(a_storeItems[i].GetQuantity());
		}
		else if (a_storeItems[i].GetName() == "Food") {
			m_partyFood.AddToQuantity(a_storeItems[i].GetQuantity());
		}
		else if (a_storeItems[i].GetName() == "Clothing") {
			m_partyClothing.AddToQuantity(a_storeItems[i].GetQuantity());
		}
		else if (a_storeItems[i].GetName() == "Ammunition") {
			m_partyAmmunition.AddToQuantity(a_storeItems[i].GetQuantity());
		}
		else if (a_storeItems[i].GetName() == "Spare parts - wagon wheel") {
			m_partyExtraWheel.AddToQuantity(a_storeItems[i].GetQuantity());
		}
		else if (a_storeItems[i].GetName() == "Spare parts - wagon axle") {
			m_partyExtraAxle.AddToQuantity(a_storeItems[i].GetQuantity());
		}
		else if (a_storeItems[i].GetName() == "Spare parts - wagon tongue") {
			m_partyExtraTongue.AddToQuantity(a_storeItems[i].GetQuantity());
		}
		else {
			m_utility.DisplayError("ERROR: There was an invalid item name from the store in trail class.");
		}
	}
}

/*
	Trail::IntializePartyItems()

NAME

	Oregon_Trail::InitializePartyItems - Initialize the items in the player's inventory

SYNOPSIS

	void Trail::InitializePartyItems

DESCRIPTION

	This function initializes the player's items by setting each item's name, description, default price, default
	cap price, and cap price description. This initializes all of the items in the game for the player.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:25pm 1/23/2019
*/
void Trail::InitializePartyItems() {
	m_partyOxen = Item("Oxen", 0.1, "\t There are 2 oxen in a yoke; \n \t I recommend at least 3 yoke. \n \t I charge $40 a yoke.",
		"You can not bring more than 9 oxen with you.", 9);
	m_partyOxen.SetQuantity(0);

	m_partyFood = Item("Food", 0.1, "\t I recommend you take at \n \t least 200 pounds of food \n \t for each person in your \n \t "
		"family. I see that you have \n \t 5 people in all. You'll need \n \t flour, sugar, bacon,"
		"and \n \t coffee. My price is 20 \n \t cents a pound.",
		"Your wagon may only carry \n \t 2000 pounds of food.", 2000);
	m_partyFood.SetQuantity(0);

	m_partyClothing = Item("Clothing", 0.1, "\t You'll need warm clothing in \n \t the mountains. I recommend \n \t taking at least \n \t "
		"2 sets of \n \t clothes per person. Each \n \t set is $10.00", "NULL", INT_MAX);
	m_partyClothing.SetQuantity(0);

	m_partyAmmunition = Item("Ammunition", 0.1, "\t I sell amunition in boxes \n \t of 20 bullets. Each box \n \t costs $2.00.", "NULL", INT_MAX);
	m_partyAmmunition.SetQuantity(0);

	m_partyExtraWheel = Item("Spare parts - wagon wheel", 0.1, "\t It's a good idea to have a \n \t few spare wheels for your \n \t wagon:",
		"Your wagon may only carry 3 \n \t wagon wheels.", 3);
	m_partyExtraWheel.SetQuantity(0);

	m_partyExtraAxle = Item("Spare parts - wagon axle", 0.1, "\t It's a good idea to have a \n \t few spare axles for your \n \t wagon:",
		"Your wagon may only carry 3 \n \t wagon axles.", 3);
	m_partyExtraAxle.SetQuantity(0);

	m_partyExtraTongue = Item("Spare parts - wagon tongue", 0.1, "\t It's a good idea to have a \n \t few spare tongues for your \n \t wagon:",
		"Your wagon may only carry 3 \n \t wagon tongues", 3);
	m_partyExtraTongue.SetQuantity(0);
}