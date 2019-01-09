#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Error
{
public:
	Error();
	~Error();
	void DisplayError(string error);

private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};

