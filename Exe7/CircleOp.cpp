#include "Shape.h"
#include "Circle.h"

const float PI = 3.14f;
Circle::Circle() :Shape(0) //Empty  Constractor
{
	radius = 0;
}
Circle::Circle(float r) :Shape(1) //one parameter  Constractor
{
	if (r < 0)
		throw "ERROR";
	radius = r;
}
Circle:: Circle(const Circle& other) : Shape(other) // Copy Constractor
{
	radius = other.radius;
}
Circle::~Circle()
{
	delete this;
}
bool Circle::isSpecial() const
{
	Point p(0, 0);
	return (**theLine == p);
}
void Circle::printSpecial() const
{
	if (isSpecial())
	cout << " A canonical circle with a radius " << radius << endl;
}

float Circle:: area() const
{
	return radius * radius * PI;
}