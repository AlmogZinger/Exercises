#include"PrivateSoldier.h"

bool PrivateSoldier::medal()
{
	if (numOfOp >= 10)
	{
		float sum = 0;
		for (int i = 0; i < numOfOp; i++)
		{
			sum += grades[i];
		}
		if ((float)sum / numOfOp > 95)
			return true;
		else
			return false;
	}
	return false;
}

void PrivateSoldier::print()
{
	cout << "private" << endl;
	cout << "ID: " << ID << endl;
	cout << "first name: " << fname << endl;
	cout << "last name: " << lname << endl;
	cout << "num operations: " << numOfOp << endl;
	cout << "grades: ";
	vector<int>::iterator it2 = grades.begin();
	while (it2 != grades.end())
	{
		cout << *it2 << " ";
		++it2;
	}
	cout << endl;
}
PrivateSoldier::PrivateSoldier(const PrivateSoldier& p)
{
	for (int i = 0; i < p.grades.size(); i++)
	{
		grades[i] = p.grades[i];
	}
	this->ID = p.ID;
	this->numOfOp = p.numOfOp;
	this->fname = p.fname;
	this->lname = p.lname;
}