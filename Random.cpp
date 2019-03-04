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
		if (randomNum >= 80) {
			Blizzard(a_player, a_date);
			return;
		}
	}
	else if (a_weather == 4) {
		if (randomNum >= 80) {
			Thunderstorm(a_player, a_date);
			return;
		}
	}

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
		FindAbandonedWagon(a_player);
	}
	else if (randomNum >= 75) {
		BadTrail(a_player, a_date);
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
	Random::FindAbandonedWagon(Player &a_player)

NAME

	Random::FindAbandonedWagon - randomly find extra supplies

SYNOPSIS

	void Random::FindAbandonedWagon(Player &a_player)

	a_player --> main player object from the trail game

DESCRIPTION

	This function will randomly select 1 to 3 items that the player can gain from finding
	an abandoned wagon.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	1:20pm 3/3/2019
*/
void Random::FindAbandonedWagon(Player &a_player) {

	// Determines how many items the player will earn from the abandoned wagon
	int amountOfItemsEarned = (rand() % 3) + 1;

	// This determines which item will be picked
	int randomNum = rand() % 7;

	// This determines the percentage of the quantity of an item the player will recieve
	double amountEarnedPercentage = (double)(rand() % 50) / 100;

	int itemsEarned;

	// Vector of names for the items to be rewarded
	vector<string> itemNames = { "Oxen", "Food", "Clothing", "Ammunition", "Spare parts - wagon wheel" , "Spare parts - wagon axle",
	"Spare parts - wagon tongue" };

	cout << "\t You stumble upon a broken wagon. You find: " << endl; 
	for (int i = 0; i < amountOfItemsEarned; i++) {

		// The amount of an item the player will earned is calculated by the maximum number the player can
	// carry, multiplied by the random percentage calculated earlier
		itemsEarned = (int)(a_player.GetItem(itemNames[randomNum]).GetCapNumber() * amountEarnedPercentage);

		// If the percentage was too low, the player will earn 1 of the item
		if (itemsEarned == 0) {
			itemsEarned = 1;
		}

		// Add to the player's quantity for an item based on the random percentage that was generated times the maximum
		// amount of items the play is allowed to have
		a_player.AddItemQuantity(itemNames[randomNum], itemsEarned);

		cout << "\t \t "<< itemNames[randomNum] << ": " << itemsEarned << endl; 

		// Re calculate a new item for the player to earn
		randomNum = rand() % (7 - (i + 1));

	}
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

/*
	Random::BadTrail(Player &a_player, Date &a_date)

NAME

	Random::BadTrail - randomly picks a number of days the player has to wait

SYNOPSIS

	void Random::BadTrail(Player &a_player, Date &a_date)

	a_player --> main player object from the trail game
	a_date --> object containing the current date from trail game

DESCRIPTION

	This function will randomly pick a number of days the player must wait because they
	were on a bad trail

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:39am 3/3/2019
*/
void Random::BadTrail(Player &a_player, Date &a_date) {

	int randomNum = (rand() % 5) + 1;

	cout << "Lose trail. You lose " << randomNum << " days." << endl;

	for (int i = 0; i < randomNum; i++) {
		a_date.NextDay();
		a_player.DeductFood();
	}
}

/*
	Random::Blizzard(Player &a_player, Date &a_date)

NAME

	Random::Blizzard - randomly picks a number of days the player has to wait

SYNOPSIS

	void Random::Blizzard(Player &a_player, Date &a_date)

	a_player --> main player object from the trail game
	a_date --> object containing the current date from trail game

DESCRIPTION

	This function will randomly pick a number of days the player must wait because they
	were trapped in a blizzard

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:54am 3/3/2019
*/
void Random::Blizzard(Player &a_player, Date &a_date) {

	int randomNum = (rand() % 7) + 1;

	m_utility.OutputMessage("Due to the freezing weather, you get");
	cout << "\t delayed by a blizzard. Lose " << randomNum << " days." << endl << endl;

	// Advance the day and have the player eat food for however many random number of days
	for (int i = 0; i < randomNum; i++) {

		if (randomNum - i == 1) {
			cout << "\t Trapped in the blizzard for " << randomNum - i << " day..." << endl;
		}
		else {
			cout << "\t Trapped in the blizzard for " << randomNum - i << " days..." << endl;
		}
		m_utility.Wait();

		a_date.NextDay();
		a_player.DeductFood();

	}

	m_utility.OutputMessage("The blizzard has passed...");
}

/*
	Random::Thunderstorm(Player &a_player, Date &a_date)

NAME

	Random::Thunderstorm - randomly picks a number of days the player has to wait

SYNOPSIS

	void Random::Thunderstorm(Player &a_player, Date &a_date)

	a_player --> main player object from the trail game
	a_date --> object containing the current date from trail game

DESCRIPTION

	This function will randomly pick a number of days the player must wait because they
	were stuck in a thunderstorm.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	11:55am 3/3/2019
*/
void Random::Thunderstorm(Player &a_player, Date &a_date) {

	int randomNum = (rand() % 7) + 1;

	m_utility.OutputMessage("Due to the brutal weather, you get");
	cout << "\t delayed by thunderstorm. Lose " << randomNum << " days." << endl;

	for (int i = 0; i < randomNum; i++) {

		if (randomNum - i == 1) {
			cout << "\t Trapped in the storm for " << randomNum - i << " day..." << endl;
		}
		else {
			cout << "\t Trapped in the storm for " << randomNum - i << " days..." << endl;
		}
		m_utility.Wait();

		a_date.NextDay();
		a_player.DeductFood();

	}

	m_utility.OutputMessage("The storm as passed...");
}

/*
	Random::DevelopeDisease(Player &a_player)

NAME

	Random::DevelopeDisease - randomly picks a member of the player's party to get sick

SYNOPSIS

	void Random::DevelopeDisease(Player &a_player)

	a_player --> main player object from the trail game

DESCRIPTION

	This function will randomly pick a member of the player's party and assign them some kind of disease.
	Some of them include dysentary, broken arm, ect.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	12:42pm 3/3/2019
*/
void Random::DevelopDisease() {

}

/*
	Random::BrokenWagonPartHelper(Player &a_player, string a_itemName)

NAME

	Random::BrokenWagonPartHelper - handle user input for fixing wagon part

SYNOPSIS

	void Random::BrokenWagonPartHelper(Player &a_player, string a_itemName)

	a_player --> main player object from the trail game
	a_itemName --> the name of the item that broke

DESCRIPTION

	This function will prompt the user if they want to fix a part of their wagon that broke. It will
	then randomly pick if the player can repair the part or not. 

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	1:18pm 3/3/2019
*/
void Random::BrokenWagonPartHelper(Player &a_player, string a_itemName) {

	string choice;
	int randomNum = rand() % 2;

	cin >> choice;

	// If the player wants to try and fix the wagon part...
	if (choice == "yes" || choice == "ye" || choice == "y") {

		// If successful, they won't have to use a spare part
		if (randomNum == 0) {
			m_utility.OutputMessage("You were able to fix the broken wagon wheel.");
		}
		// Otherwise, they will have to use a spare part if they have one
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
	// If the player said no, the player will have to use a spare part if they have one
	else {
		if (a_player.GetItem("Spare parts - wagon wheel").GetQuantity() > 0) {
			a_player.SetItemQuantity(a_itemName, a_player.GetItem("Spare parts - wagon wheel").GetQuantity() - 1);
		}
		else {
			// Broken wagon wheel - significantly hurt player's health
		}
	}
}