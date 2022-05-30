#include "Account.h"
#include <iostream>
using namespace std;

const int MAX_MINUS = -6000;
const int MAX_WITHDRAWAL = 2500;
const int MAX_DEPOSIT = 10000;

int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;

void checking(int ac, int cd, string em)
{
	string endOfEmail;
	bool flag = false;
	int place = em.find("@"); //The place of the '@' in the string.
	int placeDot = em.find_last_of(".",place);////The place of the '.' in the string after the '@'.
	if (place > -1 && placeDot > -1)
	{ // If there is @ and a dot after it.
		 endOfEmail = em.substr(placeDot,10); 
		flag = true;
	}
	
	if (ac <= 0)
		throw "ERROR: account number must be positive number! \n";
	if (cd < 1000 || cd > 9999)
		throw "ERROR: code must be of 4 digits! \n";
	if (place == -1)
		throw "ERROR: email must contain @! \n";
	if (place == 0)
		throw "ERROR: wrong email! \n";
	if (place>place)
		throw "ERROR: email must end at .com or .co.il! \n";
	if (flag && endOfEmail.compare(".com") && endOfEmail.compare(".co.il"))
		throw "ERROR: email must end at .com or .co.il! \n";

}
Account:: Account(int get_accountNumber, int get_code,  string get_email,int get_balance = 0)//•	constructor
{
	accountNumber = 0;
	code = 0;
	balance = 0;
	email = "";
	checking(get_accountNumber, get_code, get_email);
	accountNumber = get_accountNumber;
	code = get_code;
	balance = get_balance;
	email = get_email;
}

int Account::getAccountNumber(){ return accountNumber;}
int Account::getCode() { return code; }
int Account::getBalance() { return balance; }
string Account::getEmail() { return email; }

void  Account:: withdraw(int nis)
{
	if (balance - nis < MAX_MINUS)
		throw "ERROR: cannot have less than - 6000 NIS!\n";
	if (nis > MAX_WITHDRAWAL)
		throw "ERROR: cannot withdraw more than 2500 NIS! \n";
	balance -= nis;
	sumWithdraw+=nis; 
}

void Account::deposit(int nis)
{
	if (nis > MAX_DEPOSIT)
		throw "ERROR: cannot deposit more than 10000 NIS! \n";
	balance += nis;
	sumDeposit+=nis;
}

int Account::getSumWithdraw()
{
	return sumWithdraw;
}

int Account::getSumDeposit()
{
	return sumDeposit;
} 


istream& operator>>(istream& is, Account& ac)
{
	//Receive the hour.
	int nac,cd;
	string em;
	is >> nac >>cd>>em;

	//Try to enter the new valus.
	ac = Account(nac, cd, em);
	return is;
}