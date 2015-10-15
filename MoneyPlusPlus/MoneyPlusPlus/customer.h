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
	int role;				//0 = customer, 1 = manager, 2 = maintainence

	vector<Account*> accounts;

	Customer();
	Customer(int, string);
	Customer(string, string, string, string);
	Customer(int, string, string, string, string, int);

	void addAccount(Account*);
	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setPass(string);
	void setID(int);
	void setRole(int);

	vector<Account*> getAccounts();
	void deleteAccount(Account*);
	string getFirstName();
	string getLastName();
	string getEmail();
	string getPass();
	int getID();
	int getRole();
};