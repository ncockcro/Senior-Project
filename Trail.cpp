#include "Trail.h"



Trail::Trail()
{
}


Trail::~Trail()
{
}

void Trail::ActiveGame() {
	PromptPosition();

}

void Trail::PromptPosition() {
	
	string positionChoice;

	while (1) {
		cout << "\t Many kinds of people made the trip to Oregon." << endl;
		cout << "\t You may:" << endl;

		cout << "\t 1. Be a banker from Boston" << endl;
		cout << "\t 2. Be a carpenter from Ohio" << endl;
		cout << "\t 3. Be a farmer from Illinois" << endl;
		cout << "\t 4. Find out the differences between these choices" << endl << endl;
		cout << "\t What is your choice? ";
		cin >> positionChoice;

		if (positionChoice == "1" || positionChoice == "2" || positionChoice == "3" || positionChoice == "4") {
			break;
		}
	}

	
}
