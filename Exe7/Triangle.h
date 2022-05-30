#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include <iostream>
using namespace std;

class Triangle : public Shape
{
protected:
	float Lengths[3] = {0, 0, 0}; //The length of each side in the triangle.
public:
	Triangle(); //Empty constractor
	bool isSpecial() const;//If the triangle is a equilateral triangle
	void printSpecial() const; // Print the msg " An equilateral triangle with a side length #  " # is the length of eatch side.
	float area() const; //The area of the triangle by haron's formula. 
	~Triangle();

private:

};


#endif // !TRIANGLE_H