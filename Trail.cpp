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
	m_weather = 0;

	m_currentLocation = "Independence";

	m_rateOfTravel = 10;
	m_milesTraveled = 0;

	InitializeLocations();

	m_rate5dollars = 0;
	m_rate2_5dollars = 0;
	m_rate0_5dollars = 0;

	m_totalScore = 0;

	srand((unsigned int)time(0));
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

	string choice;
	int milesNeededToTravel;
	int milesTraveled;
	string whichDirection;
	bool goingToGreenRiver = true;

	PromptPosition();
	PromptCharacterNames();
	PromptStartingMonth();
	m_dialogue.T_LeavingMessage(m_player.GetPlayerMoney());
	DepartingStore();
	m_dialogue.T_DepartingDialogue();

	m_date.ShowLocation(m_currentLocation);
	TrailMenu(m_Independence.GetHasStore(), m_Independence.GetName());

	// Cycle through the list of locations that the player has to travel to
	for (size_t i = 0; i < m_locations.size(); i++) {

		m_currentLocation = m_locations[i]->GetName();

		// Once you arrive at a location, this will propt if you want to visit the location
		if (m_locations[i]->GetName() != "Independence") {
			while (1) {
				cout << "\t You are now at the " << endl;
				cout << "\t " << m_locations[i]->GetName() << endl;
				cout << "\t Would you like to look around? ";
				cin >> choice;
				cout << endl;

				if (choice == "yes" || choice == "ye" || choice == "y") {
					m_date.ShowLocation(m_locations[i]->GetName());
					TrailMenu(m_locations[i]->GetHasStore(), m_locations[i]->GetName());
					break;
				}
				else if (choice == "no" || choice == "n") {
					break;
				}
			}
		}

		m_locations[i]->CrossLocation(m_player, m_date, m_weather);

		// If the player is at the Green River, then they have the option to travel to Green River,
		// or the next location which is Fort Bridger
		if (m_locations[i]->GetName() == "South Pass") {
			while (1) {
				m_dialogue.T_WhichDirectionChoice1();
				cin >> whichDirection;

				// Going to Green River
				if (whichDirection == "1") {
					goingToGreenRiver = true;
					m_locations[i]->SetMilesNeeded(57);
					break;
				}
				// Going to Fort Bridger
				else if (whichDirection == "2") {
					goingToGreenRiver = false;
					m_locations[i]->SetMilesNeeded(125);
					if (m_utility.HasElement(m_locations.size(), i + 1)) {
						m_locations[i + 1] = &m_FortBridger;
					}
					break;
				}
				else {
					m_utility.DisplayError("Invalid option.");
				}
			}
		}

		if (m_locations[i]->GetName() == "Blue Mountains") {
			while (1) {
				m_dialogue.T_WhichDirectionChoice2();
				cin >> whichDirection;

				// Going to Green River
				if (whichDirection == "1") {
					m_locations[i]->SetMilesNeeded(55);
					break;
				}
				// Going to Fort Bridger
				else if (whichDirection == "2") {
					m_locations[i]->SetMilesNeeded(125);
					if (m_utility.HasElement(m_locations.size(), i + 1)) {
						m_locations[i + 1] = &m_TheDalles;
					}
					break;
				}
				else {
					m_utility.DisplayError("Invalid option.");
				}
			}
		}

		if (m_utility.HasElement(m_locations.size(), i + 1)) {
			ShowMilesTo(m_locations[i]->GetName(), m_locations[i + 1]->GetName(), m_locations[i]->GetMilesNeeded());
		}

		milesNeededToTravel = m_locations[i]->GetMilesNeeded();
		milesTraveled = 0;

		// At each location, keep cycling through til the player reaches the destination
		for (int j = 0; j < m_locations[i]->GetMilesNeeded(); j += m_rateOfTravel) {
			ShowAndUpdateTrailInfo(m_rateOfTravel, milesNeededToTravel);
			milesTraveled += m_rateOfTravel;

			m_randomEvent.RandomEvent(m_player, m_date, m_weather);

			m_utility.Wait();
		}

		m_milesTraveled -= m_rateOfTravel;
		milesTraveled -= m_rateOfTravel;
		AddEndingMiles(m_locations[i]->GetMilesNeeded() - milesTraveled);

	}

	m_dialogue.T_End();
	CalculateScore();

}

