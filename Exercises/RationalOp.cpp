#include "Rational.h"
#include <iostream>
using namespace ::std;

const int NEGATIVE = -1; //Const for negative number.


Rational::Rational() //•	Empty constructor
{
	numerator = 1;
	denominator = 1;
}
Rational::Rational(int num, int den) //•	Two value's constructor
{
	if (den > 0)
	{ //If the denominator is a positive number.
		numerator = num; 
		denominator = den;
	}
	else if (den < 0)
	{ //If the denominator is a negitive number.
		numerator = num * NEGATIVE;
		denominator = denominator * NEGATIVE;
	}
	else
	{ //If the denominator is 0.
		numerator = num;
		denominator = 1;

	}
}
Rational::Rational(const Rational& other) //•	copy constructor
{
	numerator = other.numerator;
	denominator = other.denominator;
}

void Rational::setNumerator(int  const num)
{
	numerator = num;
}
int Rational::getNumerator() const
{
	return numerator;
}

void Rational:: setDenominator(int const den)
{
	if (den) //If den isn't 0.
	{
		if (den > 0) //	If den is a positive number.
			denominator = den;
		else
		{ //	If den is a negitive number.
			denominator = den * NEGATIVE;
			numerator = numerator * NEGATIVE;
		}
	}
	else //If den is 0
		denominator = 1;
}
int Rational::getDenominator()  const
{
	return denominator;
}

void Rational::print()  const//Print the retional.
{
	if (denominator == 1) //If den is 1 - print only the numerator
		cout << numerator;
	else
		cout << numerator << "/" << denominator;
}



void Rational::reduction()
{
	if (numerator)
	{
		//Takr the higher number between numerator and denominator.
		int num = abs(numerator);
		int max = (denominator < num ? denominator : num);

		//Finds the largest divider.
		for (; denominator % max || num % max; max--);

		//Divide the number by the divisor
		numerator /= max;
		denominator /= max;
	}
	else denominator = 1; //If numerator is 0 , set denominator as 1.
}


Rational Rational:: operator+(Rational const &other) const
{
	Rational adder;
	//Summarize the numbers according to their common denominatorץ
	adder.numerator = denominator * other.numerator + other.denominator * numerator;
	adder.denominator = denominator * other.denominator;

	adder.reduction();
	return adder;
}
Rational Rational:: operator-(Rational const &other) const
{
	//Adding the first with the negative of the secound.
	Rational temp = other;
	temp.numerator *= NEGATIVE;
	return *this + temp;
}

Rational Rational:: operator*(Rational const  &other)  const
{
	//Multiplies the numerator and denominators of each other
	Rational temp(numerator * other.numerator, denominator * other.denominator);
	temp.reduction();
	return temp;
}

Rational Rational:: operator/(Rational const &other) const
{
	//Multiplies the first number by the inverse of the secondץ
	Rational temp(other.denominator,other.numerator);
	temp = *this * temp;
	temp.reduction();
	return temp;
}
Rational Rational:: operator++(int dame) 
{
	Rational temp = *this;
	numerator += denominator;
	return temp;
}
Rational Rational:: operator--(int dame) 
{
	Rational temp = *this;
	numerator -= denominator;
	return temp;
}
Rational Rational:: operator++() 
{
	numerator += denominator;
	return *this;
}
Rational Rational:: operator--()
{
	numerator -= denominator;
	return *this;
}
bool Rational:: operator>=(Rational const &other) const //Return true if the first number >= than the other one.
{
	return (*this > other || *this == other);
}
bool Rational:: operator<=(Rational const& other) const //Return true if the first number <= than the other one.
{
	return (*this < other || *this == other);
}
bool Rational:: operator>(Rational const& other) const //Return true if the first number > than the other one.
{
	return ((*this - other).numerator > 0);
}
bool Rational:: operator<(Rational const& other) const//Return true if the first number < than the other one.
{
	return ((*this - other).numerator < 0);
}
bool Rational:: operator==(Rational const& other) const//Return true if the first number == than the other one.
{
	Rational temp1 = *this;
	Rational temp2 = other;
	temp1.reduction();
	temp2.reduction();
	return (temp1.numerator == temp2.numerator) && (temp1.denominator == temp2.denominator);
}
bool Rational:: operator!=(Rational const& other) const //Return true if the first number != than the other one.
{
	return !(*this == other);
}

