#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape(int num=0) //constractor 
{
	theLine = new Point*[num];
	numOfPoints = num;
	
	cout << "Enter values of "<<num<<" points:" << endl;
	for (int i = 0; i < num; i++)
	{
		theLine[i] = new Point();
		cin >> *theLine[i];
	}
}

Shape::Shape(const Shape& sh) //Copy conatractor.
{
	numOfPoints = sh.numOfPoints;
	if (theLine != nullptr)
		delete this;

	theLine = new Point*[numOfPoints];

	for (int i = 0; i < numOfPoints; i++)
		theLine[i] = sh.theLine[i];
}

Shape::Shape(Shape&& sh) // move constructor
{
	numOfPoints = sh.numOfPoints;
	theLine = sh.theLine;
	sh.theLine = nullptr;
	sh.numOfPoints = 0;
}
Shape::~Shape() //  destructor
{
	for (int i = 0; i < numOfPoints; i++)
	{
		delete theLine[i];
	}
	delete[] theLine;
	theLine = nullptr;
	numOfPoints = 0;
}
ostream& operator>>(ostream& os, const Shape& sh)
{
	os << "points: ";
	for (int i = 0; i < sh.numOfPoints; i++)
		os << *sh.theLine[i] << " ";
	return os;
}


ostream& operator<<(ostream& os, const Shape& sh)
{
	os << "points: ";
	for (int i = 0; i < sh.numOfPoints; i++)
		os << *sh.theLine[i];
	os << " area is: " << sh.area();
	return os;
}