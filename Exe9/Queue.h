/********************************
Uri Ehrlich 208967976 and Almog Zinger 206554941
Programming in C++
Exercise 8 question 1
The program runs an alghorithm of library using a bst
*********************************/
#pragma once
#include <iostream>
using namespace std;
template <class T>
class Queue
{
public:
	virtual ~Queue() {};
	virtual void clear() = 0;
	virtual void enqueue(T value) = 0;
	virtual T dequeue() = 0;
	virtual T front() = 0;
	virtual bool isEmpty() const = 0;
};
