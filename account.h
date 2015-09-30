#include <iostream>
#include <istream>

using namespace std;

class Account
{
public:
	bool type;
	int balance;

	void deposit(int);
	void withdraw(int);
	int checkBalance();
}