/*
	Trail::PromptPosition()

NAME

	Trail::PromptPosition - Prompts the user for which position they want (difficulty)

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
		m_player.SetPlayerMoney(1600);
		m_player.SetPlayerPosition("Banker");
	}
	// Player chose to be a carpenter
	else if (positionChoice == "2") {
		m_player.SetPlayerMoney(800);
		m_player.SetPlayerPosition("Carpenter");
	}
	// Player chose to be a farmer
	else if (positionChoice == "3") {
		m_player.SetPlayerMoney(400);
		m_player.SetPlayerPosition("Farmer");
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
	string temp;
	bool sameName = false;

	while (1) {
		cout << "\t What is the first name of the wagon leader? ";
		cin >> temp;

		m_player.GetWagonLeader().SetName(temp);

		m_utility.OutputMessage("What are the names of the four other members?");

		// Cycling through four times to get the names of the four other members of the wagon party
		for (int i = 0; i < 4; i++) {
			cout << "\t " << i + 1 << ". ";
			cin >> temp;

			if (temp == m_player.GetWagonLeader().GetName()) {
				sameName = true;
			}

			for (size_t j = 0; j < m_player.GetWagonParty().size(); j++) {
				if (temp == m_player.GetWagonParty()[j].GetName()) {
					sameName = true;
				}
			}

			if (sameName) {
				m_utility.DisplayError("Name already used, pick another.");
				i--;
				sameName = false;
			}
			else {
				m_player.GetWagonParty().push_back(Member(temp));
			}
		}

		cout << "\t Are these names correct? Verify with yes or no. ";
		cin >> verify;

		if (verify == "yes" || verify == "ye" || verify == "y") {
			break;
		}
		else {
			m_player.GetWagonParty().clear();
		}
	}

}

/*
	Trail::PromptStartingMonth()

NAME

	Trail::PromptStartingMonth - Prompts the user for which month to start from

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
		m_date.SetMonth("March");
	}
	else if (choice == "2") {
		m_date.SetMonth("April");
	}
	else if (choice == "3") {
		m_date.SetMonth("May");
	}
	else if (choice == "4") {
		m_date.SetMonth("June");
	}
	else if (choice == "5") {
		m_date.SetMonth("July");
	}
	else {
		m_utility.DisplayError("ERROR: Trail class doesn't know which month is starting!");
	}

	m_date.SetDay(1);
	m_date.SetYear(1848);
}

/*
	Trail::DepartingStore()

NAME

	Trail::DepartingStore - Initialize the store for the player when they are leaving Independence

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
	Store store = Store();
	store.SetDate(m_date.GetYear(), m_date.GetMonth(), m_date.GetDay());
	store.SetLocation("Independence, Missouri");
	store.SetPlayerMoney(m_player.GetPlayerMoney());
	store.DisplayStore(storeItems, m_player);

	// Deduct the money that the player spent at the store
	m_player.DeductMoney(store.GetTotalPrice());

	// Add the items that the player bought to their inventory
	AddItemsFromStore(store.GetItemQuantitys());

}

/*
	Trail::AddItemsFromStore(vector<Item> a_storeItems)

NAME

	Trail::AddItemsFromStore - Add the items the player bought from a store to their inventory

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
			m_player.AddItemQuantity("Oxen", a_storeItems[i].GetQuantity() * 2);
		}
		else if (a_storeItems[i].GetName() == "Food") {
			m_player.AddItemQuantity("Food", a_storeItems[i].GetQuantity());
		}
		else if (a_storeItems[i].GetName() == "Clothing") {
			m_player.AddItemQuantity("Clothing", a_storeItems[i].GetQuantity());
		}
		else if (a_storeItems[i].GetName() == "Ammunition") {
			m_player.AddItemQuantity("Ammunition", a_storeItems[i].GetQuantity() * 20);
		}
		else if (a_storeItems[i].GetName() == "Spare parts - wagon wheel") {
			m_player.AddItemQuantity("Spare parts - wagon wheel", a_storeItems[i].GetQuantity());
		}
		else if (a_storeItems[i].GetName() == "Spare parts - wagon axle") {
			m_player.AddItemQuantity("Spare parts - wagon axle", a_storeItems[i].GetQuantity());
		}
		else if (a_storeItems[i].GetName() == "Spare parts - wagon tongue") {
			m_player.AddItemQuantity("Spare parts - wagon tongue", a_storeItems[i].GetQuantity());
		}
		else {
			m_utility.DisplayError("ERROR: There was an invalid item name from the store in trail class.");
		}
	}
}

/*
	Trail::TrailMenu()

NAME

	Trail::TrailMenu - Menu for player options while on the trail

SYNOPSIS

	void Trail::TrailMenu(bool a_hasStore, string a_locationName)

	a_hasStore --> indicates if a location has a store or not
	a_locationName --> name of the current location

DESCRIPTION

	This function provides various functions for the player to use while on the trail, able to change
	the pace at which they are using rations and pace, and other uses.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:41am 1/28/2019
*/
void Trail::TrailMenu(bool a_hasStore, string a_locationName) {

	string choice;
	bool alreadyRested = false;
	bool alreadyHunted = false;

	while (1) {
		cout << "\t Weather: " << m_utility.GetWeatherName(m_weather) << endl;
		cout << "\t Health: " << m_utility.GetHealthName(m_player.GetHealth()) << endl;
		cout << "\t Pace: " << m_player.GetPace() << endl;
		cout << "\t Rations: " << m_player.GetFoodRate() << endl << endl;

		cout << "\t You May:" << endl;
		m_utility.OutputMessage("    1. Continue on trail");
		m_utility.OutputMessage("    2. Check Supplies");
		m_utility.OutputMessage("    3. Look at map");
		m_utility.OutputMessage("    4. Change pace");
		m_utility.OutputMessage("    5. Change food rations");
		m_utility.OutputMessage("    6. Stop to rest");
		m_utility.OutputMessage("    7. Talk to people");
		if (a_hasStore) {
			m_utility.OutputMessage("    8. Buy supplies");
		}
		else {
			m_utility.OutputMessage("    8. Hunt");
		}

		cout << "\t    What is your choice? ";
		cin >> choice;

		// Continue the trail
		if (choice == "1") {
			break;
		}
		// Show the player's supplies
		else if (choice == "2") {
			ShowSupplies();
		} 
		// Show the map
		else if (choice == "3") {
			LookAtMap();
		}
		// Change the pace the player is going
		else if (choice == "4") {
			ChangePace();
		}
		// Change the amount of rations being used
		else if (choice == "5") {
			ChangeRations();
		}
		// Rest for a # of days to regenerate party health
		else if (choice == "6") {
			if (!alreadyRested) {
				alreadyRested = true;
				Rest();
			}
			else {
				cout << endl;
				m_utility.DisplayError("You have already rested!");
			}
		}
		// Talk to local people to get advice
		else if (choice == "7") {
			m_dialogue.TalkToPeople(m_currentLocation);
		}
		// Buy supplies if the location the player is at is not a river
		else if (a_hasStore && choice == "8") {
			VisitStore(a_locationName);
		}
		else if (!a_hasStore && choice == "8") {
			if (!alreadyHunted) {
				alreadyHunted = true;
				Hunt();
			}
			else {
				cout << endl;
				m_utility.DisplayError("You have already hunted!");
			}
		}
		// Anything else if invlaid input
		else {
			m_utility.DisplayError("Invalid option.");
		}
	}

}

