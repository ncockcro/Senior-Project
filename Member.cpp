#include "Member.h"

/*
	Member::Member()

NAME

	Member::Member - default constructor

SYNOPSIS

	Member::Member()

DESCRIPTION

	This is the default constructor and initializes any members of the Member class.

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	7:45pm 3/8/2019
*/
Member::Member()
{
	m_name = "NULL";
	isDead = false;
}

/*
	Member::Member(string a_name)

NAME

	Member::Member - overloaded constructor

SYNOPSIS

	Member::Member(string a_name)

	a_name --> name of the member

DESCRIPTION

	This is an overloaded version of the constructor which sets the name of the member to what was passed
	in.

RETURNS

	None

AUTHOR

	Nicholas Cockcroft

Date

	7:51pm 3/8/2019
*/
Member::Member(string a_name) {
	m_name = a_name;
	isDead = false;
}

/*
	Member::GetName()

NAME

	Member::GetName - returns name of the member

SYNOPSIS

	string Member::GetName()

DESCRIPTION

	This function will return the name of a member.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	7:56pm 3/8/2019
*/
string Member::GetName() {
	return m_name;
}

/*
	Member::SetName(string a_name)

NAME

	void Member::SetName - sets the name of the member

SYNOPSIS

	void Member::SetName(string a_name)

	a_name --> name of the member

DESCRIPTION

	This function will set the name of the member to what was passed in

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	7:59pm 3/8/2019
*/
void Member::SetName(string a_name) {
	m_name = a_name;
}

/*
	Member::AddDisease(string a_disease)

NAME

	Member::AddDisease - adds a disease to a member's list

SYNOPSIS

	void Member::AddDisease(string a_disease)

	a_disease --> the disease to be added

DESCRIPTION

	This function takes in a disease and adds it to the vector of diseases a member has.

RETURNS

	Void

AUTHOR

	Nicholas Cockcroft

Date

	8:01pm 3/8/2019
*/
void Member::AddDisease(string a_disease) {
	m_diseases.push_back(a_disease);

	// If a member has atleast 3 diseases, than the member is dead
	if (m_diseases.size() > 2) {
		isDead = true;
	}
}

/*
	Member::GetNumOfDiseases()

NAME

	Member::GetNumOfDiseases - gets the number of diseases

SYNOPSIS

	int Member::GetNumOfDiseases()

DESCRIPTION

	Returns the number of diseases a player has.

RETURNS

	Int

AUTHOR

	Nicholas Cockcroft

Date

	8:03pm 3/8/2019
*/
int Member::GetNumOfDiseases() {
	return m_diseases.size();
}

/*
	Member::GetDiseases()

NAME

	Member::GetDiseases - returns the list of diseases

SYNOPSIS

	vector<string> Member::GetDiseases()

DESCRIPTION

	This function returns the list of diseases a member has.

RETURNS

	Vector<string>

AUTHOR

	Nicholas Cockcroft

Date

	8:04pm 3/8/2019
*/
vector<string> Member::GetDiseases() {
	return m_diseases;
}

/*
	Member::GetLastDisease()

NAME

	Member::GetLastDisease - returns the last disease added

SYNOPSIS

	string Member::GetLastDisease()

DESCRIPTION

	This function returns the last disease that was added. This is typically called when a member gets
	a disease added and that disease wants to be outputted to the screen.

RETURNS

	String

AUTHOR

	Nicholas Cockcroft

Date

	8:06pm 3/8/2019
*/
string Member::GetLastDisease() {

	if (m_diseases.size() > 0) {
		return m_diseases.back();
	}
	else {
		cerr << "ERROR: No diseases." << endl;
		return "NULL";
	}
}

/*
	Member::CheckIfDead()

NAME

	Member::CheckIfDead - returns if the player is dead or not

SYNOPSIS

	bool Member::CheckIfDead()

DESCRIPTION

	This function returns true if the member is dead and false if they are not.

RETURNS

	Bool

AUTHOR

	Nicholas Cockcroft

Date

	8:08pm 3/8/2019
*/
bool Member::CheckIfDead() {

	if (isDead) {
		return true;
	}
	else {
		return false;
	}
}