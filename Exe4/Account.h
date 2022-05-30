#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account
{
private:
	int accountNumber;
	int code;
	int balance;
	string email;
	static 	int sumWithdraw;
	static int	sumDeposit;
public:
	Account() :accountNumber(0), code(0), balance(0), email("") {}//•	empty constructor  
	Account(int, int, string, int);//•	constructor

	int getAccountNumber();
	int getCode();
	int getBalance();
	string getEmail();

	void withdraw(int nis);
	void deposit(int nis);

	friend istream& operator>>(istream& is, Account& );

	static int getSumWithdraw();
	static int  getSumDeposit();
};

#endif // !ACCOUNT_H

