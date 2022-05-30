/*************************************
* Studant name: Almog Zinder I.D 206554941
* Course title: Curse on C++.
* Exercise for home num. 5 question num.1
* The oparation of the class List.
*****************************************/
#include "List.h"

//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}


List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}


//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(nullptr)
{
	// no further initialization
}

List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}


List::~List()
{
	clear();
}


void List::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != nullptr; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}

bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == nullptr;
}

void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}


void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}



List& List::operator=(List&& l)
{
	this->clear();

	this->head = l.head;

	l.head = nullptr;
	return *this;
}
List& List::operator=(const List& l)
{
	if (l.head == nullptr)
		this->head = nullptr;
	else
	{
		head = new Link(l.head->value, nullptr); //Set the first organ.
		Link* p = head; //Pointer to the list
		for (Link* q = l.head->next; q != nullptr; q = q->next, p = p->next)
			p->next = new Link(q->value, nullptr);
	}
	return *this;
}


ostream& operator<<(ostream& os, const List& l)
{
	//Print the all List
	for (List::Link* p = l.head; p != nullptr; p = p->next)
		os << p->value << " ";
	os << endl;
	return os;
}

istream& operator>>(istream& is, List& l)
{
	l.clear();
	int i;
	is >> i; //Insert the first number to the head.
	l.head = new List::Link(i, nullptr);
	List::Link* p = l.head; //Pointer to the last organ of the list.
	is >> i; //The secound number.
	while (i < p->value) //While the resive number is last than the previous number.
	{
		p->next = new List::Link(i, nullptr); //Add the number to the list.
		p = p->next; //Preceed 'p' to the next organ.
		is >> i;  //Recive the next number.
	}
	return is;
}

void List::insert(const int key)
{
	//If the list is empty - add key to the first member.
	if (head == nullptr)
		this->add(key);
	else
	{
		Link* p = head; //Pointer to the list
		if (p->value < key) //If key supposed to be in the top.
			this->add(key); // Made key as the first member.
		else {
			//Preceed p to the place one before key place.
			//This can be the last member - if p recive 'nullptr' - not found member that smaller or equle.
			//This can be the place one before the member that smaller then he.
			while (p->next != nullptr && p->next->value > key)
				p = p->next;
			p->next = new Link(key, p->next); //Insert key to his place.
		}
	}
}

void List::remove(const int key)
{
	bool found = false;
	Link* p = head; //Pointer to the list
	if (p->value == key) //If the first member is 'key'
	{
		// Set head as the next member and delete key from the memory
		head = p->next;
		delete p;
		p = nullptr;
		found = true; //Remember that found the key
	}
	else
	{
		//Run with P until get to place he shuld be there.
		for (; !found && p->next != nullptr && p->next->value >= key; p = p->next)
		{
			if (p->next->value == key) //If found key. 
			{
				Link* q = p->next;
				p->next = q->next;//Set the next of the correct member to the next of key
				//And dalete the member 'key'.
				delete q;
				q = nullptr;
				found = true; //Remember that found the key
			}
		}

		if (!found) //If not found key.
			throw "value not found";
	}
}

