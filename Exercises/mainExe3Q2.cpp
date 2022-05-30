#include "MyDate.h"
#include <iostream>

using namespace std;


enum CHOICE {
	EXIT, UPDATE, FIRST, LAST, ASSIGNING,IS_EARLIER,IS_LATER, IS_EQUAL
};

MyDate getDateFromUser()
{
	int day, month, year;
	char junk;
	cout << "enter a date" << endl;
	cin >> day >> junk >> month >> junk >> year;
	return MyDate(day, month, year);
}

void setDateByUser(MyDate &md)
{
	int day, month, year;
	char junk;
	cout << "enter a date" << endl;
	cin >> day >> junk >> month >> junk >> year;
	md.setDate(day, month, year);
}

int main()
{

	int op;
	MyDate md;

	MyDate firstMd = getDateFromUser();

	cout << "Enter a code" << endl;
	cin >> op;
	while (op != EXIT)
	{
		switch (op) 
		{
		case UPDATE:
			setDateByUser(md);
			md.print();
			cout << endl;
			break;
		case FIRST:
			md2 = ++*md;
			md2.print();
			cout << endl;
			md->print();
			cout << endl;
			break;
		case LAST:
			md2 = *md++;
			md2.print();
			cout << endl;
			md->print();
			cout << endl;
			break;
		case ASSIGNING:
			md = getDateFromUser();
			firstMd = md;
			firstMd.print();
			cout << endl;
			break;
		case IS_EARLIER:
			md = getDateFromUser();
			cout << firstMd << " > " << md << " : ";
			if (firstMd < md)
				cout << "true";
			else
				cout << "false";
			break;
		case IS_LATER:
			cout << "enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			md2.setDate(day, month, year);
			md->print(); cout << " > "; md2.print(); cout << ":";
			if (*md > md2)
				cout << "true";
			else
				cout << "false";
			break;
		case ISEQUAL:
			cout << "enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			md2.setDate(day, month, year);
			md->print(); cout << " == "; md2.print(); cout << ":";
			if (*md == md2)
				cout << "true";
			else
				cout << "false";
			break;
		}
		cout << "Enter a code" << endl;
		cin >> op;
	}

	return 0;
}


