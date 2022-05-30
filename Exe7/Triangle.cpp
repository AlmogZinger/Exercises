#include "Triangle.h"
#include "Point.h"
#include <cmath>

Triangle::Triangle() : Shape(3) //Empty constractor
{
	//Initializes the length of the sides.
	Lengths[0] = theLine[0]->getDistance(*theLine[1]);
	Lengths[1] = theLine[1]->getDistance(*theLine[2]);
	Lengths[2] = theLine[2]->getDistance(*theLine[0]);
}
bool Triangle::isSpecial() const//If the triangle is a equilateral triangle
{
	if (Lengths[0]==Lengths[1])
		if (Lengths[1] == Lengths[2])//If the the all sudes are equal.
			return true;
	return false;
}
void Triangle::printSpecial() const // Print the msg " An equilateral triangle with a side length #  " # is the length of eatch side.
{
	if (isSpecial())
	cout << " An equilateral triangle with a side length " << Lengths[0] << endl;
}
float Triangle::area() const //The area of the triangle by haron's formula. 
{
	float s = (Lengths[0] + Lengths[1] + Lengths[2]) / 2;
	return sqrt(s * (s - Lengths[0]) * (s - Lengths[1]) * (s - Lengths[2]));
}

Triangle::~Triangle() //  destructor
{
	for (int i = 0; i < 3; i++)
		Lengths[i] = 0;
	delete this;
}