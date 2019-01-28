#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Utility.h"

using namespace std;

class Dialogue
{
public:
	Dialogue();
	~Dialogue();
	void TalkToPeople(string a_location);

private:
	void Independence();
	void KRiverCrossing();
	void BBlueRiverCrossing();

	Utility m_utility = Utility();

	int m_randomNum;

};

