#include "Random.h"

/*
	Random::Random()

NAME

	Random::Random - Default constructor

SYNOPSIS

	Random::Random()

DESCRIPTION

	Default constructor for the random class.

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	3:38pm 3/2/2019
*/
Random::Random()
{
	srand((unsigned int)time(0));
}

/*
	Random::RandomEvent(Player &a_player)

NAME

	Random::RandomEvent - Randomly chooses a random event to happen

SYNOPSIS

	void Random::RandomEvent(Player &a_player)

	a_player --> the player object from the main trail game

DESCRIPTION

	This function will generate a random number and if it falls within the range of a random event
	to happen, it will call the appropriate function to cause the random event. There is a greater
	chance that nothing will happen that way there aren't random events always happening throughout the game.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	3:44pm 3/2/2019
*/
void Random::RandomEvent(Player &a_player, Date &a_date, int a_weather) {

	int randomNum = rand() % 100;

	// If the weather is cold, higher chance for a blizzard
	if (a_weather == 0) {
		if (randomNum >= 50) {
			Blizzard(a_player, a_date);
		}
	}
	else if (a_weather == 4) {
		if (randomNum >= 50) {
			Thunderstorm(a_player, a_date);
		}
	}

	randomNum = 86;
	if (randomNum >= 95) {
		FindWildFruit(a_player);
	}
	else if (randomNum >= 90) {
		StolenGoods(a_player);
	}
	else if (randomNum >= 85) {
		BrokenWagonPart(a_player);
	}
	else if (randomNum >= 80) {
		RainWashedPath();
	}
	else if (randomNum >= 75) {
		BadTrail();
	}
	else if (randomNum >= 70) {
		DevelopDisease();
	}
	else {

	}
}

/*
	Random::FindWildFruit(Player &a_player)

NAME

	Random::FindWildFruit - randomly generates a random amount of food for the player

SYNOPSIS

	void Random::FindWildFruit(Player &a_player)

	a_player --> main player object from the trail game

DESCRIPTION

	This function will randomly generate a multiplier between 2 and 9 and times that by 20 to give the
	player a certain amount of food

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	3:46pm 3/2/2019
*/
void Random::FindWildFruit(Player &a_player) {

	int randomNum = (rand() % 7) + 2;

	a_player.AddItemQuantity("Food", 20 * randomNum);

	m_utility.OutputMessage("You find a fruit tree.");
	cout << "\t You managed to pick " << 20 * randomNum << endl;
	cout << "\t pounds of food." << endl;


}

/*
	Random::StolenGoods(Player &a_player)

NAME

	Random::StolenGoods - player loses a certain amount of items

SYNOPSIS

	void Random::StolenGoods(Player &a_player)

	a_player --> main player object from the trail game

DESCRIPTION

	This function will cause the player to lose a certain amount of items from their inventory.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	3:47houseatlyncrestwas16
	4:01pm 3/2/2019
*/
void Random::StolenGoods(Player &a_player) {

	vector<Item> lostItems = a_player.LoseItems();

	if (lostItems.size() > 0) {
		m_utility.OutputMessage("A thief came in the middle");
		m_utility.OutputMessage("of the night and took: ");
	}
	
	for (size_t i = 0; i < lostItems.size(); i++) {
		cout << "\t \t " << lostItems[i].GetName() << ": " << lostItems[i].GetQuantity() << endl;
	}
}

/*
	Random::BrokenWagonPart(Player &a_player)

NAME

	Random::BrokenWagonPart - randomly breaks a part of the players wagon

SYNOPSIS

	void Random::BrokenWagonPart(Player &a_player)

	a_player --> main player object from the trail game

DESCRIPTION

	This function will randomly pick a piece from the player's wagon to break.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	3:21pm 3/2/2019
*/
void Random::BrokenWagonPart(Player &a_player) {

	int randomNum = rand() % 3;

	// Broken wheel
	if(randomNum == 2) {
		m_utility.OutputMessage("Broken wagon wheel. Would you like");
		cout << "\t to try to repair it?";
		
		BrokenWagonPartHelper(a_player, "Spare parts - wagon wheel");

	}
	// Broken axle
	else if (randomNum == 1) {
	
		m_utility.OutputMessage("Broken wagon axle. Would you like");
		cout << "\t to try to repair it?";

		BrokenWagonPartHelper(a_player, "Spare parts - wagon axle");
	}
	// Broken tongue
	else if (randomNum == 0) {

		m_utility.OutputMessage("Broken wagon tongue. Would you like");
		cout << "\t to try to repair it?";

		BrokenWagonPartHelper(a_player, "Spare parts - wagon tongue");
	}
	else {
		m_utility.DisplayError("ERROR: Error in getting a random number in BrokenWagonPart()");
	}
}

void Random::RainWashedPath() {

}

void Random::BadTrail() {

}

void Random::Blizzard(Player &a_player, Date &a_date) {

	int randomNum = (rand() % 7) + 1;

	m_utility.OutputMessage("Due to the freezing weather, you get");
	m_utility.OutputMessage("delayed by a blizzard.");

	for (int i = 0; i < randomNum; i++) {
		a_date.NextDay();
		a_player.DeductFood();
	}
}

void Random::Thunderstorm(Player &a_player, Date &a_date) {

	int randomNum = (rand() % 7) + 1;

	m_utility.OutputMessage("Due to the brutal weather, you get");
	m_utility.OutputMessage("delayed by thunderstorms.");

	for (int i = 0; i < randomNum; i++) {
		a_date.NextDay();
		a_player.DeductFood();
	}
}

void Random::DevelopDisease() {

}

void Random::BrokenWagonPartHelper(Player &a_player, string a_itemName) {

	string choice;
	int randomNum = rand() % 2;

	cin >> choice;

	if (choice == "yes" || choice == "ye" || choice == "y") {
		if (randomNum == 0) {
			m_utility.OutputMessage("You were able to fix the broken wagon wheel.");
		}
		else {
			m_utility.OutputMessage("You were unsuccessful in repairing.");

			if (a_player.GetItem("Spare parts - wagon wheel").GetQuantity() > 0) {
				a_player.SetItemQuantity(a_itemName, a_player.GetItem("Spare parts - wagon wheel").GetQuantity() - 1);
			}
			else {
				// Broken wagon wheel - significantly hurt player's health
			}
		}
	}
	else {
		if (a_player.GetItem("Spare parts - wagon wheel").GetQuantity() > 0) {
			a_player.SetItemQuantity(a_itemName, a_player.GetItem("Spare parts - wagon wheel").GetQuantity() - 1);
		}
		else {
			// Broken wagon wheel - significantly hurt player's health
		}
	}
}