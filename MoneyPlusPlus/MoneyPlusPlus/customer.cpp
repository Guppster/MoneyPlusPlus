#include "customer.h"

//Default Constructor
Customer::Customer()
{

}

//Auth Constructor
Customer::Customer(int id, string pass)
{
	iD = id;
	password = pass;
}

//Full Constructor without ID
Customer::Customer(string fname, string lname, string _email, string pass)
{
	firstName = fname;
	lastName = lname;
	email = _email;
	password = pass;
}

//Full Constructor
Customer::Customer(int id, string fname, string lname, string _email, string pass, int roleNum)
{
	iD = id;
    firstName = fname;
    lastName = lname;
    email = _email;
    password = pass;
	role = roleNum;
}

void Customer::addAccount(Account *account)
{
	accounts.push_back(account);
}

void Customer::deleteAccount(Account *account)
{
	int element = 0;
	for (int i = 0; i != accounts.size(); i++)
	{
		if (accounts[i]->getName().compare(account->getName()))
		{
			cout << "FOUND";
			element = i;
			break;
		}
	}
	accounts.erase(accounts.begin() + element);
}

//Sets the first name
void Customer::setFirstName(string name)
{
    firstName = name;
}

//Sets the last name
void Customer::setLastName(string name)
{
    lastName = name;
}

//Sets the email
void Customer::setEmail(string _email)
{
    email = _email;
}

//Sets the password
void Customer::setPass(string pass)
{
    password = pass;
}

void Customer::setID(int id)
{
	iD = id;
}


void Customer::setRole(int num)
{
	role = num;
}

int Customer::getRole()
{
	return role;
}


//retrieves the customer's email
string Customer::getEmail()
{
    return email;
}

//retrieves the customer's password
//currently in plaintext needs to be encrypyed
string Customer::getPass()
{
    return password;
}

int Customer::getID()
{
	return iD;
}

vector<Account*> Customer::getAccounts()
{
	return accounts;
}

//retrieves the customer's firstname
string Customer::getFirstName()
{
    return firstName;
}

//retrieves the customer's lastname
string Customer::getLastName()
{
    return lastName;
}
