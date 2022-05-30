#pragma once
#ifndef PART_TIME_H
#define PART_TIME_H
#include "Employee.h"


class PartTime : public Employee
{
private:
	int hoursOfWork; //The number of work hour in this month.
	float payPerHour; //The salay of the employee for one hour.
public:
	PartTime(string name = "", int id = 0, int seniority = 0, int new_hoursOfWork = 0, float new_payPerHour = 0); //•	constructor and empty constructor.
	PartTime(const PartTime&); // Copy constructor.

	float salary() const;

	friend ostream& operator<<(ostream& os, const PartTime& ft);
	friend istream& operator>>(istream& is, PartTime& ft);

};



#endif //PART_TIME