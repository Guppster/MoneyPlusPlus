#include "Source.h"

void applyForAccount(Customer *customer)
{
	int selection = 0;
	string name;
	Account *account = new Account();

	//Clear the screen for a cleaner interface
	system("clear");

	//Ask the user what type of account they want to make
	cout << "1. " << "Apply for a Checking account\n";
	cout << "2. " << "Apply for a Saving account\n";

	cout << "\nOption #: ";
	cin >> selection;
	server.logData(customer, selection);

	if (selection == 1)
	{
		account->setType(0);
	}
	else
	{
		account->setType(1);
	}

	//Clear the screen for a cleaner interface
	system("clear");

	cout << "Enter name of Account\n";
	cin >> name;
	server.logData(customer, name);
	account->setName(name);
	account->setApproved(0);
	account->setBalance(0);

	//Add the account to the customer
	customer->addAccount(account);
	server.serialize();

	//Notify the user that the account creation process has started and once the manager reviews his account it will be visable.
	cout << "The account is pending and will be added to your interface when it is accepted.\n";
	cout << "\nPress Enter To Continue...";
	cin.get();
	cin.get(); 
	mainMenu(customer);

}//End of applyForAccount method

void applyForAccountforManager(Customer *customer, Customer *managerCustomer)
{
	int selection = 0;
	string name;
	Account *account = new Account();

	//Clear the screen for a cleaner interface
	system("clear");

	//Ask the user what type of account they want to make
	cout << "1. " << "Apply for a Checking account\n";
	cout << "2. " << "Apply for a Saving account\n";

	cout << "\nOption #: ";
	cin >> selection;
	server.logData(customer, selection);

	if (selection == 1)
	{
		account->setType(0);
	}
	else
	{
		account->setType(1);
	}

	//Clear the screen for a cleaner interface
	system("clear");

	cout << "Enter name of Account\n";
	cin >> name;
	server.logData(customer, name);
	account->setName(name);
	account->setApproved(1);
	account->setBalance(0);

	//Add the account to the customer
	customer->addAccount(account);
	server.serialize();

	cout << "\nPress Enter To Continue...";
	cin.get();
	cin.get();
	mainMenu(managerCustomer);

}//End of applyForAccount method

void openAccount(Customer *customer, Account *account)
{
	int selection = 0;
	int tempNum;

	system("clear");
	cout << account->getName() << " : " << account->getTypeinString() << "\n";
	cout << "Balance: " << account->getBalance() << "\n\n";

	cout << "1. " << "Deposit Money\n";
	cout << "2. " << "Withdraw Money\n";
	cout << "3. " << "Go Back\n";
	cout << "\nOption #: ";

	cin >> selection;
	server.logData(customer, selection);

	if(selection == 1)
	{
		system("clear");
		cout << "How much would you like to deposit: ";
		cin >> tempNum;
		account->deposit(tempNum);
		server.logData(customer, tempNum);
		server.serialize();
		openAccount(customer, account);
	}
	else if(selection == 2)
	{
		system("clear");
		cout << "How much would you like to withdraw: ";
		cin >> tempNum;
		server.logData(customer, tempNum);
		account->withdraw(tempNum);
		server.serialize();
		openAccount(customer, account);
	}
	else
	{
		mainMenu(customer);
	}
}//End of openAccount method

