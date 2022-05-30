#include "PartTime.h"
#include <iostream>
#include <string>
using namespace std;

PartTime:: PartTime (string name, int id, int seniority, int new_hoursOfWork, float new_payPerHour): Employee(name, id, seniority) //•	constructor and empty constructor.
{
	if (new_hoursOfWork < 0|| new_payPerHour < 0)
		throw "field in detiels in FullTime class";
	//Using the constructor of the father.
	hoursOfWork  = new_hoursOfWork; //Update the number of work hour in this month.
	payPerHour =new_payPerHour; //Update the salay of the employee for one hour.
}
PartTime::PartTime(const  PartTime& other) : Employee(other) //Using the copy constructor of the father.// Copy constructor.
{
	hoursOfWork = other.hoursOfWork; //Update the number of work hour in this month.
	payPerHour = other.payPerHour; //Update the salay of the employee for one hour.
}

float PartTime::salary() const //Return the salary for one month.
{
	return (float)hoursOfWork * payPerHour; //Multy the num of hour at the month with the pay per hour.
}
ostream& operator<<(ostream& os, const PartTime& ft)
{
	const Employee* temp = &ft; //A father pointer that allow as to get to the oparotor "<<" of the father.
	os << *temp; //Inialize values with the oparetor "<<" of the father.
	os << "Hours: " << ft.hoursOfWork << endl; //Print the number of the work hour of the employee
	os << "Salary per Month: " << ft.salary() << endl; //Print his salary for the monyh of the employee.
	return os;
}


istream& operator>>(istream& is, PartTime& ft)
{
	//A father pointer that allow as to get to the oparotor ">>" of the father. for the fields - name,id,seniority,pay
	Employee* temp = &ft;
	is >> *temp;//Inialize values with the oparetor "<<" of the father.
	//Continue with the extra fildes of the son.
	int new_hoursOfWork;
	float new_payPerHour;
	is >> new_hoursOfWork>> new_payPerHour;
	if (new_hoursOfWork < 0 || new_payPerHour < 0)
		throw "field in detiels in FullTime class";
	ft.hoursOfWork = new_hoursOfWork;
	ft.payPerHour = new_payPerHour;
	ft.pay = ft.salary();
	return is;
}