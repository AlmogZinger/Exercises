#pragma once
#ifndef OFFICER_H
#define OFFICER_H
#include "Soldier.h"

class Officer : public Soldier
{//uriiiiiiiiiiiiiiii
public:
	Officer (int id, string fn, string ln, int numofop, int sgrade): Soldier(id,fn,ln,numofop), socialGrade(sgrade){} //Constractor
	Officer(const Officer& other); // copy constractor
	int getSocialGrade();
	virtual bool medal();
	virtual void print();
private:
	int socialGrade;
};
#endif // !OFFICER_H

Officer :: Officer(const Officer& other) : Soldier(other)
{
	socialGrade = other.socialGrade;
}

int Officer::getSocialGrade()
{
	return socialGrade;
}bool Officer:: medal()
{
	return (numOfOp > 2) && (socialGrade >= 92);
}
void  Officer::print()
{
	Soldier::print();// Call to tha print of soldier.
	cout << "sociometric score: " << socialGrade<<endl;
}