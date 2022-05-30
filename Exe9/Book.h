/********************************
Uri Ehrlich 208967976 and Almog Zinger 206554941
Programming in C++
Exercise 9 question 2
The program runs an alghorithm of library using a bst
*********************************/

#pragma once
#ifndef B00K_H
#define B00K_H
#include <string>
using namespace std;
class Book
{
public:
	Book() : ID(0), author(""), name("") {} //Empty constructor
	bool operator!=(Book const& other) const; // comparison operands
	bool operator==(Book const& other) const;
	bool operator>=(Book const& other) const;
	bool operator<=(Book const& other) const;
	bool operator>(Book const& other) const;
	bool operator<(Book const& other) const;
	friend istream& operator>>(istream& is, Book& book); // input output operands
	friend ostream& operator<<(ostream& os, const Book& ft);

private://fields
	int ID;
	string author;
	string name;
};




#endif // !B00K_H
