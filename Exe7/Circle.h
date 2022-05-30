#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "Shape.h"
using namespace std;

class Circle : public Shape
{
	float radius; // The radius of the circle.
public:
	Circle(); //Empty constractor
	Circle(float r=0); //Constractor
	Circle(const Circle &other); // Copy Constractor
	bool isSpecial() const;//If the circle is a canonical circle
	void printSpecial() const; // Print the msg " A canonical circle with a radius # " # is the radius.
	float area() const; //The area of the circle - radius^2*PI
	~Circle();


};
#endif // !CIRCLE_H