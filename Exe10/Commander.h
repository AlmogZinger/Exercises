#pragma once
#ifndef COMM_H
#define COMM_H
#include "PrivateSoldier.h"


class Commander :public PrivateSoldier
{
public:
	Commander(int id, string fn, string ln, int numofop, bool combet) : Soldier(id,fn,ln,numofop) ,isCombet(combet){}
	~Commander();

protected:
	bool isCombet; //IF the soldier are combet

};

Commander::Commander()
{
}

Commander::~Commander()
{
}
#endif // !COMM_H

#include <string>
