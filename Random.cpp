#include "Random.h"



Random::Random()
{
	srand((unsigned int)time(0));
}

void Random::RandomEvent(Player &a_player) {

	int randomNum = rand() % 100;

	randomNum = 92;
	if (randomNum >= 95) {
		FindWildFruit(a_player);
	}
	else if (randomNum >= 90) {
		StolenGoods(a_player);
	}
	else if (randomNum >= 85) {
		BrokenWagonPart();
	}
	else if (randomNum >= 80) {
		RainWashedPath();
	}
	else if (randomNum >= 75) {
		BadTrail();
	}
	else if (randomNum >= 70) {
		Blizzard();
	}
	else if (randomNum >= 65) {
		DevelopDisease();
	}
	else {

	}
}

void Random::FindWildFruit(Player &a_player) {

	int randomNum = (rand() % 7) + 2;

	a_player.AddItemQuantity("Food", 20 * randomNum);

	m_utility.OutputMessage("You find a fruit tree.");
	cout << "\t You managed to pick " << 20 * randomNum << endl;
	cout << "\t pounds of food." << endl;


}

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

void Random::BrokenWagonPart() {

}

void Random::RainWashedPath() {

}

void Random::BadTrail() {

}

void Random::Blizzard() {

}

void Random::DevelopDisease() {

}