#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle : public Shape
{
protected:
	float Lengths[2] = { 0, 0}; //The length of sides of the rectangle.
public:
	Rectangle(); //Empty constractor
	bool isSpecial() const;//If the rectangle is sqaure.
	void printSpecial() const; // Print the msg "Square with side length # " # is the length of the side of the square.
	float area() const; //The area of the rectangle. 
	~Rectangle();
};


#endif // !RECTANGLE_H