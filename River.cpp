#include "River.h"

/*
	River::River()

NAME

	River::River() - Default constructor

SYNOPSIS

	River::River()

DESCRIPTION

	This is the default constructor for the river class, sets the initial values for the width and depth of the river

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	11:18am 2/6/2019
*/
River::River()
{
	srand((unsigned int)time(0));

	m_randomNum = 0;
	m_riverDepth = 0.0;
	m_riverWidth = 0.0;
	m_hasFerry = false;
}

/*
	River::CrossLocation()

NAME

	River::CrossLocation - Handles the functionality for when the player needs to cross a river

SYNOPSIS

	void River::CrossLocation

DESCRIPTION

	This function is the main driving function of the river class and handles the opening dialogue for the river,
	seeding the width and depth of a river with random values, and houses the main menu for a river for if the
	player wants to take a certain way to cross a river, take a ferry if available, wait a day, or get some
	advice.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:21am 2/6/2019
*/
void River::CrossLocation(Player &a_player, Date &a_date, int a_weather) {

	string choice;

	// Generating a random number for the depth of the river
	uniform_real_distribution<double> unif(0.1, 10.0);
	default_random_engine re;
	re.seed((unsigned int)time(0));
	m_riverDepth = unif(re);

	// Generating a random number for the length of the river
	uniform_real_distribution<double> unif2(100.0, 800.0);
	default_random_engine re2;
	re2.seed((unsigned int)time(0));
	m_riverWidth = unif2(re2);

	OpeningDialogue();

	while (1) {
		cout << "\t " << a_date.GetMonth() << " " << a_date.GetDay() << ", " << a_date.GetYear() << endl << endl;
		ShowRiverMenu(m_utility.GetWeatherName(a_weather));
		cin >> choice;

		// If the player wants to ford the river with their wagon
		if (choice == "1") {
			FordRiver(a_player);
			break;
		}
		// If the player wants to try and float across the river
		else if (choice == "2") {
			FloatRiver(a_player);
			break;
		}
		// If the river has a ferry, then choice 3 will be the option to take it
		else if (m_hasFerry && choice == "3") {

			// If TakeFerry returns true, then the player successfully crossed the river
			if (TakeFerry(a_player)) {
				break;
			}
		}
		// If the river does not have a ferry, then option 3 is for waiting for conditions
		else if (!m_hasFerry && choice == "3") {
			WaitADay(a_date);
		}
		// If the river has a ferry, then option 4 is for waiting for conditions
		else if (m_hasFerry && choice == "4") {
			WaitADay(a_date);
		}
		// If there is no ferry for the river, then option 4 is for getting more info
		else if (!m_hasFerry && choice == "4") {
			RiverMoreInfoDialogue();
		}
		// If there is a ferry at the river, then option 5 is for getting more info
		else if (m_hasFerry && choice == "5") {
			RiverMoreInfoDialogue();
		}
		else {
			m_utility.DisplayError("Invalid option.");
		}

	}

}
/*
	River::GetRiverWidth()

NAME

	River::GetRiverWidth - Returns the width of a river object

SYNOPSIS

	double River::GetRiverWidth()

DESCRIPTION

	The function returns the width of a river object.

RETURNS

	Double

AUTHOR

	Nicholas Cockcroft

Date

	10:27pm 1/30/2019
*/
double River::GetRiverWidth() {
	return m_riverWidth;
}

/*
	River::GetRiverDepth()

NAME

	River::GetRiverDepth - Returns the depth of a river object

SYNOPSIS

	void River::GetRiverDepth()

DESCRIPTION

	This function returns the depth of a river object.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:30pm 1/30/2019
*/
double River::GetRiverDepth() {
	return m_riverDepth;
}

/*
	River::OpeningDialogue()

NAME

	River::OpeningDialogue - Outputs the intro to a river

SYNOPSIS

	void Trail::OpeningDialogue()

DESCRIPTION

	This function outputs the opening dialogue, river width and depth, to the console.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:24am 2/6/2019
*/
void River::OpeningDialogue() {

	cout << endl;
	m_utility.OutputMessage("You must cross the river in");
	m_utility.OutputMessage("order to continue. The");
	m_utility.OutputMessage("river at this point is");
	cout << "\t currently " << m_riverWidth << " feet across," << endl;
	cout << "\t and " << m_riverDepth << " feet deep in the" << endl;
	m_utility.OutputMessage("middle.");
	cout << endl;
	m_utility.Wait();
}

/*
	River::ShowRiverMenu

NAME

	River::ShowRiverMenu - Outputs the menu options for river

SYNOPSIS

	void Trail::ShowRiverMenu(string a_weather)

	a_weather --> current weather of the game

DESCRIPTION

	This function outputs to the console the menu options for the player. It will also show if there is a ferry
	to take or not depending on what was set.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:28am 2/6/2019
*/
void River::ShowRiverMenu(string a_weather) {

	cout << "\t Weather: " << a_weather << endl;
	cout << "\t River width: " << m_riverWidth << endl;
	cout << "\t River depth: " << m_riverDepth << endl << endl;
	
	cout << "\t You may:" << endl << endl;
	
	cout << "\t 1. attempt to ford the river" << endl;
	cout << "\t 2. caulk the wagon and float it across" << endl;
	if (m_hasFerry) {
		cout << "\t 3. take a ferry across" << endl;
		cout << "\t 4. wait to see if conditions improve" << endl;
		cout << "\t 5. get more information" << endl << endl;
	}
	else {
		cout << "\t 3. wait to see if conditions improve" << endl;
		cout << "\t 4. get more information" << endl << endl;
	}

	cout << "\t What is your choice? ";
}

