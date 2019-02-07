/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	2/6/2019

CLASS
	Date

DESCRIPTION
	The prupose of this class is to handle all of the functionality surrounding the in game date system. This holds
	the date but also the functionality to increment by a day and show the current location of where the player is.
*/

#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include "Utility.h"

using namespace std;

class Date
{
public:
	Date();

	void NextDay();
	int GetYear();
	void SetYear(int a_year);
	string GetMonth();
	void SetMonth(string a_month);
	int GetDay();
	void SetDay(int a_day);
	void ShowLocation(string a_location);

private:
	Utility m_utility;
	string ConvertMonth(int a_month);
	int ConvertMonth(string a_month);
	string m_month;
	int m_year;
	int m_day;

	int m_lastDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	HANDLE m_hConsole;
};

