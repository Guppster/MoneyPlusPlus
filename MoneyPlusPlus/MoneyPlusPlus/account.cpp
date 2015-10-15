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
	string input;
	if ((balance - amount) < 0)
	{
		cout << "\n WARNING: This operation is now allowed because it would make your account have a negative balance";
		cout << "\nPress Enter to Continue...";
		cin.get();
		cin.get();
		return;
	}

		if ((balance - amount) < 1000)
		{
			cout << "\n WARNING: Your balance will drop below $1000 and we will charge $2.00 on every withdraw if this happens";
			cout << "\n Are you sure you wish to continue? (Y/N)";

			cin >> input;

			if (input.compare("Y") || input.compare("y"))
			{
				balance -= amount;
				balance -= 2;
			}
			else if (input.compare("N") || input.compare("n"))
			{
				return;
			}
		}


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
