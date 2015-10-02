#include <iostream>
#include <istream>
#include <string>

using namespace std;

class Account
{
public:
	bool type;
	int balance;

	void deposit(int);
	void withdraw(int);
	void setName(string);
	string getName();
	int checkBalance();
};