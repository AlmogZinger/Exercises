#include "PrivateSoldier.h"
#include "string"
#include <iostream>
using namespace std;

PrivateSoldier::PrivateSoldier(int id, string fn, string ln, int numOfOp) :PrivateSoldier(id, fn, ln, numOfOp) // ctor
{
	grades = nullptr;

}

PrivateSoldier::PrivateSoldier(const PrivateSoldier& source)
{

}