#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include "account.h"

using namespace std;

class Customer
{
public:
	string firstName;
	string lastName;
	string email;
	string password;
	int iD;

	vector<Account*> accounts;

	Customer();
	Customer(int, string);
	Customer(string, string, string, string);

	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setPass(string);
	void setID(int);

	string getFirstName();
	string getLastName();
	string getEmail();
	string getPass();
	int getID();
	vector<Account*> getAccounts();
};