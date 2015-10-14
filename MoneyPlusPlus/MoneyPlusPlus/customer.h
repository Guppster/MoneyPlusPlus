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
	Customer(int, string, string, string, string);

	void addAccount(Account*);
	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setPass(string);
	void setID(int);

	vector<Account*> getAccounts();
	string getFirstName();
	string getLastName();
	string getEmail();
	string getPass();
	int getID();
	
};