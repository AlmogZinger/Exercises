#pragma once
#ifndef FULLTIME_H
#define FULLTIME_H
#include "Employee.h"

class FullTime : public Employee
{
	float salaryPerYear; //The salay of the employee for one year.
public:
	FullTime(string name = "", int id = 0, int seniority = 0, float new_salaryPerYear = 0); //•	constructor and empty constructor.
	FullTime(const FullTime&); // Copy constructor.

 float salary() const ;

	friend ostream& operator<<(ostream& os, const FullTime& ft);
	friend istream& operator>>(istream& is, FullTime& ft);

};

#endif // !FULLTIME_H