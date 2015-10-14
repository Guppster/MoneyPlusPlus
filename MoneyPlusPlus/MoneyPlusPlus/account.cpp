#include "account.h"

//Default Constructor
Account::Account()
{

}

//Full Constructor
Account::Account(int type, string _name, int amount, int status)
{
	isSaving = type;
	name = _name;
	balance = amount;
	approved = status;
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

void Account::setApproved(int status)
{
	approved = status;
}

int Account::getApproved()
{
	return approved;
}

string Account::getName()
{
	return name;
}

int Account::getType()
{
	return isSaving;
}

string Account::getTypeinString()
{
	if(isSaving == 1)
	{
		return "Saving";
	}
	
	return "Checking";
}

int Account::getBalance()
{
	return balance;
}
