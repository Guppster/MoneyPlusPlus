#pragma once
#include <iostream>
#include <istream>
#include <string>

using namespace std;

class Account
{
public:
	bool isSaving;
	int balance;
	string name;

	void deposit(int);
	void withdraw(int);
	int checkBalance();

	void setName(string);
	void setType(bool);
	void setBalance(int);

	string getName();
	bool getType();
	int getBalance();
};