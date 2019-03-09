/*
WRITTEN BY
	Nicholas Cockcroft

DATE
	3/8/19

CLASS
	Member

DESCRIPTION
	The prupose of this class is to handle the data pertaining to a particular wagon member. It holds data
	such as the person's name and any diseases that they have. This class holds the functionality for 
	anything pertaining to a wagon party member.
*/

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
	string GetName();
	void SetName(string a_name);
	void AddDisease(string a_disease);
	int GetNumOfDiseases();
	vector<string> GetDiseases();
	string GetLastDisease();
	bool CheckIfDead();

private:
	string m_name;
	vector<string> m_diseases;
	bool isDead;
};

