
#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
class Point {

private:
	int x; //The x value.
	int y;//The y value.

public:
	Point(); //Empty constructor.
	Point(int myX, int myY); //Two parameter constructor.

	int getX(); //Return the x value.
	void setX(int myX); //Set value for x.
	int getY();//Return the y value.
	void setY(int myY);//Set value for y.
	float getDistance(Point p); //Return the distance beetwen two points.
	bool isEquel(Point other); //Return true if the values of x and y of the two points are equel.
	Point&  operator= (const Point& p);
	bool operator== (const Point& p);
	friend istream& operator>>(istream& is, Point& p); 
	friend ostream& operator<<(ostream& os, const Point& p);
};
#endif // !POINT_H#pragma once