/*
	Trail::ShowSupplies()

NAME

	Trail::ShowSupplies - Shows the player's current supplies

SYNOPSIS

	void Trail::ShowSupplies()

DESCRIPTION

	This function will output all of the player's supplies to the screen for them to see.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:50am 1/28/2019
*/
void Trail::ShowSupplies() {

	m_utility.OutputMessage("\t Your Supplies");
	cout << "\t oxen     " << m_player.GetItem("Oxen").GetQuantity() << endl;
	cout << "\t sets of clothing     " << m_player.GetItem("Clothing").GetQuantity() << endl;
	cout << "\t bullets     " << m_player.GetItem("Ammunition").GetQuantity() << endl;
	cout << "\t wagon wheels     " << m_player.GetItem("Spare parts - wagon wheel").GetQuantity() << endl;
	cout << "\t wagon axles     " << m_player.GetItem("Spare parts - wagon axle").GetQuantity() << endl;
	cout << "\t wagon tongue     " << m_player.GetItem("Spare parts - wagon tongue").GetQuantity() << endl;
	cout << "\t pounds of food     " << m_player.GetItem("Food").GetQuantity() << endl;
	cout << "\t money left     $" << m_player.GetPlayerMoney() << endl;
	m_utility.Wait();
}

void Trail::LookAtMap() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 2);
	cout << endl << "\t ";
	for (size_t i = 0; i < m_locations.size(); i++) {

		cout << m_locations[i]->GetName();

		// Need to also show the other location the player can travel to
		if (m_locations[i]->GetName() == "Green River") {
			cout << " || Fort Bridger";
		}

		// Need to also show the other location the player can travel to
		if (m_locations[i]->GetName() == "Fort Walla Walla") {
			cout << " || The Dalles";
		}

		// Output an arrow so long as its not the last location
		if (i != m_locations.size() - 1) {
			cout << " --> ";
		}

		if (i % 3 == 0 && i > 0) {
			cout << endl;
			cout << "\t ";
		}

		if (m_locations[i]->GetName() == m_currentLocation) {
			SetConsoleTextAttribute(hConsole, 12);
		}
	}

	SetConsoleTextAttribute(hConsole, 7);

	cout << endl << endl;
	m_utility.Wait();
}

