#include "customer.h"

//Auth Constructor
Customer::Customer(int id, string pass)
{
	iD = id;
	password = pass;
}

//Full Constructor
Customer::Customer(string fname, string lname, string _email, string pass)
{
    firstName = fname;
    lastName = lname;
    email = _email;
    password = pass;
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
