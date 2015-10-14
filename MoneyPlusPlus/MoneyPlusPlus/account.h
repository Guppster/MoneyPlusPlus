#pragma once
#include <iostream>
#include <istream>
#include <string>

using namespace std;

class Account
{
public:
	int isSaving;			// 1 = true, 0 = false
	int approved;			// 1 = true, 0 = false
	int balance;
	string name;

	Account();
	Account(int type, string _name, int amount, int status);

	void deposit(int);
	void withdraw(int);
	int checkBalance();

	void setName(string);
	void setType(int);
	void setBalance(int);
	void setApproved(int);

	int getApproved();
	string getName();
	int getType();
	int getBalance();
};