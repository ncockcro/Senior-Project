/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	1/9/2019

CLASS
	Trail

DESCRIPTION
	The purpose of this class is to serve as an active game running in Oregon Trail. This is when the player is playing
	an active game of Oregon Trail and traversing the trail. Everything that is defined in this class is for when the player
	is playing an active game of Oregon Trail.
*/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Utility.h"
#include "Store.h"
#include "Item.h"
#include "Dialogue.h"
#include "Location.h"
#include "River.h"

using namespace std;

class Trail
{
public:
	Trail();
	void ActiveGame();

private:
	void PromptPosition();
	void PromptCharacterNames();
	void PromptStartingMonth();
	void LeavingMessage();
	void DepartingStore();
	void DeductMoney(double a_money);
	void InitializePartyItems();
	void AddItemsFromStore(vector<Item> a_storeItems);
	void TrailMenu();
	void ShowSupplies();
	void ChangePace();
	void ChangeRations();
	void Rest();
	void InitializeLocations();

	Utility m_utility = Utility();
	double m_playerMoney;
	string m_playerPosition;
	string m_month;
	int m_year;
	int m_day;
	string m_location;

	string m_wagonLeader;
	string m_wagonParty[4];

	Store m_Store;

	// Player's items during the playthrough
	Item m_partyOxen;
	Item m_partyFood;
	Item m_partyClothing;
	Item m_partyAmmunition;
	Item m_partyExtraWheel;
	Item m_partyExtraAxle;
	Item m_partyExtraTongue;

	int m_milesLeft;
	int m_weather;
	int m_health;
	string m_pace;
	string m_rationsPace;

	Dialogue m_dialogue = Dialogue();

	River m_KansasRiver;
	River m_BigBlueRiver;
	Location m_FortKearney;
	Location m_ChimneyRock;
	Location m_FortLaramie;
	Location m_IndependenceRock;
	Location m_SoutPass;
	Location m_FortBridger;
	River m_SnakeRiver;
	Location m_FortBoise;
	Location m_BlueMountains;
	Location m_FortWallaWalla;
	Location m_TheDalles;

};