void mainMenu(Customer *customer)
{
	vector<Account*> accounts = customer->getAccounts();
	string tempApproved;
	int tempNum;
	int counter = 0;
	int selection = 0;
	int i = 0;

	system("clear");
	cout << "Welcome " << customer->getFirstName() << ".\n\n";

	if (customer->getRole() == 0)
	{
		//If the customer has no accounts 
		if (accounts.empty())
		{
			cout << "1. " << "Apply for an Account\n";
			cout << "2. " << "Exit the Program\n";
			cout << "\nOption #: ";

			cin >> selection;
			server.logData(customer, selection);

			if (selection = 1) applyForAccount(customer);
			else if (selection = 2) server.serialize();
		}
		else//If the customer has accounts 
		{
			cout << "[Your Accounts]\n";

			//List all accounts
			for (i = 0; i != accounts.size(); i++)
			{
				tempApproved = (accounts[i]->getApproved() == 0) ? " - [UNAPPROVED]" : "";
				tempNum = i + 1;
				cout << tempNum << ". " << accounts[i]->getName() << " - " << accounts[i]->getTypeinString() << " account" << tempApproved << "\n";
				counter = i + 1;
			}

			//Organizing output with a blank line
			cout << "\n[Other Actions]\n";
			i++;

			cout << i++ << ". " << "Apply for an Account\n";
			cout << i++ << ". " << "Transfer money between accounts\n";
			cout << i++ << ". " << "Cancel an Account\n";
			cout << i++ << ". " << "Change your password\n";
			cout << i++ << ". " << "Logout\n";
			cout << i++ << ". " << "Exit the Program\n";

			cout << "\nOption #: ";

			cin >> selection;

			server.logData(customer, selection);

			for (int j = 0; j != accounts.size(); j++)
			{
				if (selection == (counter - j))
				{
					if (accounts[counter - j-1]->getApproved() == 1)
					{
						openAccount(customer, accounts[counter - j - 1]);
					}
					else
					{
						cout << "\nThis Account is UNAPPROVED. Please wait for a manager to approve your account.\n";
						cout << "Press Enter to Continue...";
						cin.get();
						cin.get();
						mainMenu(customer);
					}
				}
			}

			if (selection == (counter + 1))
			{
				applyForAccount(customer);
			}
			else if (selection == (counter + 2))
			{
				transferBetweenAccounts(customer);
			}
			else if (selection == (counter + 3))
			{
				cancelOwnAccount(customer);
			}
			else if (selection == (counter + 4))
			{
				changeYourPassword(customer);
			}
			else if (selection == (counter + 5))
			{
				server.serialize();
				system("clear");
				main();
			}
			else if (selection == (counter + 6))
			{
				server.serialize();
			}
		}
	}
	else if (customer->getRole() == 1)
	{
		cout << "You are a Manager\n";

		cout << "1. " << "View accounts awaiting approval\n";
		cout << "2. " << "Create new Account for existing customer\n";
		cout << "3. " << "Create new Customer\n";
		cout << "4. " << "Delete Account\n";
		cout << "5. " << "View Accounts for A Customer\n";
		cout << "6. " << "View All Accounts\n";
		cout << "7. " << "Change your password\n";
		cout << "8. " << "Logout\n";
		cout << "9. " << "Exit Program\n";

		cout << "\nOption #: ";

		cin >> selection;

		server.logData(customer, selection);

		if (selection == 1)
		{
			viewAwaitingApproval(customer);
		}
		else if (selection == 2)
		{
			system("clear");
			cout << "Enter the ID of the user you wish to edit: ";
			cin >> selection;

			Customer *delCustomer = server.findCustomer(selection);
			if (delCustomer != NULL)
			{
				applyForAccountforManager(delCustomer, customer);
			}
			else
			{
				cout << "\nUser not found!\n";
				cout << "Press Enter to Continue...";
				cin.get();
				cin.get();
			}

			mainMenu(customer);
		}
		else if (selection == 3)
		{
			system("clear");
			applyForAccountforManager(registerNewFromManager(), customer);
		}
		else if (selection == 4)
		{
			managerDeleteAccount(customer);
		}
		else if (selection == 5)
		{
			viewCustomerAccount(customer);
		}
		else if (selection == 6)
		{
			viewAllAccounts(customer);
		}
		else if (selection == 7)
		{
			system("clear");
			changeYourPassword(customer);
		}
		else if (selection == 8)
		{
			system("clear");
			server.serialize();
			main();
		}
		else if (selection == 9)
		{
			server.serialize();
		}
	}
	else if (customer->getRole() == 2)
	{
		cout << "You are a Maintenance person\n";

		cout << "1. " << "Toggle execution trace\n";
		cout << "2. " << "Logout\n";
		cout << "3. " << "Exit Program\n";

		cout << "\nOption #: ";

		cin >> selection;

		server.logData(customer, selection);

		if (selection == 1)
		{
			if (server.getTrace())
			{
				server.setTrace(false);
				cout << "\nTrace Disabled. Hit Enter\n";
				cin.get();
				cin.get();
			}
			else
			{
				server.setTrace(true);
				cout << "\nTrace Enabled. Hit Enter\n";
				cin.get();
				cin.get();
			}
			mainMenu(customer);
		}
		else if (selection == 2)
		{
			system("clear");
			server.serialize();
			main();
		}
		else if (selection == 3)
		{
			server.serialize();
		}
	}
}//End of main menu method

