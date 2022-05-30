#pragma once
#ifndef LIST_H
#define LIST_H


#include <iostream>
using namespace std;
//------------------------------------------------
//  class List
//      arbitrary size Lists
//      permits insertion and removal 
//      only from the front of the List
//------------------------------------------------
class List
{
protected:
	//--------------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	List& operator=(List&& l);
	List& operator=(const List& l);
	void insert(const int key);
	void remove(const int key);

	friend ostream& operator<<(ostream& os, const List& l);
	friend istream& operator>>(istream& is, List& l);

protected:
	// data field
	Link* head;
};
#endif // !LIST_H
