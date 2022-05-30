/*************************************
* Studant name: Almog Zinder I.D 206554941
* Course title: Curse on C++.
* Exercise for home num. 6 question num.2
* The head file of the class RoundList.
*****************************************/
#pragma once
#ifndef ROUNDLIST_H
#define ROUNDLIST_H
#include "List.h"
#include <iostream>

class RoundList : public List
{
public:
	List::Link* addToEnd(int val);
	void add(int val);
	void removeFirst();
	void clear();
	int search(int n);

	friend ostream& operator<<(ostream& os, const RoundList& RL);
};



























#endif // !ROUNDLIST_H