void viewCustomerAccount(Customer *customer)
{
	int id;
	int tempNum;
	int selection;
	string tempApproved;
	int counter;

	system("clear");
	cout << "Enter the ID of the user you wish to view: ";
	cin >> id;
	server.logData(customer, id);

	Customer *delCustomer = server.findCustomer(id);
	if (delCustomer != NULL)
	{
		vector<Account*> accs = delCustomer->getAccounts();

		if (accs.size() != 0)
		{
			for (int i = 0; i < accs.size(); i++)
			{
				tempApproved = (accs[i]->getApproved() == 0) ? " - [UNAPPROVED]" : "";
				tempNum = i + 1;
				cout << tempNum << ". " << accs[i]->getName() << " - " << accs[i]->getTypeinString() << " account" << tempApproved << " - Balance: $" << accs[i]->getBalance() << endl;
				counter = i + 1;
			}

			cout << "Press Enter to Continue...";
			cin.get();
			cin.get();
		}
		else
		{
			cout << "\nNo accounts found for this user.\n";
			cout << "Press Enter to Continue...";
			cin.get();
			cin.get();
		}
	}
	else
	{
		cout << "\nUser not found!\n";
		cout << "Press Enter to Continue...";
		cin.get();
		cin.get();
	}

	mainMenu(customer);
}

void viewAllAccounts(Customer *customer)
{
	int id;
	int tempNum;
	int selection;
	string tempApproved;
	int counter;

	system("clear");

	vector<Customer*> customers = server.customers;

	for (int j = 0; j != customers.size(); j++)
	{
		vector<Account*> accs = customers[j]->getAccounts();

		if (accs.size() != 0)
		{
			for (int i = 0; i < accs.size(); i++)
			{
				tempApproved = (accs[i]->getApproved() == 0) ? " - [UNAPPROVED]" : "";
				tempNum = i + 1;
				cout << tempNum << ". " << accs[i]->getName() << " - " << accs[i]->getTypeinString() << " account" << tempApproved << " - Balance: $" << accs[i]->getBalance() << endl;
				counter = i + 1;
			}

			cout << endl;
		}
	}

	cout << "\nPress Enter to Continue...";
	cin.get();
	cin.get();
	
	mainMenu(customer);
}

void cancelOwnAccount(Customer *customer)
{
	int selection;
	int tempNum;
	int i;
	vector<Account*> accounts = customer->getAccounts();

	system("clear");

	//List all accounts
	for (i = 0; i != accounts.size(); i++)
	{
		tempNum = i + 1;
		cout << tempNum << ". " << accounts[i]->getName() << " - " << accounts[i]->getTypeinString() << " account" << endl;
	}

	cout << "Which account # would you like to Delete:\t" << endl;
	cin >> selection;
	server.logData(customer, selection);

	for (int j = 0; j != accounts.size(); j++)
	{
		if (selection == (j + 1))
		{
			if (accounts[j]->getBalance() == 0)
			{
				customer->deleteAccount(accounts[j]);
			}
			else
			{
				cout << "\nUnable to delete account. Please withdraw all funds first" << endl;
				cout << "Press Enter to Continue...";
				cin.get();
				cin.get();
			}

		}
	}
	server.serialize();
	mainMenu(customer);
}

