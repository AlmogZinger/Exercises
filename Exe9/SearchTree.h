/********************************
Uri Ehrlich 208967976 and Almog Zinger 206554941
Programming in C++
Exercise 9 question 2
The program runs an alghorithm of library using a bst
*********************************/

#pragma once
#ifndef SEARCH_TREE
#define SEARCH_TREE
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value); // add a value
	bool  search(T value) //is a value exists in a tree
	{
		return search(Tree<T>::root, value);
	}
	void remove(T val) {remove(searchPointer(Tree<T>::root, val));	} // remove a value
	T successor(T val){ return successor(searchPointer( Tree<T>::root , val ) ) ;} // returns the value of the successr
	void deleteDuplicates() { deleteDuplicates(Tree<T>::root); } // delete duplicates values


private: // private functions  
	void add(typename Tree<T>::Node* current, T val);
	bool  search(typename Tree<T>::Node* current, T val);
	void remove(typename Tree<T>::Node* current);
	T successor(typename Tree<T>::Node* current);
	void deleteDuplicates(typename Tree<T>::Node* current);
	typename Tree<T>::Node* min(typename Tree<T>::Node* current); //Return the minimum  of the sub tree.
	typename Tree<T>::Node* searchPointer(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* successorPointer(typename Tree<T>::Node* current);

};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root) // if the tree is empty
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val); // else - just add
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val) // add to the left side( the value is smaller)

		if (!current->right) // no right son
		{
			current->right = new typename Tree<T>::Node(val);
			current->right->parent = current;
			return;
		}
		else add(current->right, val);// theres a right son
	else // the value is bigger the the root

		if (!current->left) //If doesnt has left son
		{
			current->left = new typename Tree<T>::Node(val);
			current->left->parent = current;
			return;
		}
		else // theres a left son
			//if (current->value == val)
			//{
			//	typename Tree<T>::Node * temp= new typename Tree<T>::Node(val); //The new Node
			//	current->left->parent = temp; //Set the parant of the old left son to the new node
			//	temp->left = current->left;//Set the left son of the new Node to the old son of the current
			//	current->left = temp; // Set the left son of the current to the new Node
			//	temp->parent = current;//Set the parent of the new Node to the current
			//}
			//else
			add(current->left, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}


template <class T>
typename Tree<T>::Node* SearchTree<T>::searchPointer(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		throw "not exist";	// not found
	if (current->value == val)
		return current; //return the pointer to the node
	if (current->value < val)
		return searchPointer(current->right, val);
	else
		return searchPointer(current->left, val);
}

template <class T>
T SearchTree<T>::successor(typename Tree<T>::Node* current)
{
	if (current == nullptr)
		throw "no successor";

	if (current->right != nullptr) //If has right son
		return min(current->right)->value; //Return the minimun value in the right sub tree

	typename Tree<T>::Node* p1 = current->parent; //P1 is the parant of the current. 

	while (p1 != NULL && current == p1->right) //If not end the tree and the cureent is the right son.
	{
		//Climb up
		current = p1;
		p1 = current->parent;
	}
	if (p1 == NULL)
		throw "no successor";
	return p1->value; //If get to the place - return the vlue of the successor.
}

template <class T>
typename Tree<T>::Node* SearchTree<T>::successorPointer(typename Tree<T>::Node* current)
{
	if (current == nullptr)
		throw "no successor";

	if (current->right != nullptr) //If has right son
		return min(current->right); //Return the minimun value in the right sub tree

	typename Tree<T>::Node* p1 = current->parent; //P1 is the parant of the current. 

	while (p1 != NULL && current == p1->right) //If not end the tree and the cureent is the right son.
	{
		//Climb up
		current = p1;
		p1 = current->parent;
	}
	if (p1 = NULL)
		throw "no successor";
	return p1; //If get to the place - return the vlue of the successor.
}

template <class T>
typename Tree<T>::Node* SearchTree<T>::min(typename Tree<T>::Node* current) //Current isnt NULL!!
{
	while (current->left != nullptr)
		current = current->left;
	return current;
}

template <class T>
void SearchTree<T>::remove(typename Tree<T>::Node* current)
{
	if (current == nullptr)
		return;

	typename Tree<T>::Node* p = current->parent;

	/**********************************IS A LEAF*************************************/
	if (current->left == nullptr && current->right == nullptr) //If current is a leaf
	{
		if (p == NULL)// current is the root - the has only one member
			Tree<T>::root = nullptr;
		else
		if (p->right == current) //If current is the right son 
			p->right = nullptr;//  - update the filed in the parant
		else
			p->left = nullptr;//If current is the right son  - update the filed in the parant
		delete current;
		return; //end action
	}

	/**********************************ONLY ONE SON*************************************/
	if (current->left == nullptr || current->right == nullptr) //If cerrent has only one son
	{
		//Current has only right son 
		if (current->right != nullptr) 
			if (p == NULL)// current is the root - has only right son
			{
				Tree<T>::root = current->right;
				current->right->parent = nullptr;
			}
			else if (p->right == current)	//Current is a right son.
			{
				p->right = current->right; //the right son of current replace the current
				current->right->parent = p; //The new parent of cureent son is current parant.
			}
			else  //Current is the left son and has only right son
			{
				p->left = current->right; //the right son of current replace the current
				current->right->parent = p; //The new parent of cureent son is current parant.
			}


		else //Current has only a left son.
			if (p == NULL)// current is the root - has only left son
			{
				Tree<T>::root = current->left;
				current->left->parent = nullptr;
			}
			else if (p->right == current) //Current is a right son 
			{
				p->right = current->left; //the left son of current replace the current
				current->left->parent = p; //The new parent of cureent son is current parant.
			}
			else //Current is a left son and has left son 
			{
				p->left = current->left; //the left son of current replace the current
				current->left->parent = p; //The new parent of cureent son is current parant.
			}

		delete current;
		return; //end action.
	}

	/**********************************HAS TWO SONS*************************************/
	
	typename Tree<T>::Node* succ = successorPointer(current); // find the successor of current 
	current->value = succ->value;// set the value of the currnet with the value of seccessor 
	remove(succ); // remove the original node of seccessor
	return;
}



template <class T>
void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* current) 
{
	if (current != NULL) // if tree not empty
	{
		deleteDuplicates(current->left); // delete in the sub left tree
		deleteDuplicates(current->right); // delete in the right sub tree
		if (search(current->left, current->value)) // there is a duplicate
			remove(searchPointer(current->left, current->value));//delete the spare node
	}
}
#endif // !SEARCH_TREE
