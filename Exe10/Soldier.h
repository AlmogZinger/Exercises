#pragma once
#ifndef SOLDIER_H
#define SOLDIER_H
#include <string>
#include <iostream>
using namespace std;
/****************/


/****************/

class Soldier
{
public:
	Soldier() : ID(0), fname(""), lname(""), numOfOp(0) {} //Empty constractor
	Soldier(const Soldier &other); //Copy constractor
	Soldier(int id, string fn, string ln, int numofop) : ID(id), fname(fn), lname(ln), numOfOp(numofop) {}
	
	virtual ~Soldier() = 0;
	virtual bool medal()=0;
	 virtual void print();
	 virtual string soldierType()=0;
	 
	 int getID();
	 string getfname();
	 string getlname();
	 int getNumOfOp();

protected:
	int ID; //The id of the soldier
	string fname; // the first name of the soldier
	string lname; // the last name of the soldier/
	int numOfOp;// the number of opertions the soldier was invole in
};


Soldier::Soldier(const Soldier& other)
{
	ID = other.ID; //The id of the soldier
	fname  = other.fname; // the first name of the soldier
	lname = other.lname; // the last name of the soldier/
	numOfOp =  other.numOfOp;// the number of opertions the soldier was invole in
}

void Soldier:: print()
{
	cout << "ID: " << ID << endl
		<< "first name: " << fname << endl
		<< "last name: " << lname << endl
		<< "num operation: " << numOfOp << endl;
}

int Soldier::getID()
{
	return ID;
}
string Soldier::getfname()
{
	return fname;
}
string Soldier::getlname()
{
	return lname;
}
int Soldier::getNumOfOp()
{
	return numOfOp;
}
#endif // !SOLDIER_H