/*
	Trail::ChangePace()

NAME

	Trail::ChangePace - Changes the pace at which the player's party walks per day

SYNOPSIS

	void Trail::ChangePace()

DESCRIPTION

	This function allows the player to change the pace at which the player can travel per day with their
	party. The less they walk per day, the healthier they will be. The more they walk per day, the greater
	the chance they will get sick.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	12:01pm 1/28/2019
*/
void Trail::ChangePace() {

	string choice;

	while (1) {
		// Outputting the options to console for the player
		m_utility.OutputMessage("\t Change pace");
		cout << "\t (currently \"" << m_player.GetPace() << "\")" << endl << endl;

		cout << "\t    1. a steady pace" << endl;
		cout << "\t    2. a strenuous pace" << endl;
		cout << "\t    3. a grueling pace" << endl;
		cout << "\t    4. find out what these \n different paces mean" << endl << endl;

		cout << "\t What is your choice? ";
		cin >> choice;

		// If they picked a valid option, the corrent pace will be selected
		if (choice == "1") {
			m_player.SetPace("steady");
			break;
		}
		else if (choice == "2") {
			m_player.SetPace("strenuous");
			break;
		}
		else if (choice == "3") {
			m_player.SetPace("grueling");
			break;
		}
		else if (choice == "4") {
			m_utility.OutputMessage("steady - You travel about 8 hours a");
			m_utility.OutputMessage("day, taking frequent rests. You take");
			m_utility.OutputMessage("care not to get too tired.");
			cout << endl;
			m_utility.OutputMessage("strenuous - You travel about 12 hours");
			m_utility.OutputMessage("a day, starting just after sunrise");
			m_utility.OutputMessage("and stopping shortly before sunset.");
			m_utility.OutputMessage("You stop to rest only when necessary.");
			m_utility.OutputMessage("You finish each day feeling very");
			m_utility.OutputMessage("tired.");
			cout << endl;
			m_utility.OutputMessage("grueling - You travel about 16 hours");
			m_utility.OutputMessage("a day, starting before sunrise and");
			m_utility.OutputMessage("continuing until dark. You almost");
			m_utility.OutputMessage("never stop to rest. You do not get");
			m_utility.OutputMessage("enough sleep at night. You finish");
			m_utility.OutputMessage("each day feeling absolutley");
			m_utility.OutputMessage("exhausted, and your health suffers.");
			cout << endl;
			m_utility.Wait();
		}
	}
}

/*
	Trail::ChangeRations

NAME

	Trail::ChangeRations - Changes the amount of rations the player's party each per day

SYNOPSIS

	void Trail::ChangeRations()

DESCRIPTION

	This function allows the player to change the amount of rations their party will consume each day. If they choose
	"filling" they will consume 15 pounds of food per day, "meager" will consume 10 pounds, and "bare bones" will
	consume 5 pounds per day.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	1:05pm 1/28/2019
*/
void Trail::ChangeRations() {

	string choice;

	while (1) {
		m_utility.OutputMessage("\t Change food rations");
		cout << "(currently \"" << m_player.GetFoodRate() << "\")" << endl << endl;

		m_utility.OutputMessage("The amount of food the people in");
		m_utility.OutputMessage("your party eat each day can");
		m_utility.OutputMessage("change. These amounts are:");
		cout << endl;
		m_utility.OutputMessage("\t 1. filling - meals are large and");
		m_utility.OutputMessage("\t generous.");
		cout << endl;
		m_utility.OutputMessage("\t 2. meager - meals are small, but");
		m_utility.OutputMessage("\t adequate.");
		cout << endl;
		m_utility.OutputMessage("\t 3. bare bones - meals are very");
		m_utility.OutputMessage("\t small; everyone stays hungry.");
		cout << endl;

		cout << "\t What is your choice? ";
		cin >> choice;

		// Consume 15 pounds of food per day
		if (choice == "1") {
			m_player.SetFoodRate("filling");
			break;
		}
		// Consume 10 pounds of food per day
		else if (choice == "2") {
			m_player.SetFoodRate("meager");
			break;
		}
		// Consume 5 pounds of food per day
		else if (choice == "3") {
			m_player.SetFoodRate("bare bones");
			break;
		}
		else {
			m_utility.DisplayError("Invalid menu choice");
		}
	}

}

/*
	Trail::Rest()

NAME

	Trail::Rest - Allows player to rest a couple days to regenerate health

SYNOPSIS

	void Trail::Rest()

DESCRIPTION

	This function allows the player rest for a couple of days to regenerate the members of the party's health. 
	The player is at most allowed to rest 9 days at a time.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	1:29pm 1/28/2019
*/
void Trail::Rest() {

	string numOfDays;

	cout << endl;
	while (1) {
		cout << "\t How many days would you" << endl;
		cout << "\t like to rest? ";
		cin >> numOfDays;

		if (!m_utility.CheckInput(numOfDays)) {
			m_utility.DisplayError("Invalid input.");
			continue;
		}
		//try {

			// Only allowed to rest 9 days
			if (stoi(numOfDays) > 9) {
				m_utility.DisplayError("Can only rest at most 9 days.");
			}
			else {
				for (int i = 0; i < stoi(numOfDays); i++) {
					m_date.ShowDate();
					m_utility.OutputMessage("Your party rests and recovers");
					m_utility.OutputMessage("for the day.");
					m_utility.Wait();

					m_date.NextDay();

				}
				break;
			}
		//}
		// If the user typed in anything other than a number, an exception will be thrown and the player
		// will get an error message
		/*catch (exception e) {
			m_utility.DisplayError("Invalid option.");
		}*/
	}
}

