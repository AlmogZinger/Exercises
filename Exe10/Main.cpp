#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include "Soldier.h"
#include "PrivateSoldier.h"
using namespace std;

enum option {
	EXIT,	//	סיום התוכנית
	ADD_NEW_SOLDIER,	//	הוספת חייל חדש
	DESERVES_MEDAL,	//	הדפסת פרטי כל החיילים הזכאים לצל"ש
	HIGHEST_SOCIOMETRIC,	//הדפסת שם (משפחה ופרטי) של  החייל בעל ציון סוציומטרי מקסימלי 
	PRIVATE_MEDAL_COUNT,	//	הדפסת מספר החיילים הטירוניים הזכאים לצל"ש
	NONCOMBAT_COMMANDER,	//	הדפסת שמות (משפחה ופרטי) של המפקדים שאינם בקרבי
	SUPER_SOLDIER,   //הדפסת הודעה מתאימה, האם קיים חייל שהשתתף ביותר מ- 15  מבצעים צבאיים
	REMOVE_OFFICER,	//	מחיקת כל החיילים הקצינים שלא השתתפו כלל במבצע צבאי
};

enum Type {
	PRIVATE=1,// Private soldier.
	COMM,//Commander soldier
	OFFICER //Officer soldier
};


void add(vector<Soldier*> army)
{
	vector<int> new_grades;
	Soldier* s1;
	int choose, new_ID, new_numOfOp;
	string new_fname, new_lname;
	cout << "choose a soldier\n";
	cout << "enter 1 to add a private\n";
	cout << "enter 2 to add a commander\n";
	cout << "enter 3 to add an officer\n";
	cin >> choose;
	cout << "enter id, first name, last name and number of operations\n";
	cin >> new_ID>> new_fname >>new_lname>> new_numOfOp; //Get the reguler value..

	switch (choose) {
	case PRIVATE:
		int oneGrade;
		cout << "enter " << new_numOfOp << " grades\n";
		for (int i = 0; i < new_numOfOp; i++)
		{
			cin >> oneGrade;
			new_grades.insert(new_grades.begin(), oneGrade);
		}
		s1 = new PrivateSoldier(new_ID, new_fname, new_lname, new_numOfOp, new_grades);
		army.insert(army.begin(), s1);


		break;
	case COMM:
		cout << "enter 1 if the soldier is combat and 0 if not\n";
		s1 = new co
		break;
	case OFFICER:
		cout << "enter the sociometric score\n";
		s1 = new Officer
		break;
	}

}

