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

	void setFirstName(string fname);
	void setLastName(string lname);
	void setID(int num);

	string getFirstName();
	string getLastName();
	int getID();
};