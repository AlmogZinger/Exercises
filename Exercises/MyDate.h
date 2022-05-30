#pragma once
#ifndef MYDATE_H
# define MYDATE_H
class MyDate
{
private:
	int day;
	int month;
	int year;
public:
	MyDate(int MyDay = 1, int MyMonth = 1, int MyYear = 1920);
	MyDate(const MyDate& other);
	~MyDate();

	void setDate(int const MyDay, int const MyMonth, int const MyYear);
	void print() const;

	MyDate operator++(int dame);
	MyDate operator++();

	MyDate operator=(MyDate);

	bool operator<(MyDate const) const;
	bool operator>(MyDate const) const;
	bool operator==(MyDate const) const;
	friend ostream& operator<<(ostream& , const MyDate& );

};

#endif // !MYDATE_H 

