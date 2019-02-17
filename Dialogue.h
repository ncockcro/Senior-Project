/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	1/30/2019

CLASS
	Dialogue

DESCRIPTION
	The prupose of this class is to house all of the dialogue that is displayed at the various locations throughout
	the game.
*/
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

	void T_DepartingDialogue();
	void T_LeavingMessage(double a_playerMoney);
	void T_WhichDirectionChoice1();
	void T_WhichDirectionChoice2();
	void T_End();

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
	void FortWallaWalla();
	void TheDalles();

	Utility m_utility = Utility();

	int m_randomNum;

};

