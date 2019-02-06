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
	~Date();

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

