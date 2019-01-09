/*
WRITTEN BY
Nicholas Cockcroft

DATE
1/9/2019

CLASS
Error

DESCRIPTION
The purpose of this class is to handle any error handling that occurs throughout the course of the program. This class is used
accross all other classes in Oregon Trail for displaying errors and anything else that deals with errors.
*/
#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Error
{
public:
	Error();
	void DisplayError(string error);

private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};

