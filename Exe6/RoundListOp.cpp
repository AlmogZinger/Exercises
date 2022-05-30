#include"RoundList.h"
#include <iostream>
/*************************************
* Studant name: Almog Zinder I.D 206554941
* Course title: Curse on C++.
* Exercise for home num. 6 question num.2
* The oparation of the class RoundList.
*****************************************/
void RoundList::add(int val)
{
	//Add a new value to the front of a Linked List
	head = addToEnd(val);
	if (head == nullptr)
		throw "failed in memory allocation";
}

void RoundList::removeFirst()
{
	if (head != nullptr) {
		if (head == head->next)
		{
			Link* p = head; // Save a pointer to the first element
			p->next = nullptr;
			delete p;
			head = nullptr;
		}
		else {
			// make sure there is a first element
			if (isEmpty())
				throw "the List is empty, no Elements to remove";
			// save pointer to the removed node
			Link* p = head, * q = head->next;
			// reassign the last node
			while (q->next != head)
				q = q->next;

			//setting the next of head to the currect first element.
			q->next = head->next;
			head = p->next;
			p->next = nullptr;
			// recover memory used by the first element
			delete p;
		}
	}
}

void RoundList::clear()
{
	//If the list isnt empty
	if (head != nullptr) {
		// empty all elements from the List
		Link* theNext;
		//While get to the last element (or the single element in list with one element)
		Link* p;
		for (p = head; p->next != head; p = theNext)
		{
			// delete the element pointed to by p
			theNext = p->next;
			p->next = nullptr;
			delete p;
		}
		//delete the last element
		p->next = nullptr;
		delete p;

		// mark that the List contains no elements
		head = nullptr;
	}
}

List::Link* RoundList::addToEnd(int val)
{
	if (head == nullptr){
		//If this is the first element
		head = new Link(val,nullptr);
		//Setting the next to himself...
		head->next = head;
		return head;
	}
	else{
		//Getting the last element
		Link* p = head->next;
		while (p->next != head)
			p = p->next;
		p->next = new Link(val, head);
		//Return the new element
		return p->next;
	}
}
int RoundList::search(int n)
{
	//If the list is empty - return -1
	if (head == nullptr)
		return -1;
	//Else , incarise the pointer 'n' times.
	Link* p = head;
	for (int i = 0; i < n; i++)
		p = p->next;
	return p->value;
}

ostream& operator<<(ostream& os, const RoundList& RL)
{
	if (!(RL.head == nullptr))
	{
		List::Link* p = RL.head;
		//The first element
		os << p->value << " ";
		p = p->next;
		//the rest element untill he reach the last one.
		while (p != RL.head)
		{
			os << p->value << " ";
			p = p->next;
		}
	}

	return os;

 }