/*
	Trail::InitalizeLocations()

NAME

	Trail::InitializeLocations - Initializes the various locations for the trail

SYNOPSIS

	void Trail::Rest()

DESCRIPTION

	This function will intialize the name, amount of miles required to get to, and various other information
	that should be set at the start of the game for the locations in the game

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	5:50pm 1/30/2019
*/
void Trail::InitializeLocations() {

	m_Independence.SetName("Independence");
	m_Independence.SetMilesNeeded(102);

	m_KansasRiver.SetName("Kansas River crossing");
	m_KansasRiver.SetMilesNeeded(82);
	m_KansasRiver.SetHasStore(false);
	m_KansasRiver.SetHasFerry(true);

	m_BigBlueRiver.SetName("Big Blue River crossing");
	m_BigBlueRiver.SetMilesNeeded(118);
	m_BigBlueRiver.SetHasStore(false);

	m_FortKearney.SetName("Fort Kearney");
	m_FortKearney.SetMilesNeeded(250);

	m_ChimneyRock.SetName("Chimney Rock");
	m_ChimneyRock.SetMilesNeeded(86);
	m_ChimneyRock.SetHasStore(false);

	m_FortLaramie.SetName("Fort Laramie");
	m_FortLaramie.SetMilesNeeded(190);

	m_IndependenceRock.SetName("Independence Rock");
	m_IndependenceRock.SetMilesNeeded(102);
	m_IndependenceRock.SetHasStore(false);

	m_SouthPass.SetName("South Pass");
	m_SouthPass.SetMilesNeeded(0); // Will change once the user picks Green River or Fort Bridger
	m_SouthPass.SetHasStore(false);

	m_GreenRiver.SetName("Green River");
	m_GreenRiver.SetMilesNeeded(143);
	m_GreenRiver.SetHasStore(false);
	m_GreenRiver.SetHasFerry(false);

	m_FortBridger.SetName("Fort Bridger");
	m_FortBridger.SetMilesNeeded(143);

	m_SodaSprings.SetName("Soda Springs");
	m_SodaSprings.SetMilesNeeded(57);
	m_SodaSprings.SetHasStore(false);

	m_FortHall.SetName("Fort Hall");
	m_FortHall.SetMilesNeeded(182);

	m_SnakeRiver.SetName("Snake River");
	m_SnakeRiver.SetMilesNeeded(113); // Has the option to hire an Indian to cross

	m_FortBoise.SetName("Fort Boise");
	m_FortBoise.SetMilesNeeded(160);

	m_BlueMountains.SetName("Blue Mountains"); // From here, has the choice to travel to Fort Walla Walla or Dalles
	m_BlueMountains.SetMilesNeeded(55);
	m_BlueMountains.SetHasStore(false); 

	m_FortWallaWalla.SetName("Fort Walla Walla"); // Has the choice
	m_FortWallaWalla.SetMilesNeeded(55);

	m_TheDalles.SetName("The Dalles");
	m_TheDalles.SetMilesNeeded(125);
	m_TheDalles.SetHasStore(false);

	m_WillametteValley.SetName("Willamette Valley"); // User must pay to get into this location
	m_WillametteValley.SetMilesNeeded(0);
	m_WillametteValley.SetHasStore(false); 
	
	m_locations.push_back(&m_Independence);
	m_locations.push_back(&m_KansasRiver);
	m_locations.push_back(&m_BigBlueRiver);
	m_locations.push_back(&m_FortKearney);
	m_locations.push_back(&m_ChimneyRock);
	m_locations.push_back(&m_FortLaramie);
	m_locations.push_back(&m_IndependenceRock);
	m_locations.push_back(&m_SouthPass);
	m_locations.push_back(&m_GreenRiver);
	//m_locations.push_back(&m_FortBridger);
	m_locations.push_back(&m_SodaSprings);
	m_locations.push_back(&m_FortHall);
	m_locations.push_back(&m_SnakeRiver);
	m_locations.push_back(&m_FortBoise);
	m_locations.push_back(&m_BlueMountains);
	m_locations.push_back(&m_FortWallaWalla);
	//m_locations.push_back(&m_TheDalles);
	m_locations.push_back(&m_WillametteValley);


}

