#pragma once
#ifndef VECTOR_H
#define VECTOR_H
/********************************
Uri Ehrlich 208967976 and Almog Zinger 206554941
Programming in C++
Exercise 8 question 1
The program runs an alghorithm of library using a bst
*********************************/
#include <iostream>
using namespace std;

const int DEF_CAPACITY = 100;

template <class T>
class Vector
{
protected:
	T* data;
	int size;		//size in use
	int capacity;	//available capacity
public:
	//constructors
	Vector(int capacity = DEF_CAPACITY);
	Vector(const Vector<T>& v);
	~Vector();
	//operations
	Vector<T>& operator= (const Vector<T>&);
	// view and modify
	T& operator [](int index);
	int	getSize() const;
	int  getCapacity() const;
	void insert(T value);
	void  clear();
	T  delLast();
	bool isEmpty() const; // id the vector is empty
};


//=======class Vector implementation=====     
template <class T>
Vector<T>::Vector(int Capacity)
{
	capacity = Capacity;
	size = 0;
	data = new T[capacity];
	if (data == NULL)
		throw "memory allocation problem";
}

template <class T>
Vector<T>::Vector(const Vector<T>& vec)
{
	capacity = vec.capacity;
	size = vec.size;
	data = new T[capacity];
	if (data == NULL)
		throw "memory allocation problem";
	for (int index = 0; index < size; index++)
		data[index] = vec.data[index];
}

template <class T>
Vector<T>::~Vector()
{
	if (data != NULL)
	{
		delete[] data;
		data = NULL;
	}
}

template <class T>
void Vector<T>::clear()
{
	size = 0;
}

template<class T>
T& Vector<T>::operator [](int index)
{
	if (index < 0 || index >= size)
		throw "vector overflow";
	return data[index];
}

template <class T>
Vector<T>& Vector<T>::operator =(const Vector<T>& vec)
{
	size = vec.size;
	capacity = vec.capacity;

	if (data)
		delete[] data;
	data = new T[capacity];
	if (data == NULL)
		throw "memory allocation problem";
	for (int index = 0; index < size; index++)
		data[index] = vec.data[index];
	return *this;
}

template <class T>
int Vector<T>::getSize() const
{
	return size;
}

template <class T>
int Vector<T>::getCapacity() const
{
	return capacity;
}

template <class T>
void Vector<T>::insert(T value)
{
	if (size > capacity)
		throw "the vector is full";
	data[size] = value;
	size++;
}

template <class T>
T Vector<T>::delLast()
{
	if (size < 0)
		throw "the vector is empty";
	return data[--size];
}

template<class T>
inline bool Vector<T>::isEmpty() const
{
	if (size)
		return false;
	return true;
}
#endif // !VECTOR_H
