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

	Account account[69];

	void deposit(int);
	void withdraw(int);
	int checkBalance();
};