#include "River.h"



River::River()
{
	srand((unsigned int)time(0));

	uniform_real_distribution<double> unif(0.1, 10.0);
	default_random_engine re;
	m_riverDepth = unif(re);

	uniform_real_distribution<double> unif2(100.0, 400.0);
	default_random_engine re2;
	m_riverLength = unif2(re2);

	m_hasFerry = false;
}

void River::CrossLocation(string a_weather) {

	string choice;

	OpeningDialogue();

	while (1) {
		ShowRiverMenu(a_weather);
		cin >> choice;

		if (choice == "1") {

		}
		else if (choice == "2") {

		}
		else if (m_hasFerry && choice == "3") {
			TakeFerry();
		}
		else if (!m_hasFerry && choice == "3") {

		}
		else if (m_hasFerry && choice == "4") {
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

	cout << "What is your choice? ";
}

void River::TakeFerry() {

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
			break;
		}
		else if (choice == "no" || choice == "n") {
			break;
		}
		else {
			m_utility.OutputMessage("Invalid choice.");
		}
	}

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