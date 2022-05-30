#pragma once
#ifndef  SHAPE_H
#define SHAPE_H
#include "Point.h"
#include <iostream>
using namespace std;
class Shape
{
protected: 
	int numOfPoints; //The number of points of the shape
	Point** theLine; //the shape

public:

	Shape() : numOfPoints(0), theLine(nullptr) {};
	Shape(int);
	Shape(const Shape&); //Copy constructor
	Shape(Shape&& sh); // move constructor
	friend ostream& operator>>(ostream& os, const Shape& sh);
	virtual ~Shape();
	virtual float area() const = 0; 
	virtual bool isSpecial() const =0;
	virtual void printSpecial()const =0;
	friend ostream& operator<<(ostream& os, const Shape& sh);
};

#endif // ! SHAPE_H
