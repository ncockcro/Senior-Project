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
	void ShowLocation(string a_location, int a_year, string a_month, int a_day);
	string GetWeatherName(int a_weather);

private:
	HANDLE m_hConsole;
};

