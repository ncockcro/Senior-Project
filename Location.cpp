#include "Location.h"



Location::Location()
{
}

void Location::SetName(string a_name) {
	m_name = a_name;
}

string Location::GetName() {
	return m_name;
}

void Location::SetMilesNeeded(int a_miles) {
	m_milesNeeded = a_miles;
}

int Location::GetMilesNeeded() {
	return m_milesNeeded;
}

void Location::DeductMiles(int a_miles) {

	if (a_miles > 0) {
		m_milesNeeded -= a_miles;
	}
	else {
		m_utility.DisplayError("ERROR: Cannot deduct negative/zero miles from location");
	}
}