/*
	River::FordRiver()

NAME

	River::FordRiver - Player uses oxen to pull wagon through river

SYNOPSIS

	void Trail::GetRiverDepth()

DESCRIPTION

	This function handles when the player picks the option to ford the river with their oxen. If
	the depth of a river is shallow enough, than they will be successfull in crossing this way, otherwise,
	the player's wagon may sink and lose items.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:31am 2/6/2019
*/
void River::FordRiver(Player &a_player) {

	vector<Item> lostItems;

	for (int i = 0; i < ((int)m_riverWidth / 100); i++) {
		m_utility.OutputMessage("Fording the river...");
		m_utility.Wait();

		// Insert random chance of losing items here
		if (m_riverDepth < 3.00) {
			// 10% of losing items
			if (GenerateRandomNum(0.1)) {
				lostItems = a_player.LoseItems();
				if (lostItems.size() > 0) {
					m_utility.OutputMessage("The river is too deep to");
					m_utility.OutputMessage("ford. You lose:");
				}
				
				for (size_t i = 0; i < lostItems.size(); i++) {
					cout << "\t \t " << lostItems[i].GetName() << ": " << lostItems[i].GetQuantity() << endl;
				}
				break;
			}
		}
		else if (m_riverDepth < 7.00) {
			// 50% of losing items
			if (GenerateRandomNum(0.5)) {
				lostItems = a_player.LoseItems();
				if (lostItems.size() > 0) {
					m_utility.OutputMessage("The river is too deep to");
					m_utility.OutputMessage("ford. You lose:");
				}

				for (size_t i = 0; i < lostItems.size(); i++) {
					cout << "\t \t " << lostItems[i].GetName() << ": " << lostItems[i].GetQuantity() << endl;
				}
				break;
			}
		}
		else {
			// 40% of losing items
			if (GenerateRandomNum(0.4)) {
				lostItems = a_player.LoseItems();
				if (lostItems.size() > 0) {
					m_utility.OutputMessage("The river is too deep to");
					m_utility.OutputMessage("ford. You lose:");
				}

				for (size_t i = 0; i < lostItems.size(); i++) {
					cout << "\t \t " << lostItems[i].GetName() << ": " << lostItems[i].GetQuantity() << endl;
				}
				break;
			}
		}
	}

}

/*
	River::FloatRiver()

NAME

	River::FloatRiver - Player seals their wagon and floats across river

SYNOPSIS

	void Trail::FloatRiver()

DESCRIPTION

	This function handles when the player chooses the option to float across the river. If the river has a very high
	depth, then they will be more successful in floating across then if they tried to ford the river.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:34am 2/6/2019
*/
void River::FloatRiver(Player &a_player) {

	vector<Item> lostItems;
	for (int i = 0; i < ((int)m_riverWidth / 100); i++) {
		m_utility.OutputMessage("Floating on river...");
		m_utility.Wait();

		// Insert random chance of losing items here
		if (m_riverDepth < 3.00) {
			// 50% of losing items
			if (GenerateRandomNum(0.5)) {
				lostItems = a_player.LoseItems();
				if (lostItems.size() > 0) {
					m_utility.OutputMessage("Your wagon tips over and");
					m_utility.OutputMessage("you lose:");
				}

				for (size_t i = 0; i < lostItems.size(); i++) {
					cout << "\t \t " << lostItems[i].GetName() << ": " << lostItems[i].GetQuantity() << endl;
				}
				break;
			}
		}
		else if (m_riverDepth < 7.00) {
			// 10% of losing items
			if (GenerateRandomNum(0.1)) {
				lostItems = a_player.LoseItems();
				if (lostItems.size() > 0) {
					m_utility.OutputMessage("Your wagon tips over and");
					m_utility.OutputMessage("you lose:");
				}

				for (size_t i = 0; i < lostItems.size(); i++) {
					cout << "\t \t " << lostItems[i].GetName() << ": " << lostItems[i].GetQuantity() << endl;
				}
				break;
			}
		}
		else {
			// 40% of losing items
			if (GenerateRandomNum(0.4)) {
				lostItems = a_player.LoseItems();
				if (lostItems.size() > 0) {
					m_utility.OutputMessage("Your wagon tips over and");
					m_utility.OutputMessage("you lose:");
				}

				for (size_t i = 0; i < lostItems.size(); i++) {
					cout << "\t \t " << lostItems[i].GetName() << ": " << lostItems[i].GetQuantity() << endl;
				}
				break;
			}
		}
	}

}

