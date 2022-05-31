#pragma once
#include <iostream>
#include"Soldier.h"
#include<vector>
using namespace std;
class PrivateSoldier : public Soldier
{
public:
	PrivateSoldier(int i, string f, string l, int o,vector<int> new_grades) : Soldier(i, f, l, o) ,grades(new_grades){}
	~PrivateSoldier() { grades.clear(); }
	PrivateSoldier(const PrivateSoldier& p);
	bool medal();
	void print();
	string soldierType() { return "Private"; }
	int getSoc() { throw "ERROR: this function is just for officer soldier"; }
	string getFname() { return fname; }
	string getName() { return lname; }
	bool isCombat() { return NULL; }
protected:
	vector<int> grades;
};