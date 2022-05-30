#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H 


class  Rational
{
private:
	int numerator;
	int denominator;

public:

	Rational();
	Rational(int num,int den);
	Rational(const Rational &other);
	void setNumerator(int const);
	int getNumerator() const; 
	void setDenominator(int const);
	int getDenominator() const; 
	void print() const;
	void  reduction();

	Rational operator+(Rational const& other) const;
	Rational operator-(Rational const& other) const;
	Rational operator*(Rational const& other) const;
	Rational operator/(Rational const& other) const;
	Rational operator++(int);
	Rational operator--(int);
	Rational operator++();
	Rational operator--();
	bool operator>=(Rational const& other) const;
	bool operator<=(Rational const& other) const;
	bool operator>(Rational const& other) const;
	bool operator<(Rational const& other) const;
	bool operator==(Rational const& other)  const;
	bool operator!=(Rational const& other) const;


};
#endif // !RATIONAL_H