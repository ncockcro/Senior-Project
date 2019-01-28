#include "Dialogue.h"



Dialogue::Dialogue()
{
	srand(time(0));
}


Dialogue::~Dialogue()
{
}

void Dialogue::TalkToPeople(string a_location) {

	if (a_location == "Independence") {
		Independence();
	}
	else if (a_location == "Kansas River crossing") {
		KRiverCrossing();
	}
	else if (a_location == "Big Blue River crossing") {
		BBlueRiverCrossing();
	}
	else {
		m_utility.DisplayError("Invalid location for dialogue.");
	}

	if (m_randomNum == 2) {
		m_randomNum = 0;
	}
	else {
		m_randomNum++;
	}

	m_utility.Wait();
}

void Dialogue::Independence() {

	m_randomNum = rand() % 3;

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A town resident tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Some folks seem to think that");
		m_utility.OutputMessage("two oxen are enough to get them");
		m_utility.OutputMessage("to Oregon! Tow oxen can barely");
		m_utility.OutputMessage("move a fully loaded wagon, and");
		m_utility.OutputMessage("if one of them gets sick or");
		m_utility.OutputMessage("dies, you won't be going");
		m_utility.OutputMessage("anywhere. I wouldn't go");
		m_utility.OutputMessage("overland with less than six.\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A trader named Jim tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Better take extra sets of");
		m_utility.OutputMessage("clothing. Trade 'em to Indians");
		m_utility.OutputMessage("for fresh vegetables, fish, or");
		m_utility.OutputMessage("meat. It's well worth hiring");
		m_utility.OutputMessage("an Indian guide at river");
		m_utility.OutputMessage("crossings. Expect to pay them!");
		m_utility.OutputMessage("They're sharp traders, not");
		m_utility.OutputMessage("easily cheated.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("A traveler, Miles Hendericks,");
		m_utility.OutputMessage("tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Did you read the Missouri");
		m_utility.OutputMessage("Republicans today? --Says some");
		m_utility.OutputMessage("folk start for Oregon without");
		m_utility.OutputMessage("meat. It's well worth hiring");
		m_utility.OutputMessage("carrying spare parts, not even");
		m_utility.OutputMessage("an extra wagon axle. Must");
		m_utility.OutputMessage("think they grow on trees! Hope");
		m_utility.OutputMessage("they're lucky enough to find an");
		m_utility.OutputMessage("abandoned wagon.\"");
	}
	else {
		m_utility.DisplayError("ERROR: Wrong number for dialougue.");
	}
}

void Dialogue::KRiverCrossing() {

	m_randomNum = rand() % 3;

	if (m_randomNum == 0) {
		m_utility.OutputMessage("A stranger tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Can't afford to take a ferry.");
		m_utility.OutputMessage("Were making our wagon into a");
		m_utility.OutputMessage("boat. We'll turn it over,");
		m_utility.OutputMessage("caulk the bottom and sides with");
		m_utility.OutputMessage("pitch, and use it to float our");
		m_utility.OutputMessage("goods across. Have to swim the");
		m_utility.OutputMessage("animals. Hope it doesn't rain");
		m_utility.OutputMessage("-- the river's high enough!\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A ferry operator tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Don't try to ford any river");
		m_utility.OutputMessage("deeper than the wagon bed --");
		m_utility.OutputMessage("about two and half feet.");
		m_utility.OutputMessage("You'll swamp your wagon and");
		m_utility.OutputMessage("lose your supplies. You can");
		m_utility.OutputMessage("caulk the wagon bed and float");
		m_utility.OutputMessage("it -- or be smart and hire me");
		m_utility.OutputMessage("to take your wagon on my");
		m_utility.OutputMessage("ferry!\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("Aunt Rebecca Sims tells you:");
		cout << endl;
		m_utility.OutputMessage("\"With the crowds of people");
		m_utility.OutputMessage("waiting to get on the ferry, we");
		m_utility.OutputMessage("could be stranded here for");
		m_utility.OutputMessage("days! Hope theres enough");
		m_utility.OutputMessage("graze for all those animals --");
		m_utility.OutputMessage("not many people carry feed!");
		m_utility.OutputMessage("I'd rather wait, though, than");
		m_utility.OutputMessage("cross in a rickety wagon boat!\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number for K River Crossing.");
	}

}

void Dialogue::BBlueRiverCrossing() {

	m_randomNum = rand() % 3;

	if (m_randomNum == 0) {
		m_utility.OutputMessage("Big Louie, a trail driver,");
		m_utility.OutputMessage("tells you:");
		cout << endl;
		m_utility.OutputMessage("\"Be careful you don't push");
		m_utility.OutputMessage("those animals too hard! Keep");
		m_utility.OutputMessage("'em moving but set them a fair");
		m_utility.OutputMessage("pace. Can't keep driving 'em");
		m_utility.OutputMessage("so fast or you'll end up with");
		m_utility.OutputMessage("lame-footed animals. A lame ox");
		m_utility.OutputMessage("is about as good to you as a");
		m_utility.OutputMessage("dead one!\"");
	}
	else if (m_randomNum == 1) {
		m_utility.OutputMessage("A party leader heading east");
		m_utility.OutputMessage("tells you:");
		cout << endl;
		m_utility.OutputMessage("\"We've had enough! Pesky flies");
		m_utility.OutputMessage("all day and mosquitoes all");
		m_utility.OutputMessage("night! It's either baking sun");
		m_utility.OutputMessage("or oceans of mud -- and");
		m_utility.OutputMessage("sometimes both. Worry over");
		m_utility.OutputMessage("Indians attacking -- haven't");
		m_utility.OutputMessage("seen any yet, but still a");
		m_utility.OutputMessage("worry.\"");
	}
	else if (m_randomNum == 2) {
		m_utility.OutputMessage("A lady, Marnie Stewart, tells");
		m_utility.OutputMessage("you:");
		cout << endl;
		m_utility.OutputMessage("\"This prairie is mighty pretty");
		m_utility.OutputMessage("with all the wild flowers and");
		m_utility.OutputMessage("tall grasses. But there's too");
		m_utility.OutputMessage("much of it! I miss not having");
		m_utility.OutputMessage("a town nearby. I wonder how");
		m_utility.OutputMessage("many days until I see a town --");
		m_utility.OutputMessage("a town with real shops, a");
		m_utility.OutputMessage("church, people...\"");
	}
	else {
		m_utility.DisplayError("ERROR: Invalid random number for Big Blue River Crossing.");
	}
}