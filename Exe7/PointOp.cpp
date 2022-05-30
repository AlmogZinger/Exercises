#include "Point.h"
#include <cmath>


Point::Point() { x = 0; y = 0; }//Empty constructor.
Point::Point(int myX, int myY) {
	x = myX;	y = myY;
}//Two parameter constructor.

int Point::getX() { return x; } //Return the x value.
void Point::setX(int myX) { x = myX; }//Set value for x.
int Point::getY() { return y; }//Return the y value.
void Point::setY(int myY) { y = myY; }//Set value for y.
float  Point::getDistance(Point p)//Return the distance beetwen two points.
{
	return (float)sqrt(pow((p.x - x), 2) + pow((p.y - y), 2));
}

bool Point::isEquel(Point other)//Return true if the values of x and y of the two points are equel.
{
	return (x == other.x) && (y == other.y);
}

Point& Point:: operator= (const Point& p )
{
	x = p.x;
	y = p.y;
	return *this;
}

bool Point:: operator== (const Point& p)
{
	return (x==p.x)&&(y==p.y);
}
istream& operator>>(istream& is, Point& p)
{
int x, y;
char junk;
is >> junk >> x >> junk >> y >> junk;
p.x = x;
p.y = y;
	return is;
}
ostream& operator<<(ostream& os, const Point& p) {
	os << '(' << p.x << ',' << p.y << ')';
	return os;
}