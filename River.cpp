#include "River.h"



River::River()
{
	m_riverDepth = 0.0;
	m_riverLength = 0.0;
}

/*
	River::GetRiverLength()

NAME

	River::GetRiverLength - Returns the length of a river object

SYNOPSIS

	double River::GetRiverLength()

DESCRIPTION

	The function returns the length of a river object.

RETURNS

	Double

AUTHOR

	Nicholas Cockcroft

Date

	10:27pm 1/30/2019
*/
double River::GetRiverLength() {
	return m_riverLength;
}

/*
	River::GetRiverDepth()

NAME

	River::GetRiverDepth - Returns the depth of a river object

SYNOPSIS

	void Trail::GetRiverDepth()

DESCRIPTION

	This function returns the depth of a river object.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	10:30pm 1/30/2019
*/
double River::GetRiverDepth() {
	return m_riverDepth;
}
