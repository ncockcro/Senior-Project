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
	void FortKearney();
	void ChimneyRock();
	void FortLaramie();
	void IndependenceRock();
	void SouthPass();
	void FortBridger();
	void GreenRiver();
	void SodaSprings();
	void FortHall();
	void SnakeRiver();
	void FortBoise();
	void BlueMountains();
	void GrandeRondeValley(); // Or Blue Mountains
	void FortWallaWalla();
	void TheDalles();

	Utility m_utility = Utility();

	int m_randomNum;

};