/*
	Trail::ShowAndUpdateTrailInfo()

NAME

	Trail::ShowAndUpdateTrailInfo - Shows and updates the information each time the player travels

SYNOPSIS

	void Trail::ShowAndUpdateTrailInfo(int a_miles, int &a_milesNeeded)

	a_miles --> the rate the player travels at in miles
	a_milesNeeded --> how many miles the player needs to travel to

DESCRIPTION

	This function shows essential information while the player is traveling to Oregon and updates
	all of the information after being displayed such as the date and miles traveled.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	5:55pm 1/30/2019
*/
void Trail::ShowAndUpdateTrailInfo(int a_miles, int &a_milesNeeded) {

	cout << "\t Date: " << m_date.GetMonth() << " " << m_date.GetDay() << ", " << m_date.GetYear() << endl;
	cout << "\t Weather: " << "Warm" << endl;
	cout << "\t Health: " << "Good" << endl;
	cout << "\t Food: " << m_player.GetItem("Food").GetQuantity() << endl;
	cout << "\t Next landmark: " << a_milesNeeded << " miles" << endl;;
	cout << "\t Miles traveled: " << m_milesTraveled << " miles" << endl << endl;

	m_player.DeductFood();
	m_date.NextDay();
	a_milesNeeded -= m_rateOfTravel;
	m_milesTraveled += a_miles;
}

/*
	Trail::AddEndingMiles(int a_miles)

NAME

	Trail::AddEndingMiles - Add ending miles to the total traveled

SYNOPSIS

	void Trail::AddEndingMiles(int a_miles)

	a_miles --> the rate the player travels at in miles

DESCRIPTION

	This function adds any leftover miles from traveling to the total miles travelled. For example,
	if the rate the player is travelling at is 10 miles per increment, and they have to travel
	102 miles, the last 2 miles will be added using this function.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	5:55pm 2/6/2019
*/
void Trail::AddEndingMiles(int a_miles) {

	m_milesTraveled += a_miles;
}

/*
	Trail::ShowMilesTo(string a_currentLocationName, string a_nextLocationName, int a_milesNeeded)

NAME

	Trail::ShowMilesTo - Outputs the miles needed to travel somewhere

SYNOPSIS

	void Trail::ShowMilesTo(string a_currentLocationName, string a_nextLocationName, int a_milesNeeded)

	a_currentLocationName --> name of the current location the player is at
	a_nextLocationName --> name of the next location the player will travel to
	a_milesNeeded --> miles needed to get to the next location

DESCRIPTION

	This function outputs a short description of where the player will travel to next.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	4:11pm 2/11/2019
*/
void Trail::ShowMilesTo(string a_currentLocationName, string a_nextLocationName, int a_milesNeeded) {

	cout << endl << "\t From " << a_currentLocationName << " it is " << a_milesNeeded << endl;
	m_utility.OutputMessage("miles to the " + a_nextLocationName + ".");
	cout << endl;

	m_utility.Wait();
}

/*
	Trail::VisitStore(string a_location)

NAME

	Trail::VisitStore - A locations store if the player wants to visit it

SYNOPSIS

	void Trail::VisitStore(string a_location)

	a_location --> the location the store is at

DESCRIPTION

	This function provides the functionality for setting up a store for the player to visit,
	initializsing the items inside of it, and calling the function from the Store class for the
	player to buy supplies.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	4:17pm 2/11/2019
*/
void Trail::VisitStore(string a_location) {

	vector<Item> storeItems;

	// Initializing the items to be put into the departing store
	storeItems.push_back(Item("Oxen", 25.0 + m_rate5dollars, "\t " + to_string(25 + m_rate5dollars) + " per ox", "You can not bring more than 9 oxen with you.", 9));
	storeItems.push_back(Item("Food", 0.25 + m_rate0_5dollars, "\t " + to_string(0.25 + m_rate0_5dollars) + "per pound", "Your wagon may only carry \n \t 2000 pounds of food.", 2000));
	storeItems.push_back(Item("Clothing", 12.5 + m_rate2_5dollars, "\t " + to_string(12.50 + m_rate2_5dollars) + "per set", "NULL", INT_MAX));
	storeItems.push_back(Item("Ammunition", 2.5 + m_rate0_5dollars, "\t " + to_string(2.5 + m_rate0_5dollars) + "per box", "NULL", INT_MAX));
	storeItems.push_back(Item("Spare parts - wagon wheel", 12.5 + m_rate2_5dollars, "\t " + to_string(12.50 + m_rate2_5dollars) + "per wheel", 
		"Your wagon may only carry 3 \n \t wagon wheels.", 3));
	storeItems.push_back(Item("Spare parts - wagon axle", 12.5 + m_rate2_5dollars, "\t " + to_string(12.50 + m_rate2_5dollars) + " per axle",
		"Your wagon may only carry 3 \n \t wagon axles.", 3));
	storeItems.push_back(Item("Spare parts - wagon tongue", 12.5 + m_rate2_5dollars, "\t " + to_string(12.50 + m_rate2_5dollars) + " per tongue",
		"Your wagon may only carry 3 \n \t wagon tongues", 3));

	// Creating the store, setting the initial information, and sending the items to be sold there
	Store store = Store();
	store.SetDate(m_date.GetYear(), m_date.GetMonth(), m_date.GetDay());
	store.SetLocation(a_location);
	store.SetPlayerMoney(m_player.GetPlayerMoney());
	store.DisplayStore(storeItems, m_player);

	// Deduct the money that the player spent at the store
	m_player.DeductMoney(store.GetTotalPrice());

	// Add the items that the player bought to their inventory
	AddItemsFromStore(store.GetItemQuantitys());

	IncreaseRates();
}

