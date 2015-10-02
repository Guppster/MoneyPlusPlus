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

void Account::setType(bool type)
{
	isSaving = type;
}

void Account::setBalance(int num)
{
	balance = num;
}

string Account::getName()
{
	return name;
}

bool Account::getType()
{
	return isSaving;
}

int Account::getBalance()
{
	return balance;
}
