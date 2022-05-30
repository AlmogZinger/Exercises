/********************************
Uri Ehrlich 208967976 and Almog Zinger 206554941
Programming in C++
Exercise 9 question 2
The program runs an alghorithm of library using a bst
*********************************/
#include <iostream>
#include "Book.h"
#include "SearchTree.h"

using namespace std;
enum ACTION { //choises

	ADD='a',
	DELETE,
	SEARCH,
	PRINT_ALL,
	EXIT
};

char menu() {
	cout << "enter a-e" << endl;

	char x;
	cin >> x;
	if (x < 'a' || x>'e')
		throw "error";
	return x;
}
int main(){
	

	SearchTree<Book> library; 

	char ac = menu();
	while (ac != 'e') {
		switch (ac) {
		case ADD:
			try {
				Book b1 ;
				cout << "enter a book" << endl;
				cin >> b1;
				library.add(b1);
				
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			break;
		case DELETE:
			try {
				Book b1;
				cout << "enter a book" << endl;
				cin >> b1;
				library.remove(b1);
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			break;
		case SEARCH:
			try {
				Book b1;
				cout << "enter a book" << endl;
				cin >> b1;
				if (library.search(b1))
					cout << "exist" << endl;
				else
					cout << " not exist" << endl;
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			break;
		case PRINT_ALL:
			try {
				library.inOrder();
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			break;
		}
		try {
			ac = menu();
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
	
	}
	return 0;
}