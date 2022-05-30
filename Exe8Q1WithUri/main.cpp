/********************************
Uri Ehrlich 208967976 and Almog Zinger 206554941
Programming in C++
Exercise 8 question 1
The program runs an alghorithm of infix and postfix string
*********************************/

#include "Vector.h" 
#include "Stack.h"
#include "StackVector.h"
#include <iostream>
using namespace std;

int main() {

	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	try {
		string postfix = infixToPostfix(exp);
		cout << "in postfix form: " << postfix << endl;

		cout << "calculated value: " << calcPostfix(postfix) << endl;
	}
	catch ( const char* msg) { cout << msg << endl; }

	return 0;
}

/*
enter an infix expression as a string
(5+3)*((20/10)+(8-6))
in postfix form: 5 3 + 20 10 / 8 6 - + *
calculated value: 32
*/