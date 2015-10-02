#include "account.h"

int Account::checkBalance()
{
	return balance; 
}

void Account::deposit(int amount)
{
	balance += amount;
}

void Account::withdraw(int amount)
{
	balance -= amount;
}

void Account::setName(string _name)
{
	name = _name;
}

string Account::getName()
{
	return name;
}
