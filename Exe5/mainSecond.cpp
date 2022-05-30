/*************************************
* Studant name: Almog Zinder I.D 206554941
* Course title: Curse on C++.
* Exercise for home num. 5 question num.2
* The oparation of the class List.
*****************************************/
#include <iostream>
#include "List.h"
using namespace std;


List merge(List l1, List l2);
void makeSet(List& l);
void reverse(List& l);
int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;


	return 0;
}


List merge(List l1, List l2)
{
	//If one of the list are empty- return the other.
	if (l1.isEmpty())
		return l2;
	if (l2.isEmpty())
		return l1;

	//If both of them not empty - merge them:
	List temp; // The marge List.
	//The values of the firsts organs in the lists - 
	int num1 = l1.firstElement();// num1: first of l1
	int num2 = l2.firstElement();// number2 : first of l2

	while (!(l1.isEmpty() || l2.isEmpty())) //While the both list isn't empty
	{
		//Move the bigger organ bwtween the two 
		//list to the new list.
		if (num1 > num2) 
		{
			temp.add(num1); //Enter the bigger organ to the new list 
			l1.removeFirst(); //Remove the first organ of l1 from l1 to get to the next organ.
			if (!l1.isEmpty())
			num1 = l1.firstElement(); //Initialize num1 to the value of the next organ.
		}
		else
		{//The same like the 'if'..
			temp.add(num2);
			l2.removeFirst();
			if (!l2.isEmpty())
			num2 = l2.firstElement();
		}
	}

	while (!l1.isEmpty())//If l1 not empty - enter all her values to temp.
	{
		temp.add(l1.firstElement());
		l1.removeFirst();
	}
	while (!l2.isEmpty())//If l2 not empty - enter all her values to temp.
	{
		temp.add(l2.firstElement());
		l2.removeFirst();
	}
	reverse(temp); //Upsite the list so he can be from the big to the small one.
	return temp; //Return the nerge list.
}

void makeSet(List& l)
{
	if (!l.isEmpty()) 
	{
		List temp; //The working list.
		int num1	= l.firstElement(),num2; //keeps the first two numbers of the ist to compere between them.
		
		l.removeFirst();
		temp.add(num1); //Insert the first element in 'l' to the working list.
		
		while(!l.isEmpty()) //While list not finished.
		{
		num2 = l.firstElement(); //Insert num2 the next element in 'l'.
		l.removeFirst(); //Remove the element fron the list that we can get to the next element..
		if (num2 != num1) // If the element are equel to the previus element - do not insert him.
		{
			temp.add(num2);
			num1 = num2;
		}
		}

		reverse(temp);//Upsite the list so he can be from the big to the small one.
		l = temp; //Insert the working list to are list.
	}

}

void reverse(List& l)
{
	List temp; //The working list.
	while (!l.isEmpty()) //While 'l' not empty
	{
		temp.add(l.firstElement()); // Insert the first element to the working list.
		l.removeFirst(); //Delete the element from the list.
	}
	l = temp;//Insert the working list to are list.
}
/*
* RUNNING EXAMPLE:
enter sorted values for the first list:
9 5 4 2 0 5
enter sorted values for the second list:
8 7 5 2 0 4
the new merged list: 9 8 7 5 5 4 2 2 0 0

the new merged set: 9 8 7 5 4 2 0

the new merged reverse: 0 2 4 5 7 8 9
*/