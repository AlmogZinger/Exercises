#include "Rectangle.h"
#include "Point.h"
#include <cmath>

Rectangle ::Rectangle() : Shape(4) //Empty constractor
{
	//Initializes the length of the sides.
	Lengths[0] = theLine[0]->getDistance(*theLine[1]);
	Lengths[1] = theLine[1]->getDistance(*theLine[2]);
}
bool Rectangle::isSpecial() const//If the triangle is a equilateral triangle
{
	if (Lengths[0] == Lengths[1])//If the the all sides are equal.
		return true;
	return false;
}

Rectangle::~Rectangle() //  destructor
{
	for (int i = 0; i < 2; i++)
		Lengths[i] = 0;
	delete this;
}
void Rectangle::printSpecial() const // Print the msg " An equilateral triangle with a side length #  " # is the length of eatch side.
{
	if (isSpecial())
	cout << "Square with side length " << Lengths[0] << endl;
}
float Rectangle::area() const //The area of the rectangle
{
	return Lengths[0] * Lengths[1];
}