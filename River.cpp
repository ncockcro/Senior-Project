#include "River.h"



River::River()
{
	srand((unsigned int)time(0));

	uniform_real_distribution<double> unif(0.1, 10.0);
	default_random_engine re;
	re.seed(time(0));
	m_riverDepth = unif(re);

	uniform_real_distribution<double> unif2(100.0, 400.0);
	default_random_engine re2;
	re2.seed(time(0));
	m_riverLength = unif2(re2);

	m_hasFerry = false;
}

void River::CrossLocation(Player a_player, Date &a_date, int a_weather) {

	string choice;

	OpeningDialogue();

	while (1) {
		cout << "\t " << a_date.GetMonth() << " " << a_date.GetDay() << ", " << a_date.GetYear() << endl << endl;
		ShowRiverMenu(m_utility.GetWeatherName(a_weather));
		cin >> choice;

		// If the player wants to ford the river with their wagon
		if (choice == "1") {
			if (FordRiver(a_player)) {
				break;
			}
		}
		// If the player wants to try and float across the river
		else if (choice == "2") {
			if (FloatRiver(a_player)) {
				break;
			}
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
	River::GetRiverLength()

NAME

	River::GetRiverLength - Returns the length of a river object

SYNOPSIS

	double River::GetRiverLength()

DESCRIPTION

	The function returns the length of a river object.

RETURNS

	Double

AUTHOR

	Nicholas Cockcroft

Date

	10:27pm 1/30/2019
*/
double River::GetRiverLength() {
	return m_riverLength;
}

/*
	River::GetRiverDepth()

NAME

	River::GetRiverDepth - Returns the depth of a river object

SYNOPSIS

	void Trail::GetRiverDepth()

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

void River::OpeningDialogue() {

	m_utility.OutputMessage("You must cross the river in");
	m_utility.OutputMessage("order to continue. The");
	m_utility.OutputMessage("river at this point is");
	cout << "\t currently " << m_riverLength << " feet across," << endl;
	cout << "\t and " << m_riverDepth << " feet deep in the" << endl;
	m_utility.OutputMessage("middle.");
	cout << endl;
	m_utility.Wait();
}

void River::ShowRiverMenu(string a_weather) {

	cout << "\t Weather: " << a_weather << endl;
	cout << "\t River width: " << m_riverLength << endl;
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

bool River::FordRiver(Player &a_player) {

	return true;
}

bool River::FloatRiver(Player &a_player) {

	cout << "Actual length: " << m_riverLength << endl;
	cout << "Modula length: " << (int)m_riverLength / 100 << endl;
	for (int i = 0; i < ((int)m_riverLength / 100); i++) {
		m_utility.OutputMessage("Floating on river...");
		m_utility.Wait();

		// Insert random chance of losing items here
	}

	return true;
}

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

void River::WaitADay(Date &a_date) {

	m_utility.OutputMessage("You camp near the river for a day.");
	m_utility.Wait();

	a_date.NextDay();

	if (m_riverDepth > 0.0 && m_riverLength > 0.0) {
		m_riverDepth -= 0.01;
		m_riverLength -= 1.0;
	}
}
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

void River::SetHasFerry(bool a_hasFerry) {
	m_hasFerry = a_hasFerry;
}