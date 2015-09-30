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