#include "QueueStack.h"
/************
Uri Ehrlich 208967976 and Almog Zinger 206554941
Programming in C++
Exercise 8 question 2
 Queue made from Stack
***********/

void QueueStack:: clear() // clear data
{
	data.clear();
}
void  QueueStack:: enqueue(int value) //Insert data to the Queue.
{
	StackList stk;
	while (!data.isEmpty()) //Insert to stk by Emptying the Queue
		stk.push(data.pop());
	data.push(value); //Insert the new value 
	while (!stk.isEmpty()) //Insert the other values to the Queue
		data.push(stk.pop());
}
int QueueStack:: dequeue() //delete and return the first value. Throw msg if empty
{
	if (data.isEmpty())
		throw "The Queue is empty - you cant dequeue it!";
	return data.pop();
}
int QueueStack:: front() //Return the value of the first in the Queue
{
	return data.top();
}
bool QueueStack:: isEmpty() const //Return if the Queue is empty
{
	return data.isEmpty();
}
QueueStack:: QueueStack()
{

}
