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

using namespace std;

class Trail
{
public:
	Trail();
	~Trail();
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

	Utility m_utility = Utility();
	double m_playerMoney;
	string m_playerPosition;

	string m_wagonLeader;
	string m_wagonParty[4];

	string m_startingMonth;

	Store m_Store;

	// Player's items during the playthrough
	Item m_partyOxen;
	Item m_partyFood;
	Item m_partyClothing;
	Item m_partyAmmunition;
	Item m_partyExtraWheel;
	Item m_partyExtraAxel;
	Item m_partyExtraToungue;

};

