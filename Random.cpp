#include "Random.h"

/*
	Random::Random()

NAME

	Random::Random - Default constructor

SYNOPSIS

	Random::Random()

DESCRIPTION

	Default constructor for the random class.

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

AUTHOR

	Nicholas Cockcroft

Date

	3:44pm 3/2/2019
*/
void Random::RandomEvent(Player &a_player, Date &a_date) {

	int randomNum = rand() % 100;

	// If the temperature is cold outside, and the player doesn't have enough clothing for every member...
	if (a_date.GetWeather() == 0 && (size_t)a_player.GetItem("Clothing").GetQuantity() < (a_player.GetWagonParty().size() + 1)) {
		NotEnoughClothing(a_player);
	}

	if (a_player.GetHealth() == 0) {
		if (randomNum >= 60) {
			DevelopeDisease(a_player);
		}
	}

	// If the weather is cold, there is a chance for a blizzard
	if (a_date.GetWeather() == 0) {
		if (randomNum >= 90) {
			Blizzard(a_player, a_date);
			return;
		}
	}
	// If the weather is hot, there is a chance for a thunderstorm
	else if (a_date.GetWeather() == 4) {
		if (randomNum >= 90) {
			Thunderstorm(a_player, a_date);
			return;
		}
	}

	// Get food from a wild fruit tree
	if (randomNum >= 96) {
		FindWildFruit(a_player);
	}
	// Thief steals goods
	else if (randomNum >= 94) {
		StolenGoods(a_player);
	}
	// Get a broken wagon part
	else if (randomNum >= 92) {
		BrokenWagonPart(a_player);
	}
	// Find supplies from an abandoned wagon
	else if (randomNum >= 89) {
		FindAbandonedWagon(a_player);
	}
	// Get lost on the bad trail
	else if (randomNum >= 87) {
		BadTrail(a_player, a_date);
	}
	else if (randomNum >= 85) {
		WagonFire(a_player);
	}
	// Small chance for developing a disease
	else if (randomNum >= 83) {
		DevelopeDisease(a_player);
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

AUTHOR

	Nicholas Cockcroft

Date

	3:46pm 3/2/2019
*/
void Random::FindWildFruit(Player &a_player) {

	int randomNum = (rand() % 7) + 2;
	int foodEarned = 20 * randomNum;

	a_player.AddItemQuantity("Food", foodEarned);

	m_utility.OutputWithColor("You find a fruit tree.", 10);
	m_utility.OutputWithColor("You managed to pick " + to_string(foodEarned) + " pounds of food.", 10);


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

	m_utility.OutputWithColor("You stumble upon a broken wagon. You find: ", 10);
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

		m_utility.OutputWithColor("\t " + itemNames[randomNum] + ": " + to_string(itemsEarned), 10);

		// Re calculate a new item for the player to earn
		itemNames.erase(itemNames.begin() + randomNum);
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

AUTHOR

	Nicholas Cockcroft

Date

	4:01pm 3/2/2019
*/
void Random::StolenGoods(Player &a_player) {

	vector<Item> lostItems = a_player.LoseItems();

	if (lostItems.size() > 0) {
		m_utility.OutputWithColor("A thief came in the middle", 12);
		m_utility.OutputWithColor("of the night and took: ", 12);
	}
	
	for (size_t i = 0; i < lostItems.size(); i++) {
		m_utility.OutputWithColor("\t " + lostItems[i].GetName() + ": " + to_string(lostItems[i].GetQuantity()), 12);
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

AUTHOR

	Nicholas Cockcroft

Date

	11:39am 3/3/2019
*/
void Random::BadTrail(Player &a_player, Date &a_date) {

	int randomNum = (rand() % 5) + 1;

	m_utility.OutputWithColor("Lose trail. You lose " + to_string(randomNum) + " days.", 12);

	for (int i = 0; i < randomNum; i++) {

		m_utility.Wait();

		if (randomNum - i == 1) {
			m_utility.OutputWithColor("Still lost for " + to_string(randomNum - i) + " day...", 12);
		}
		else {
			m_utility.OutputWithColor("Still lost for " + to_string(randomNum - i) + " days...", 12);
		}

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

AUTHOR

	Nicholas Cockcroft

Date

	11:54am 3/3/2019
*/
void Random::Blizzard(Player &a_player, Date &a_date) {

	int randomNum = (rand() % 7) + 1;

	m_utility.OutputWithColor("Due to the freezing weather, you get", 12);
	m_utility.OutputWithColor("delayed by a blizzard. Lose " + to_string(randomNum) + " days.", 12);
	cout << endl;

	// Advance the day and have the player eat food for however many random number of days
	for (int i = 0; i < randomNum; i++) {

		if (randomNum - i == 1) {
			m_utility.OutputWithColor("Trapped in the blizzard for " + to_string(randomNum - i) + " day...", 12);
		}
		else {
			m_utility.OutputWithColor("Trapped in the blizzard for " + to_string(randomNum - i) + " days...", 12);
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

AUTHOR

	Nicholas Cockcroft

Date

	11:55am 3/3/2019
*/
void Random::Thunderstorm(Player &a_player, Date &a_date) {

	int randomNum = (rand() % 7) + 1;

	m_utility.OutputWithColor("Due to the brutal weather, you get", 12);
	m_utility.OutputWithColor("delayed by thunderstorm. Lose " + to_string(randomNum) + " days.", 12);

	for (int i = 0; i < randomNum; i++) {

		if (randomNum - i == 1) {
			m_utility.OutputWithColor("Trapped in the storm for " + to_string(randomNum - i) + " day...", 12);
		}
		else {
			m_utility.OutputWithColor("Trapped in the storm for " + to_string(randomNum - i) + " days...", 12);
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

AUTHOR

	Nicholas Cockcroft

Date

	12:42pm 3/3/2019
*/
void Random::DevelopeDisease(Player &a_player) {

	int sizeOfParty = a_player.GetWagonParty().size();
	int randomNum;
	string playersDisease;
	string temp;

	// Avoiding a divide by zero...
	if (sizeOfParty > 0) {
		randomNum = rand() % sizeOfParty;
	}

	// If there is a member in the wagon party, they develope a disease first
	if (a_player.GetWagonParty().size() > 0) {
		a_player.GetWagonParty()[randomNum].AddDisease(PickRandomDisease(a_player.GetWagonParty()[randomNum].GetDiseases()));
		playersDisease = a_player.GetWagonParty()[randomNum].GetName() + " has " + a_player.GetWagonParty()[randomNum].GetLastDisease();
		m_utility.OutputWithColor(playersDisease, 11);
		cout << endl;

		if (a_player.GetWagonParty()[randomNum].CheckIfDead()) {

			temp = a_player.GetWagonParty()[randomNum].GetName() + " has died.";
			m_utility.DisplayError(temp);
			a_player.RemovePlayer(randomNum);
		}
	}
	// Otherwise, all of the wagon members are dead and then the wagon leader develops a disease
	else {
		a_player.GetWagonLeader().AddDisease(PickRandomDisease(a_player.GetWagonLeader().GetDiseases()));
		playersDisease = a_player.GetWagonLeader().GetName() + " has " + a_player.GetWagonLeader().GetLastDisease();
		m_utility.OutputWithColor(playersDisease, 11);
		cout << endl;

		// If the wagon leader is dead, then that means all of the members are dead
		if (a_player.GetWagonLeader().CheckIfDead()) {

			temp = a_player.GetWagonLeader().GetName() + ", your wagon leader, has died.";
			m_utility.DisplayError(temp);
			m_utility.Wait();

			m_utility.DisplayError("Oh dear, all of your party members have passed.");
			m_utility.DisplayError("You never made it to Oregon. You and about");
			m_utility.DisplayError("15,000 other pioneers never made it past the trail.");
		}
	}
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
	if (m_utility.LowerCaseString(choice) == "yes" || m_utility.LowerCaseString(choice) == "ye" || m_utility.LowerCaseString(choice) == "y") {

		// If successful, they won't have to use a spare part
		if (randomNum == 0) {
			m_utility.OutputWithColor("You were able to fix the broken wagon wheel.", 10);
			cout << endl;
		}
		// Otherwise, they will have to use a spare part if they have one
		else {
			m_utility.OutputWithColor("You were unsuccessful in repairing.", 12);

			if (a_player.GetItem(a_itemName).GetQuantity() > 0) {

				a_player.SetItemQuantity(a_itemName, a_player.GetItem(a_itemName).GetQuantity() - 1);
				m_utility.OutputWithColor("You use a spare " + m_utility.GetExtraPartSimpleName(a_itemName) + ".", 11);
				cout << endl;
			}
			else {
				// Broken wagon wheel - significantly hurt player's health
				a_player.DecreaseHealthOutOfHundred(100);

				cout << endl;
				m_utility.OutputWithColor("You get significantly hurt searching around", 12);
				m_utility.OutputWithColor("for a " + m_utility.GetExtraPartSimpleName(a_itemName) + " since", 12);
				m_utility.OutputWithColor("you did not have the extra part!", 12);
				cout << endl;
			}
		}
	}
	// If the player said no, the player will have to use a spare part if they have one
	else {
		if (a_player.GetItem(a_itemName).GetQuantity() > 0) {
			a_player.SetItemQuantity(a_itemName, a_player.GetItem(a_itemName).GetQuantity() - 1);

			m_utility.OutputWithColor("You use a spare " + m_utility.GetExtraPartSimpleName(a_itemName) + ".", 11);
			cout << endl;
		}
		else {
			// Broken wagon wheel - significantly hurt player's health
			a_player.DecreaseHealthOutOfHundred(100);

			cout << endl;
			m_utility.OutputWithColor("You get significantly hurt searching around", 12);
			m_utility.OutputWithColor("for a " + m_utility.GetExtraPartSimpleName(a_itemName) + " since", 12);
			m_utility.OutputWithColor("you did not have the extra part!", 12);
			cout << endl;
		}
	}
}

/*
	Random::PickRandomDisease(vector<string> a_currentDisease)

NAME

	Random::PickRandomDisease - Picks a random disease the player doesn't have

SYNOPSIS

	string Random::PickRandomDisease(vector<string> a_currentDiseases)

	a_currentDiseases --> current disease a particular member has

DESCRIPTION

	This function will randomly pick a disease that a party member doesn't have and return it.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	11:51am 3/11/2019
*/
string Random::PickRandomDisease(vector<string> a_currentDiseases) {

	vector<string> diseases = { "cholera", "exhaustion", "a broken arm", "a broken leg", "measles", "typhoid", "dysentery" };
	vector<int> deleteDisease;

	// Cycle through the diseases pass in and the list of available diseases...
	for (size_t i = 0; i < a_currentDiseases.size(); i++) {
		for (size_t j = 0; j < diseases.size(); j++) {

			// If there is a match, track the index so the disease can be deleted so the
			// wagon member does not get the same disease twice
			if (a_currentDiseases[i] == diseases[j]) {
				deleteDisease.push_back(j);
				break;
			}
		}
	}

	// Sort array so we delete the diseases from the end of the vector first 
	sort(deleteDisease.rbegin(), deleteDisease.rend());

	// Cycle through the diseases and remove the ones the party member already has...
	for (size_t i = 0; i < deleteDisease.size(); i++) {
		diseases.erase(diseases.begin() + deleteDisease[i]);
	}

	// Finally, randomly pick a disease and return it
	int randomNum = rand() % diseases.size();
	return diseases[randomNum];
}

/*
	Random::NotEnoughClothing(Player &a_player)

NAME

	Random::NotEnoughClothing - Damages the player's health if they don't have clothing for each member

SYNOPSIS

	void Random::NotEnoughClothing(Player &a_player)

	a_player --> the player object used in the main trail game

DESCRIPTION

	This function will check which rate the player is eating food at and decrease their health
	accordingly.

AUTHOR

	Nicholas Cockcroft

Date

	11:51am 4/1/2019
*/
void Random::NotEnoughClothing(Player &a_player) {

	// Depending on the rate the player is eating at, the player should still be losing health from the cold
	if (a_player.GetFoodRate() == "filling") {
		a_player.DecreaseHealthOutOfHundred(15);
	}
	else if (a_player.GetFoodRate() == "meager") {
		a_player.DecreaseHealthOutOfHundred(12);
	}
	else {
		a_player.DecreaseHealthOutOfHundred(9);
	}

	m_utility.OutputWithColor("The freezing weather hurts your party members.", 12);
	m_utility.OutputWithColor("You should buy more clothing.", 12);
	cout << endl;
}

/*
	Random::WagonFire(Player &a_player)

NAME

	Random::WagonFire - Player will randomly lose items from a wagon fire

SYNOPSIS

	void Random::WagonFire(Player &a_player)

	a_player --> the player object used in the main trail game

DESCRIPTION

	This function output that a wildfire broke out in the player's wagon and has
	the player lose items.

AUTHOR

	Nicholas Cockcroft

Date

	10:06am 4/9/2019
*/
void Random::WagonFire(Player &a_player) {

	vector<Item> lostItems = a_player.LoseItems();

	if (lostItems.size() > 0) {
		m_utility.OutputWithColor("A wildfire broke out in", 12);
		m_utility.OutputWithColor("your wagon! You lose: ", 12);
	}

	for (size_t i = 0; i < lostItems.size(); i++) {
		m_utility.OutputWithColor("\t " + lostItems[i].GetName() + ": " + to_string(lostItems[i].GetQuantity()), 12);
	}
}