/*
	Trail::Hunt()

NAME

	Trail::Hunt - Function to let the player hunt to gain extra food

SYNOPSIS

	void Trail::Hunt()

DESCRIPTION

	This function is called when the player is in the trail menu and decides to hunt for food.
	This gives the player an oppertunity gain extra food at locations that don't have a store.
	The idea of hunting is that they need to enter "BANG" or "POW" in a certain amount of time
	that is randomly determined. Also the amount of times they are able to enter "BANG" or "POW"
	is between 1 and 10 times for varying amount of foods for the player to earn. 

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:03pm 2/20/2019
*/
void Trail::Hunt() {

	int amountOfTries = (rand() % 10) + 1;
	int amountOfTime;
	int bangOrPowNum;
	string bangOrPowString;
	string userText;
	time_t beforeTime;
	time_t afterTime;
	int amountOfFoodEarned = 0;

	// Opening intro
	m_dialogue.T_ShowHuntingInstructions();

	m_utility.OutputMessage("Ready...");
	Sleep(1000);
	m_utility.OutputMessage("Set...");
	Sleep(1000);
	m_utility.OutputMessage("Go!");

	// Cycle through the amount of times the player has to hunt
	for (int i = 0; i < amountOfTries; i++) {

		// Amount of time to type word is between 2 and 7 seconds
		amountOfTime = (rand() % 5) + 2;
		bangOrPowNum = rand() % 2;

		if (bangOrPowNum == 0) {
			bangOrPowString = "BANG";
		}
		else {
			bangOrPowString = "POW";
		}
		cout << "You have: " << amountOfTime << " seconds to type " << bangOrPowString << endl;
		beforeTime = time(0);
		cin >> userText;
		afterTime = time(0);

		// If the user types the word correctly and in the correct amount of time, they get some food
		if (userText == bangOrPowString && afterTime - beforeTime < amountOfTime) {
			cout << "You got food!" << endl;
			amountOfFoodEarned += 5 * (amountOfTime - (int)(afterTime - beforeTime + 1));
		}
		else {
			cout << "Spelled wrong or ran out of time." << endl;
		}

	}

	m_player.AddItemQuantity("Food", amountOfFoodEarned); 


}

/*
	Trail::IncreaseRates()

NAME

	Trail::IncreaseRates - Increases the amount of money to be added to store prices

SYNOPSIS

	void Trail::IncreaseRates()

DESCRIPTION

	This function increases the rates by various amounts so the next time the player visits a location,
	the prices will be slightly higher than the previous.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	4:21pm 2/11/2019
*/
void Trail::IncreaseRates() {

	m_rate5dollars += 5;
	m_rate2_5dollars += 2.5;
	m_rate0_5dollars += 0.05;
}

