#pragma once
#include "string"
#include <iostream>
#include "Soldier.h"
using namespace std;
#ifndef PRIVATESOLDIER_H
#define PRIVATESOLDIER_H


class PrivateSoldier : public Soldier
{

private:
	int* grades;

public:
	PrivateSoldier(int id, string fn, string ln, int numOfOp);
	PrivateSoldier(const PrivateSoldier& source); //copy ctor


};

#endif // !PRIVATESOLDIER_