#pragma once
#include <iostream>
#include"Soldier.h"
#include<vector>
using namespace std;
class PrivateSoldier : public Soldier
{
public:
	PrivateSoldier(int i, int o, string f, string l, vector<int> n) : Soldier(i, o, f, l), grades(n) {};
	~PrivateSoldier() { grades.clear(); }
	PrivateSoldier(const PrivateSoldier& p);
	bool medal();
	void print();
	string soldierType() { return "Private"; }
	int getSoc() { throw "ERROR: this function is just for officer soldier"; }
	string getFname() { return firstName; }
	string getName() { return lastName; }
	bool isCombat() { return NULL; }
protected:
	vector<int> grades;
};