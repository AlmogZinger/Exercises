#include "FullTime.h"
#include <iostream>
#include <string>
using namespace std;

FullTime::FullTime(string name, int id, int seniority, float new_salaryPerYear): Employee(name, id, seniority) //•	constructor and empty constructor.
{
	if (new_salaryPerYear < 0)
		throw "field in detiels in FullTime class";
	//Using the constructor of the father.
	salaryPerYear = new_salaryPerYear; //Update the last field.
}
FullTime::FullTime(const FullTime& other): Employee(other) // Copy constructor.
{
	//Employee temp = other; //Shallow copy - pointer to other as a employee.
	//Employee(temp);         //Using the copy constructor of the father.
	salaryPerYear = other.salaryPerYear;//Update the last field.
}

float FullTime::salary() const
{
	return salaryPerYear / 12.0f;
}
 ostream& operator<<(ostream& os, const FullTime& ft)
{
	 const Employee *temp = &ft; //A father pointer that allow as to get to the oparotor "<<" of the father.
	 os << *temp; //Inialize values with the oparetor "<<" of the father.
	 os << "Salary per Month: " << ft.salary()<<endl; //Continue with the extra filde of the son.
	 return os;
}


 istream& operator>>(istream& is, FullTime& ft)
 {
	  Employee* temp = &ft;//A father pointer that allow as to get to the oparotor ">>" of the father.
	 is >> *temp;//Inialize values with the oparetor "<<" of the father.
	 //Continue with the extra fildes of the son.
	 float new_salary_for_year;
	 is >> new_salary_for_year;
	 if (new_salary_for_year < 0)
		 throw "field in detiels in FullTime class";
	 ft.salaryPerYear = new_salary_for_year;
	 ft.pay = ft.salary();
	 return is;
}