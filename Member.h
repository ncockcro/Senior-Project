#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Member
{
public:
	Member();
	Member(string a_name);
	~Member();
	string GetName();
	void SetName(string a_name);
	void AddDisease(string a_disease);
	int GetNumOfDiseases();
	vector<string> GetDiseases();
	string GetLastDisease();

private:
	string m_name;
	vector<string> m_diseases;
};

