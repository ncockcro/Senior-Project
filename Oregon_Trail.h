#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class Oregon_Trail
{
public:
	Oregon_Trail();
	~Oregon_Trail();
	void StartGame();

private:
	void PickDecision();
	void ShowTitle();
	void ShowDescription();
};

