#include "MyString.h"
#include <iostream>

using namespace std;

int main()
{
	MyString a, b,c; //The strings
	int n;
	char ch;
	cin >> a >> b >> n; 
	cout << "a";
	if (a > b)
		cout << ">";
	else if (a == b)
		cout << "=";
	else cout << "<";
	cout << "b" << endl;


	 c= b.insert(n, a.getStr());
	 cout << c << endl;

	cin >> ch >> n;
	if (n < c.getLen() && n >= 0)
	{
		c[n] = ch;
		cout << c << endl;
	}
	else cout << "ERROR";
	return 0;
}