/********************************
Uri Ehrlich 208967976 and Almog Zinger 206554941
Programming in C++
Exercise 9 question 2
The program runs an alghorithm of library using a bst
*********************************/

#pragma once
#ifndef TREE
#define TREE


#include <iostream>
#include "QueueVector.h"
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		Node* parent; // a new field for the parent
		T value;
		Node(T val) : value(val), left(NULL), right(NULL), parent(NULL) {}
		Node(T val, Node* l, Node* r, Node* p) : value(val), left(l), right(r), parent(p) {}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	int height() { return height(root); }
	void reflect()	{ reflect(root); }
	void breadthScan() { breadthScan(root); }

	virtual void process(T val) { cout << val <<" "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;


private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);
	int  height(Node* current);
	void  reflect(Node* current);
	void  breadthScan(Node* current);
};







//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}
int max(int num1, int num2) //Return the maximum between two values.
{
	if (num1 > num2)
		return num1;
	return num2;
}
template <class T>
int Tree<T>::height(Node* current)
{
	if (current == NULL)
		return -1;
	return max(height(current->left), height(current->right)) + 1;
}

template <class T>
void Tree<T>::reflect(Node* current)
{
	if (current == NULL)
		return ;
	Node* temp = current->left; //Save the left son.
	current->left = current->right; //Swap the right and the left nodes.
	current->right = temp;

	//Do the same action to the sons
	reflect(current->right);
	reflect(current->left);
}

template <class T>
void Tree<T>::breadthScan(Node* current)
{
	QueueVector<Node*> qv(1000);
	qv.clear();
	qv.enqueue(current);// enter the root to the queue
	while (!qv.isEmpty()) // while the queue has a value
	{
		Node* v = qv.dequeue();
		process(v->value); // print the value
		if (v->left != NULL) // if there is  a left son
			qv.enqueue(v->left);
		if (v->right != NULL) // if there is  a right son
			qv.enqueue(v->right);
	}
}

#endif // !TREE