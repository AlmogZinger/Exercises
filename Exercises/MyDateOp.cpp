#include <iostream>
#include "MyDate.h"

using namespace std;

const int MAX_DAY_IN_MONTH = 30;
const int MAX_MONTHS_IN_YEAR = 12;
const int MIN_YEAR= 1920;

MyDate::MyDate(int MyDay, int MyMonth , int MyYear )
{
	if (MyDay > MAX_DAY_IN_MONTH || MyDay < 0)
	{
		MyDay = 1;
		cout << "Error day \n";
	}
	if (MyMonth > MAX_MONTHS_IN_YEAR || MyMonth < 0)
	{
		MyMonth = 1;
		cout << "Error month \n";
	}
	if (MyYear < MIN_YEAR)
	{
		MyYear = MIN_YEAR;
		cout << "Error year \n";
	}

	day = MyDay;
	month = MyMonth;
	year = MyYear;
}
MyDate::MyDate(const MyDate& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
}

MyDate:: ~MyDate()
{
	day = month = year = 0;
}

void  MyDate::setDate(int const MyDay, int const MyMonth, int const MyYear)
{
	if (MyDay < MAX_DAY_IN_MONTH && MyDay > 0)
		if (MyMonth < MAX_MONTHS_IN_YEAR && MyMonth > 0)
			if (MyYear > MIN_YEAR)
			{
				day = MyDay;
				month = MyMonth;
				year = MyYear;
			}
}

void  MyDate::print() const
{
		cout << day << "/"
			<< month << "/"
			<< year;
}
 MyDate MyDate :: operator++(int dame)
{
	 if (day == 30)
	 {
		 day = 1;
		 if (month == 12)
		 {
			 month = 1;
			 year++;
		 }
		 else
			 month++;

	 }
	 else
		 day++;
	 return *this;
}
 MyDate MyDate:: operator++()
 {
	 MyDate temp(*this);
	 int dam= 0;
	 this->operator++(dam);
	 return temp;
}

 MyDate MyDate:: operator=(MyDate other)
 {
	 day = other.day;
	 month = other.month;
	 year = other.year;
	 return *this;
}

 bool MyDate:: operator<(MyDate const other) const
 {
	 if (year < other.year) //If the year is eariler - return true.
		 return true;
	 else if (year == other.year)
		 if (month < other.month)//If the year is the same but the month is earlier  - return true.
			 return true;
		 else
			 //If the year and the month is the same but the day is earlier  - return true.
			 if ((month == other.month) && (day < other.day))
				 return true;
	 //If not earlier -return false.
	 return false;
}

 bool MyDate:: operator==(MyDate const other) const
 {  
	return (year == other.year) && (month == other.month) && (day == other.day);
}
 bool MyDate:: operator>(MyDate const other) const
 {
	 return  !((*this==other) || (*this < other));
}

 ostream& operator<<(ostrem& os, const MyDate& md)
 {
	 os << md.day << '/' << md.month << '/' << md.year;
	 return os;
 }