void transferBetweenAccounts(Customer *customer)
{
	system("clear");
	vector<Account*> accounts = customer->getAccounts();

	int selection;
	int tempNum;
	int i;

	int from;
	int to;
	int howmuch;

	//List all accounts
	for (i = 0; i != accounts.size(); i++)
	{
		if (accounts[i]->getApproved() == 1)
		{
			tempNum = i + 1;
			cout << tempNum << ". " << accounts[i]->getName() << " - " << accounts[i]->getTypeinString() << " account" << endl;
		}
	}

	cout << "Which account # would you like to send money from:\t" << endl;

	cin >> selection;

	server.logData(customer, selection);

	for (int j = 0; j != accounts.size(); j++)
	{
		if (selection == (tempNum - j))
		{
			from = tempNum - j - 1;
		}
	}

	cout << "Which account # would you like to send money to:\t" << endl;

	cin >> selection;

	server.logData(customer, selection);

	for (int j = 0; j != accounts.size(); j++)
	{
		if (selection == (tempNum - j))
		{
			to = tempNum - j - 1;
		}
	}

	cout << "How much would you like to transfer?:\t" << endl;
	cin >> howmuch;
	server.logData(customer, howmuch);

	accounts[from]->withdraw(howmuch);
	accounts[to]->deposit(howmuch);

	server.serialize();
	mainMenu(customer);
}

/* Allows a user to change their password*/
void changeYourPassword(Customer *customer)
{
	string tempPass;

	do
	{
		cout << "Enter your current password: ";
		cin >> tempPass;
		server.logData(customer, tempPass);
	} while (tempPass.compare(customer->getPass()));

	cout << "Enter your new password: ";
	cin >> tempPass;
	server.logData(customer, tempPass);

	customer->setPass(tempPass);
	server.serialize();

	cout << "Your Password has been Changed.\n";
	cout << "Press Enter to Continue...";
	cin.get();
	cin.get();

	mainMenu(customer);
}

void viewAwaitingApproval(Customer *customer)
{
	string tempApproved;
	int tempNum = 0;
	string selection;

	system("clear");

	for (int j = 0; j != server.customers.size(); j++)
	{
		Customer *tempCustomer = server.customers[j];
		vector<Account*> accs = tempCustomer->getAccounts();

		for (int i = 0; i != accs.size(); i++)
		{
			if (accs[i]->getApproved() == 0)
			{
				system("clear");
				tempNum = tempNum + 1;
				cout << tempNum << ". " << tempCustomer->firstName << " - " << accs[i]->getName() << " - " << accs[i]->getTypeinString() << " account" << "\n";

				cout << "\n Would you like to approve this account? Y/N (Enter any other input to go back): ";
				cin >> selection;
				server.logData(customer, selection);

				if (selection.compare("Y") || selection.compare("y"))
				{
					accs[i]->setApproved(1);
				}
				else if (selection.compare("N") || selection.compare("n"))
				{
					accs[i]->setApproved(0);
				}
			}
		}
	}
	mainMenu(customer);
}

