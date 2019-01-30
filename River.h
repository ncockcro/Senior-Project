#pragma once

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class River: public Location
{
public:
	River();
	~River();
	double GetRiverLength();
	double GetRiverDepth();

private:
	double m_riverLength;
	double m_riverDepth;
};