/*
	River::TakeFerry

NAME

	River::TakeFerry - Player uses a ferry to cross the river without fail

SYNOPSIS

	void Trail::TakeFerry(Player &a_player)

	a_player --> player object with all of the player's items

DESCRIPTION

	This function is used when the player wants to take a ferry to cross the river. It handles
	removing $5 from the player's cash if they take the ferry, and then they cross the river safely.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:58am 2/6/2019
*/
bool River::TakeFerry(Player &a_player) {

	string choice;
	bool takeFerry = false;

	while (1) {
		m_utility.OutputMessage("The ferry operator says that");
		m_utility.OutputMessage("he will charge you $5.00 and");
		m_utility.OutputMessage("that you will have to wait 4");
		m_utility.OutputMessage("days. Are you willing to do");
		cout << "\t this? ";
		cin >> choice;

		if (choice == "yes" || choice == "ye" || choice == "y") {
			takeFerry = true;
			a_player.DeductMoney(5.0);
			break;
		}
		else if (choice == "no" || choice == "n") {
			break;
		}
		else {
			m_utility.OutputMessage("Invalid choice.");
		}
	}

	if (takeFerry) {
		m_utility.OutputMessage("Crossing river...");
		m_utility.Wait();

		m_utility.OutputMessage("Crossing river...");
		m_utility.Wait();

		m_utility.OutputMessage("Crossing river...");
		m_utility.Wait();

		m_utility.OutputMessage("The ferry got your party");
		m_utility.OutputMessage("and wagon safely across.");
		m_utility.Wait();
	}

	return takeFerry;
}

/*
	River::WaitADay()

NAME

	River::WaitADay - Increments the day and lessen river conditions

SYNOPSIS

	void Trail::WaitADay(Date &a_date)

	a_date --> date object which contains the current date

DESCRIPTION

	This function increments the day by 1 and lessens the river conditions slightly

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	12:01pm 1/6/2019
*/
void River::WaitADay(Date &a_date) {

	m_utility.OutputMessage("You camp near the river for a day.");
	m_utility.Wait();

	a_date.NextDay();

	if (m_riverDepth > 0.0 && m_riverWidth > 0.0) {
		m_riverDepth -= 0.01;
		m_riverWidth -= 1.0;
	}
}

/*
	River::RiverMoreInfoDialogue()

NAME

	River::RiverMoreInfoDialogue - Outputs the advice for crossing the river

SYNOPSIS

	void River::RiverMoreInfoDialogue

DESCRIPTION

	This function outputs to the console the dialogue for when the player wants to learn more info
	about crossing the river.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	12:04pm 2/6/2019
*/
void River::RiverMoreInfoDialogue() {

	m_utility.OutputMessage("\t To ford a river means to");
	m_utility.OutputMessage("\t pull your wagon across a");
	m_utility.OutputMessage("\t shallow part of the river,");
	m_utility.OutputMessage("\t with the oxen still");
	m_utility.OutputMessage("\t attached.");
	m_utility.Wait();

	m_utility.OutputMessage("To caulk the wagon means to");
	m_utility.OutputMessage("seal it so that no water can");
	m_utility.OutputMessage("get in. The wagon can then");
	m_utility.OutputMessage("be floated across like a");
	m_utility.OutputMessage("boat.");
	m_utility.Wait();

	m_utility.OutputMessage("To use a ferry means to put");
	m_utility.OutputMessage("your wagon on top of a flat");
	m_utility.OutputMessage("boat that belongs to someone");
	m_utility.OutputMessage("else. The owner of the");
	m_utility.OutputMessage("ferry will take your wagon");
	m_utility.OutputMessage("across the river.");
	m_utility.Wait();

}

/*
	River::SetHasFerry(bool a_hasFerry)

NAME

	River::SetHasFerry - Sets the boolean value for if there is a ferry at a river

SYNOPSIS

	void Trail::SetHasFerry(bool a_hasFerry)

	a_hasFerry --> boolean value for if the river has a ferry

DESCRIPTION

	This function sets the boolean value for whether of not a river object has a ferry or not.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	12:07pm 2/6/2019
*/
void River::SetHasFerry(bool a_hasFerry) {
	m_hasFerry = a_hasFerry;
}

/*
	River::GenerateRandomNum(double a_percent)

NAME

	River::GenerateRandomNum - Generates a random number with the percentage passed in

SYNOPSIS

	void Trail::GenerateRandomNum(double a_percent)

	a_percent --> percentage that something will happen

DESCRIPTION

	This function takes in a percentage and multiplies it with the number 10. Then a random number is generated
	and if that number is less than the percentage number, then the function will return true as the random
	number was in the threshold. Otherwise, it will return false since the random number wasn't a hit.

RETURNS

	Bool

AUTHOR

	Nicholas Cockcroft

Date

	2:41pm 2/7/2019
*/
bool River::GenerateRandomNum(double a_percent) {

	int randNum = (rand() % 10) + 1;

	int successNum = (int)(10 * a_percent);

	if (randNum <= successNum) {
		return true;
	}
	else {
		return false;
	}
}