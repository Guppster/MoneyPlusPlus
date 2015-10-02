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

	cout << "Enter your account ID: \t";
	cin >> id;

	cout << "Enter your password: \t";
	cin >> pass;

	Customer tempCustomer = Customer(id, pass);

	server.auth(tempCustomer*);
}//End of login method

/*This method controls the register prompt flow*/
void registerNew()
{

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

