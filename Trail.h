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
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
#include "Utility.h"
#include "Store.h"
#include "Item.h"
#include "Dialogue.h"
#include "Location.h"
#include "River.h"
#include "Player.h"
#include "Date.h"

using namespace std;

class Trail
{
public:
	Trail();
	void ActiveGame();
	int GetTotalScore();

private:
	void PromptPosition();
	void PromptCharacterNames();
	void PromptStartingMonth();
	void DepartingStore();
	void AddItemsFromStore(vector<Item> a_storeItems);
	void TrailMenu(bool a_hasStore, string a_locationName);
	void ShowSupplies();
	void LookAtMap();
	void ChangePace();
	void ChangeRations();
	void Rest();
	void InitializeLocations();
	void ShowAndUpdateTrailInfo(int a_miles, int &a_milesNeeded);
	void AddEndingMiles(int a_miles);
	void ShowMilesTo(string a_currentLocationName, string a_nextLocationName, int a_milesNeeded);
	void VisitStore(string a_location);
	void Hunt();
	void IncreaseRates();
	void CalculateScore();
	void ShowScoreDetails(int a_scores[]);

	Utility m_utility = Utility();
	Player m_player;
	string m_currentLocation;
	Date m_date;

	string m_wagonLeader;
	vector <string> m_wagonParty;

	Store m_Store;

	// Player's items during the playthrough

	int m_milesLeft;
	int m_weather;
	int m_health; // 0 = very poor, 1 = poor, 2 = fair, 3 = good
	string m_pace;
	string m_foodRate;

	Dialogue m_dialogue = Dialogue();

	vector<Location*> m_locations;
	Location m_Independence;
	River m_KansasRiver;
	River m_BigBlueRiver;
	Location m_FortKearney;
	Location m_ChimneyRock;
	Location m_FortLaramie;
	Location m_IndependenceRock;
	Location m_SouthPass;
	River m_GreenRiver;
	Location m_FortBridger;
	Location m_SodaSprings;
	Location m_FortHall;
	River m_SnakeRiver;
	Location m_FortBoise;
	Location m_BlueMountains;
	Location m_FortWallaWalla;
	Location m_TheDalles;
	Location m_WillametteValley;

	int m_rateOfTravel;
	int m_milesTraveled;

	int m_rate5dollars;
	double m_rate2_5dollars;
	double m_rate0_5dollars;

	int m_totalScore;

};

