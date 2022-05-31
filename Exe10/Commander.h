#pragma once
#include <iostream>
#include "PrivateSoldier.h"
#include<vector>
using namespace std;
class Commander : public PrivateSoldier
{
public:
	Commander(int i, string f, string l, int o, vector<int> n, bool c) : PrivateSoldier(i, o, f, l, n), combat(c) {}
	~Commander() {}
	bool medal();
	void print();
	string soldierType() { return "Commander"; }
	int getSoc() { throw "ERROR: this function is just for officer soldier"; }
	bool isCombat() { return combat; }
private:
	bool combat;
};