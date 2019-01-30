#pragma once

#include <iostream>
#include <string>
#include "Utility.h"

using namespace std;

class Location
{
public:
	Location();
	void SetName(string a_name);
	void SetMilesNeeded(int a_miles);
	void DeductMiles(int a_miles);

private:

	string m_name;
	int m_milesNeeded;
	Utility m_utility;

};

