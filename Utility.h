/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	1/9/2019

CLASS
	Utility

DESCRIPTION
	The purpose of this class is to handle various utility functions used throughout the program for Oregon Trail.
	Some incluce handling errors, outputting specially formatted messages, and other useful functions.
*/
#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Utility
{
public:
	Utility();
	void DisplayError(string a_error);
	void Wait();
	bool IsDigits(string &a_input);
	void OutputMessage(string a_message);
	void NextDay(int &a_year, string &a_month, int &a_day);
	void ShowLocation(string a_location, int a_year, string a_month, int a_day);
	string GetWeatherName(int a_weather);

private:
	int ConvertMonth(string a_month);
	string ConvertMonth(int a_month);

	HANDLE m_hConsole;
	int m_lastDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};

