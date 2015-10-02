#include <iostream>
#include <istream>
#include <string>
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

	Account account[69];

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
};