/*
	Trail::CalculateScore()

NAME

	Trail::CalculateScore - Calculates score based on factors of the game

SYNOPSIS

	void Trail::CalculateScore()

DESCRIPTION

	This function cycle through the various ways the player is able to earn points for their
	score such as the position they picked, how many items they have at the end of the game,
	how much money they have, and other factors.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	3:05pm 3/3/2019
*/
void Trail::CalculateScore() {

	int multiplier = 1;
	int scorePerItem[8];

	// Setting the multiplier the score will be times by depending on the player's initial position
	if (m_player.GetPlayerPosition() == "Banker") {
		multiplier = 1;
	}
	else if (m_player.GetPlayerPosition() == "Carpenter") {
		multiplier = 2;
	}
	else if (m_player.GetPlayerPosition() == "Farmer") {
		multiplier = 3;
	}
	else {
		m_utility.DisplayError("ERROR: In calculating score for position.");
	}

	// Calculating the score for the player's health
	if (m_player.GetHealth() == 3) {
		m_totalScore += 500;
		m_totalScore += 500 * m_player.GetWagonParty().size();
		scorePerItem[0] = 500;
		scorePerItem[0] += 500 * m_player.GetWagonParty().size();
	}
	else if (m_player.GetHealth() == 2) {
		m_totalScore += 400;
		m_totalScore += 400 * m_player.GetWagonParty().size();
		scorePerItem[0] = 400;
		scorePerItem[0] += 400 * m_player.GetWagonParty().size();
	}
	else if (m_player.GetHealth() == 1) {
		m_totalScore += 300;
		m_totalScore += 300 * m_player.GetWagonParty().size();
		scorePerItem[0] = 300;
		scorePerItem[0] += 300 * m_player.GetWagonParty().size();
	}
	else if (m_player.GetHealth() == 0) {
		m_totalScore += 200;
		m_totalScore += 200 * m_player.GetWagonParty().size();
		scorePerItem[0] = 200;
		scorePerItem[0] += 200 * m_player.GetWagonParty().size();
	}
	else {
		m_utility.DisplayError("ERROR: Calculating score in health.");
	}

	// Gain 50 points for having the wagon
	m_totalScore += 50;
	scorePerItem[1] = 50;

	// 4 points for each ox
	m_totalScore += (4 * m_player.GetItem("Oxen").GetQuantity());
	scorePerItem[2] = 4 * m_player.GetItem("Oxen").GetQuantity();

	// 2 points for each extra wagon
	m_totalScore += (2 * m_player.GetItem("Spare parts - wagon wheel").GetQuantity());
	scorePerItem[3] = 2 * m_player.GetItem("Spare parts - wagon wheel").GetQuantity();

	// 2 points for each extra axle
	m_totalScore += (2 * m_player.GetItem("Spare parts - wagon axle").GetQuantity());
	scorePerItem[3] += 2 * m_player.GetItem("Spare parts - wagon axle").GetQuantity();

	// 2 points for each extra tongue
	m_totalScore += (2 * m_player.GetItem("Spare parts - wagon tongue").GetQuantity());
	scorePerItem[3] += 2 * m_player.GetItem("Spare parts - wagon tongue").GetQuantity();

	// 2 points for each set of clothing
	m_totalScore += (2 * m_player.GetItem("Clothing").GetQuantity());
	scorePerItem[4] = 2 * m_player.GetItem("Clothing").GetQuantity();

	// 1 point for each multiple of 50 bullets
	m_totalScore += (m_player.GetItem("Ammunition").GetQuantity() / 50);
	scorePerItem[5] = m_player.GetItem("Ammunition").GetQuantity() / 50;

	// 1 point for each 25 pounds of food
	m_totalScore += (m_player.GetItem("Food").GetQuantity() / 25);
	scorePerItem[6] = m_player.GetItem("Food").GetQuantity() / 25;

	// 1 point for each $5
	m_totalScore += (int)(m_player.GetPlayerMoney() / 5);
	scorePerItem[7] = (int)(m_player.GetPlayerMoney() / 5);

	cout << "\t Total points earner: " << m_totalScore << endl;
	ShowScoreDetails(scorePerItem);

}

/*
	Trail::ShowScoreDetails(int a_scores[])

NAME

	Trail::ShowScoreDetails - Outputs how the player earned their points

SYNOPSIS

	void Trail::ShowScoreDetails(int a_scores[])

	a_scores[] --> the various scores that the player earned

DESCRIPTION

	This function outputs to the console all of the various ways the player earned their score.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	3:06pm 3/3/2019
*/
void Trail::ShowScoreDetails(int a_scores[]) {

	m_utility.OutputMessage("Points for arriving in Oregon");

	cout << "-------------------------------------------------------" << endl;
	cout << "\t " << m_player.GetWagonParty().size() << " people in " << m_player.GetHealth() << " health " << a_scores[0] << endl;
	cout << "\t " << "1 wagon " << a_scores[1] << endl;
	cout << "\t " << m_player.GetItem("Oxen").GetQuantity() << " oxen " << a_scores[2] << endl;
	cout << "\t " << m_player.GetItem("Spare parts - wagon wheel").GetQuantity() + m_player.GetItem("Spare parts - wagon axle").GetQuantity() +
		m_player.GetItem("Spare parts - wagon tongue").GetQuantity() << " spare parts " << a_scores[3] << endl;
	cout << "\t " << m_player.GetItem("Clothing").GetQuantity() << " sets of clothing " << a_scores[4] << endl;
	cout << "\t " << m_player.GetItem("Ammunition").GetQuantity() << " bullets " << a_scores[5] << endl;
	cout << "\t " << m_player.GetItem("Food").GetQuantity() << " pounds of food " << a_scores[6] << endl;
	cout << "\t $" << m_player.GetPlayerMoney() << " cash " << a_scores[7] << endl;
	cout << "\t \t Total: " << m_totalScore << endl;
	cout << "-------------------------------------------------------" << endl;
}

/*
	Trail::GetTotalScore()

NAME

	Trail::GetTotalScore - Returns the score the player earned

SYNOPSIS

	int Trail::GetTotalScore()

DESCRIPTION

	This function returns the total score the player earned.

RETURNS

	Int

AUTHOR

	Nicholas Cockcroft

Date

	3:08pm 3/3/2019
*/
int Trail::GetTotalScore() {
	return m_totalScore;
}