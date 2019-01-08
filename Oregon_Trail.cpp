#include "Oregon_Trail.h"



Oregon_Trail::Oregon_Trail()
{
}


Oregon_Trail::~Oregon_Trail()
{
}

void Oregon_Trail::StartGame() {

	ShowTitle();

	while (1) {
		cout << "     You may:" << endl;
		cout << "\t 1. Travel the trail" << endl;
		cout << "\t 2. Learn about the trail" << endl;
		cout << "\t 3. See the Oregon Top Ten" << endl;
		cout << "\t 4. Turn sound off" << endl;
		cout << "\t 5. Choose management options" << endl;
		cout << "\t 6. End" << endl;
		PickDecision();
	}
}

void Oregon_Trail::ShowTitle() {

	ifstream file;
	string input;
	file.open("title.txt");

	while (getline(file, input)) {

		cout << input;
		cout << endl;
	}
	cout << endl;
}

void Oregon_Trail::PickDecision() {

	string choice;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << "\t What is your choice: ";
	cin >> choice;

	if (choice == "1") {
		cout << "Playing game" << endl;
	}
	else if (choice == "2") {
		ShowDescription();
	}
	else if (choice == "3") {
		cout << "Seeing the leaderboards" << endl;
	}
	else if (choice == "4") {
		cout << "There is no sound!" << endl;
	}
	else if (choice == "5") {
		cout << "Checking options" << endl;
	}
	else if (choice == "6") {
		exit(1);
	}
	else {
		system("cls");
		SetConsoleTextAttribute(hConsole, 12);
		cout << "\t That was an incorrect option" << endl;
		SetConsoleTextAttribute(hConsole, 7);
	}
}

void Oregon_Trail::ShowDescription() {

	cout << "\t Oregon trail is roughly a 2000 mile route from Independence, Missouri, to Oregon City, Oregon. " << endl;
	cout << "\t The trail is riddled with disease, snakebites, hostile Native Americans, and various other dangers." << endl;
	cout << "\t You can start as being a banker from Boston, a carpenter from Ohio, or a farmer from Illinois." << endl;
	cout << "\t Each will determine the difficulty of the trail by the starting amount of money you will recieve." << endl;
	cout << "\t At the start of the game, you will be able to purchase goods for your travels. As you move on the trail, " << endl;
	cout << "\t there will be more shops on the way, but will become scarcer the farther along the trail you are." << endl;
	cout << "\t Will you make the Oregon trail?" << endl;
	cout << "\t ";
	system("pause");
}
