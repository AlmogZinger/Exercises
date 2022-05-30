#pragma once
#ifndef CLOCK_H
#define CLOCK_H
#include<iostream>
using namespace std;
class Clock
{
private:
	int hour;	//The hour between 0-23
	int minute; // The minute between 0-59
	int second; //The second between 0-59

public:
	Clock(int h, int m, int s); //Parameters constructor.
	
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);

	int getHour();
	int getMinute();
	int getSecond();

	Clock operator+=(int s); //Increase the hour by seconds.
	friend ostream& operator<<(ostream& os, const Clock& c);
	friend istream& operator>>(istream& is, Clock& c);

};


#endif // !CLOCK_H

