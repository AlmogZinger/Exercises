/*************************************
* Studant name: Almog Zinder I.D 206554941
* Course title: Curse on C++.
* Exercise for home num. 5 question num.2
* The oparation of the class List.
*****************************************/
#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;


Employee::Employee(string new_name = "", int new_id = 0, int new_seniority = 0) //•	constructor and empty constructor.
{
	if (!(new_id < 0 || new_name.length() == 0 || new_seniority < 0)) {

		name = new_name;
		id = new_id;
		seniority = new_seniority;
		pay = 0;
	}
}
Employee:: Employee(const Employee &  em) // Copy constructor.
{
	name = em.name;
	id = em.id;
	seniority = em.seniority;
	pay = em.pay;
}

int Employee:: salaryAfterBonus()
{
	if (seniority > 5)
		pay = pay * 1.25;
	else
		pay = pay + 500;
	return pay;
}

ostream& operator<<(ostream& os, const Employee& em)
{
//Print the emplyee details:
	os << "Employee: " << em.name << endl
		<< "Employee ID: " << em.id << endl
		<< "Years Seniority: " << em.seniority << endl;
	return os;
}

istream& operator>>(istream& is, Employee& em)
{
	//Insert the detalis to the object 'Employee'.
	string new_name;
	int new_id, new_sen;
	cout << "Enter employee details:" << endl;
	is >> new_name >> new_id >> new_sen;
	if (new_id < 0 || new_name.length() == 0 || new_sen < 0) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	throw "field in detiels in Employee class";
	}
	em.name = new_name;
	em.id = new_id;
	em.seniority = new_sen;
	em.pay = 0;
	return is;
}