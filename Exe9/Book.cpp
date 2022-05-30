/********************************
Uri Ehrlich 208967976 and Almog Zinger 206554941
Programming in C++
Exercise 9 question 2
The program runs an alghorithm of library using a bst
*********************************/

#include "Book.h"
#include<string>
#include <iostream>
using namespace std;

bool Book::operator!=(Book const& other) const// operator !=
{
	return !(*this == other);
}
bool Book::operator==(Book const& other) const
{
	return (ID == other.ID) && (author == other.author) && (name == other.name); //operator ==
}

bool Book::operator>=(Book const& other) const//operator>=
{
	return (*this == other) || (*this > other);
}
bool Book::operator<=(Book const& other) const//operator <=
{
	return (*this == other) || (*this < other);
}
bool Book::operator>(Book const& other) const // checks priority
{
	if (author > other.author)// operand book auther's name  is after the other's
		return true;
	if (author < other.author) 
		return false;
	if (name > other.name)
		return true;
	if (name < other.name)
		return false;
	if (ID > other.ID)
		return true;

	return false;

}
bool Book::operator<(Book const& other) const
{
	return !(*this >= other); // operand is prior
}

istream& operator>>(istream& is, Book& book) //Insert into Book
{
	int id;
	string new_author, new_name;
	is >>id >> new_author >> new_name;
	if (id < 0)
		throw "Error in id";
	if (new_author == "")
		throw "Error in author";
	if (new_name == "")
		throw "Error in name";
	book.ID = id;
	book.author = new_author;
	book.name = new_name;
	return is;
}
ostream& operator<<(ostream& os, const Book& book)// Output for Book
{
	os << book.ID << " " << book.author << " " << book.name;
	return os;
}