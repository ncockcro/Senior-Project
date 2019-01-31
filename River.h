/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	1/30/2019

CLASS
	River

DESCRIPTION
	The prupose of this class is to give further functionality to a location, specifically a river, and provides
	further functions and variables that are needed for when a player is crossing a river.
*/
#pragma once

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class River: public Location
{
public:
	River();
	double GetRiverLength();
	double GetRiverDepth();

private:
	double m_riverLength;
	double m_riverDepth;
};

