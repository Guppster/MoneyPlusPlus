#include <iostream>
#include <string>
#include <stdlib.h>
#include "customer.h"
#include "server.h"

using namespace std;

Server server;

void applyForAccount(Customer customer)
{
	int selection = 0;
	string name;
	Account *account = new Account();

	//Clear the screen for a cleaner interface
	system("cls");

	//Ask the user what type of account they want to make
	cout << "1. " << "Apply for a Checking account\n";
	cout << "2. " << "Apply for a Saving account\n";

	cin >> selection;

	if (selection == 1)
	{
		account->setType(0);
	}
	else
	{
		account->setType(1);
	}

	//Clear the screen for a cleaner interface
	system("cls");

	cout << "Enter name of Account\n";
	cin >> name;
	account->setName(name);

	//Add the account to the customer
	customer.addAccount(account);

	//Notify the user that the account creation process has started and once the manager reviews his account it will be visable.
	cout << "The account is pending and will be added to your interface when it is accepted.\n";
	cout << "\nPress Enter To Continue...";
	cin >> name;

}//End of applyForAccount method


void mainMenu(Customer customer)
{
	vector<Account*> accounts = customer.getAccounts();
	string tempType;
	int counter = 0;
	int selection = 0;
	int i = 0;

	system("cls");
	cout << "Welcome " << customer.getFirstName() << ".\n";

	//If the customer has no accounts 
	if (accounts.empty())
	{
		cout << "1. " << "Apply for an Account\n";
		cout << "2. " << "Exit the Program\n";

		cin >> selection;

		if (selection = 1) applyForAccount(customer);


	}
	else//If the customer has accounts 
	{
		//List all accounts
		for (i = 0; i != accounts.size(); i++)
		{
			tempType = (accounts[i]->getType() == 1) ? "Saving" : "Checking";

			cout << i << ". " << accounts[i]->getName() << " - " << tempType << " account\n";
			counter = i;
		}

		cout << i++ << ". " << "Apply for an Account\n";
		cout << i++ << ". " << "Transfer money between accounts\n";
		cout << i++ << ". " << "Tranfer money to another user\n";
		cout << i++ << ". " << "Cancel an Account\n";
		cout << i++ << ". " << "Change your password\n";

		cin >> selection;

		if (selection == (counter + 1))
		{
			applyForAccount(customer);
		}
		else if (selection == (counter + 2))
		{

		}
		else if (selection == (counter + 3))
		{

		}
		else if (selection == (counter + 4))
		{

		}
		else if (selection == (counter + 5))
		{

		}

	}
}

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

	mainMenu(tempCustomer);
	
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
	cout << "\nPress Enter To Continue...";
	cin >> fname;

	mainMenu(tempCustomer);

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
	cin >> selection;
}//End of main method