void managerDeleteAccount(Customer *customer)
{
	int id;
	int tempNum;
	int selection;
	string tempApproved;
	int counter;

	system("clear");
	cout << "Enter the ID of the user you wish to delete an account from: ";
	cin >> id;
	server.logData(customer, id);

	Customer *delCustomer = server.findCustomer(id);

	vector<Account*> accs = delCustomer->getAccounts();
	
	if (accs.size() != 0)
	{
		for (int i = 0; i < accs.size(); i++)
		{
			tempApproved = (accs[i]->getApproved() == 0) ? " - [UNAPPROVED]" : "";
			tempNum = i + 1;
			cout << tempNum << ". " << accs[i]->getName() << " - " << accs[i]->getTypeinString() << " account" << tempApproved << "\n";
			counter = i + 1;
		}

		cout << "Enter which account # you wish to delete (Funds will be lost): ";
		cin >> selection;
		server.logData(customer, selection);

		delCustomer->deleteAccount(accs[counter - 1]);
		server.serialize();
	}
	else
	{
		cout << "\nNo accounts found for this user.\n";
		cout << "Press Enter to Continue...";
		cin.get();
		cin.get();
	}
	
	mainMenu(customer);
}

/* This method controls the login prompt flow */
void login()
{
	int id; 
	string pass;

	Customer *tempCustomer = new Customer();
	do
	{
		cout << "Enter your account ID: \t";
		cin >> id;
		server.logData(tempCustomer, id);

		cout << "Enter your password: \t";
		cin >> pass;
		server.logData(tempCustomer, pass);

		tempCustomer->setID(id);
		tempCustomer->setPass(pass);

		if (!server.auth(tempCustomer))
		{
			cout << "\nError: Invalid Login Credentials\n" << endl;
		}
	} while (!server.auth(tempCustomer));

	mainMenu(server.findCustomer(id));
	
}//End of login method


/*This method controls the register prompt flow*/
void registerNew()
{
	string fname;
	string lname;
	string email;
	string pass;
	string passconfirm;
	Customer *tempCustomer = new Customer();

	cout << "Enter your first name: \t";
	cin >> fname;
	server.logData(tempCustomer, fname);

	cout << "Enter your last name: \t";
	cin >> lname;
	server.logData(tempCustomer, lname);

	cout << "Enter your email: \t";
	cin >> email;
	server.logData(tempCustomer, email);

	do
	{
		cout << "Enter your password: \t";
		cin >> pass;
		server.logData(tempCustomer, pass);

		cout << "Confirm your password: \t";
		cin >> passconfirm;
		server.logData(tempCustomer, passconfirm);

		if (pass != passconfirm)
		{
			cout << "Error: Passwords do not match, try again" << endl;
		}
	} while (pass != passconfirm);

	tempCustomer->setFirstName(fname);
	tempCustomer->setLastName(lname);
	tempCustomer->setEmail(email);
	tempCustomer->setPass(pass);
	
	cout << "Your ID is: \t" << server.signup(tempCustomer) << endl;
	cout << "\nPress Enter To Continue...";
	cin.get();
	cin.get(); 

	mainMenu(tempCustomer);

}//End of registerNew method\

Customer* registerNewFromManager()
{
	string fname;
	string lname;
	string email;
	string pass;
	string passconfirm;
	Customer *tempCustomer = new Customer();

	cout << "Enter your first name: \t";
	cin >> fname;
	server.logData(tempCustomer, fname);

	cout << "Enter your last name: \t";
	cin >> lname;
	server.logData(tempCustomer, lname);

	cout << "Enter your email: \t";
	cin >> email;
	server.logData(tempCustomer, email);

	do
	{
		cout << "Enter your password: \t";
		cin >> pass;
		server.logData(tempCustomer, pass);

		cout << "Confirm your password: \t";
		cin >> passconfirm;
		server.logData(tempCustomer, passconfirm);

		if (pass != passconfirm)
		{
			cout << "Error: Passwords do not match, try again" << endl;
		}
	} while (pass != passconfirm);

	tempCustomer->setFirstName(fname);
	tempCustomer->setLastName(lname);
	tempCustomer->setEmail(email);
	tempCustomer->setPass(pass);

	cout << "Your ID is: \t" << server.signup(tempCustomer) << endl;
	cout << "\nPress Enter To Continue...";
	cin.get();
	cin.get();

	return tempCustomer;
}

/*The main program flow*/
int main()
{
	char selection;
	server.deserialize();
	
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


