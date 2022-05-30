#pragma once
#ifndef EMPOLYEE_H
#define EMPOLYEE_H
/*************************************
* Studant name: Almog Zinder I.D 206554941
* Course title: Curse on C++.
* Exercise for home num. 5 question num.2
* The oparation of the class List.
*****************************************/
#include <string>
using namespace std;

class Employee
{
protected:
	string name; //The name of the employee.
	int id; // The ID of the employee.
	int seniority; //The number of year that he work in the company.
	float pay; //His salary for one month.
public:
	Employee(string, int, int); //•	constructor and empty constructor.
	Employee(const Employee& ); // Copy constructor.


	//void setName(string);
	//void setId(int);
	//void setSeniority(int);
	//void setPay(float);

	//string getName();
	//int getId();
	//int getSeniority();
	//float getPay();

	int salaryAfterBonus();

	friend ostream& operator<<(ostream& os, const Employee& em);
	friend istream& operator>>(istream& is, Employee& em);




};





#endif // !EMPOLYEE_H