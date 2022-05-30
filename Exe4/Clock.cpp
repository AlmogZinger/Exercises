#include "Clock.h"
#include <iostream>
using namespace std;

bool checking(int s,int m,int h)
{
	if (s < 0)
		throw "Invalid time - negative number of seconds.\n";
	if (s > 59)
		throw "Invalid time - more than 60 seconds.\n";
	if (m < 0)
		throw "Invalid time - negative number of minutes.\n";
	if (m > 59)
		throw "Invalid time - more than 60 minutes.\n";
	if (h < 0)
		throw "Invalid time - negative number of hours.\n";
	if (h > 23)
		throw "Invalid time - more than 24 hours.\n";
	return true;
}
Clock:: Clock (int h, int m, int s) //Parameters constructor.
{
	hour = 0, minute = 0, second = 0;
	checking(s,m,h);
	 hour = h, minute = m, second = s;
}

void Clock:: setHour(int h)
{
	if (h < 0)
		throw "Invalid time - negative number of hours.\n";
	if (h > 23)
		throw "Invalid time - more than 24 hours.\n";
	hour = h;
}
void Clock::setMinute(int m)
{
	if (m < 0)
		throw "Invalid time - negative number of minutes.\n";
	if (m > 59)
		throw "Invalid time - more than 60 minutes.\n";
	minute = m;
}
void Clock::setSecond(int s)
{
	if (s < 0)
		throw "Invalid time - negative number of seconds.\n";
	if (s > 59)
		throw "Invalid time - more than 60 seconds.\n";
	second = s;
}

int Clock::getHour() { return hour; }
int Clock:: getMinute() { return minute; }
int Clock:: getSecond() { return second; }

Clock Clock:: operator+=(int amount) //Increase the hour by seconds.
{
	if (amount < 0) //If enter a positive amount of second.
		throw "Invalid time - negative number of seconds.\n"; 

	int s,m, h;
	
	s = amount % 60 +second;
	m = amount / 60 % 60 + minute +s/60;
	h =   hour+ m/60;

	second = s % 60;
	minute = m % 60;
	hour = h % 24;

}
ostream& operator<<(ostream& os, const Clock& c)
{	
		if (c.hour < 10)
		os << "0" << c.hour << ":";
	else
		os << c.hour << ":";


	if (c.minute < 10)
		os << "0" << c.minute << ":";
	else
		os << c.minute << ":";

	if (c.second < 10)
		os << "0" << c.second << '\t';
	else
		os << c.second << '\t';





	return os;
}

istream& operator>>(istream& is, Clock& c)
{
	c.second = 0;
	c.minute = 0;
	c.hour = 0; 

	//Receive the hour.
	int s,m,h;
	char junk;
	is >> s>>junk>>m>>junk>>h;

	//Try to enter the new valus.
	checking(s, m, h);
		c.second = s;
		c.minute = m;
		c.hour = h;
	
	return is;
}
