#include <iostream>
#include <string>
#include "customer.h"
#include "server.h"

using namespace std;

Server server;

/* This method controls the login prompt flow */
void login()
{
	int id; 
	string pass;

	Customer tempCustomer;
	do
	{
		cout << "Enter your account ID: \t";
		cin >> id;

		cout << "Enter your password: \t";
		cin >> pass;

		Customer tempCustomer (id, pass);

		if (!server.auth(&tempCustomer))
		{
			cout << "Error: Invalid Login Credentials" << endl;
		}
	} while (!server.auth(&tempCustomer));
	
}//End of login method

/*This method controls the register prompt flow*/
void registerNew()
{
	string fname;
	string lname;
	string email;
	string pass;
	string passconfirm;

	cout << "Enter your first name: \t";
	cin >> fname;

	cout << "Enter your last name: \t";
	cin >> lname;

	cout << "Enter your email: \t";
	cin >> email;

	do
	{
		cout << "Enter your password: \t";
		cin >> pass;

		cout << "Confirm your password: \t";
		cin >> passconfirm;

		if (pass != passconfirm)
		{
			cout << "Error: Passwords do not match, try again" << endl;
		}
	} while (pass != passconfirm);

	 Customer tempCustomer (fname, lname, email, pass);
	
	cout << "Your ID is: \t" << server.signup(&tempCustomer) << endl;
	cin >> fname;

}//End of registerNew method

/*The main program flow*/
int main()
{
	char selection;
	
	cout << "(L)ogin or (R)egister: \t";
	cin >> selection;

	if(selection=='L' || selection=='l')
	{
		login();
	}
	else if(selection=='R' || selection == 'r')
	{
		registerNew();
	}
}//End of main method

