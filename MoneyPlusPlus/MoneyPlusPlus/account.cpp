#include "account.h"

//Default Constructor
Account::Account()
{

}

//Full Constructor
Account::Account(int type, string _name, int amount)
{
	isSaving = type;
	name = _name;
	balance = amount;
}


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

void Account::setType(int type)
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

int Account::getType()
{
	return isSaving;
}

int Account::getBalance()
{
	return balance;
}
