#include <iostream>
using namespace std;
#include "List.h"

enum CHOICES { EXIT, INSERT, REMOVE, ASSIGN, PRINT };

int main() {
	List lst;
	List lst2;
	int choice, val;

	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-4\n";
	cin >> choice;
	while (choice != EXIT) {
		switch (choice) {
		case INSERT:
			cout << "enter a value to insert\n";
			cin >> val;
			try {
				lst.insert(val);
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			break;
		case REMOVE:
			cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
			break;
		case ASSIGN:
			try {
				lst2 = lst;
				cout << "list 2: " << lst2;
				cout << "list 1: ";
			}
			catch (const char* msg) {
				cout << msg << endl;
			}
		case PRINT:
			cout << lst << endl;
			break;
		default:cout << "ERROR\n";
		}
		cout << "choose 0-4\n";
		cin >> choice;
	}
	return 0;
}

