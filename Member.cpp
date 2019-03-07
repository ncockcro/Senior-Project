#include "Member.h"



Member::Member()
{
}

Member::Member(string a_name) {
	m_name = a_name;
}

Member::~Member()
{
}

string Member::GetName() {
	return m_name;
}

void Member::SetName(string a_name) {
	m_name = a_name;
}

void Member::AddDisease(string a_disease) {
	m_diseases.push_back(a_disease);
}

int Member::GetNumOfDiseases() {
	return m_diseases.size();
}

vector<string> Member::GetDiseases() {
	return m_diseases;
}

string Member::GetLastDisease() {

	if (m_diseases.size() > 0) {
		return m_diseases.back();
	}
	else {
		cerr << "ERROR: No diseases." << endl;
		return "NULL";
	}
}