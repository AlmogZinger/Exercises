/************
Uri Ehrlich 208967976 and Almog Zinger 206554941
Programming in C++
Exercise 8 question 2
 Queue made from Stack
***********/
#pragma once
#include "Queue.h"
#include "StackList.h"

class QueueStack : public Queue
{
public:
	 void clear();
	 void enqueue(int value);
	 int dequeue() ;
	 int front();
	 bool isEmpty() const ;
	QueueStack();


protected:
	StackList data;
};

