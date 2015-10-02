#pragma once
#include <string>
#include "customer.h"

using namespace std;

class Server
{
public:
	//Number of customers in system. (testing limit set to 100)
	Customer customer[100];

	//Public functionality
	bool auth(Customer*);
	bool signup(Customer*);

private:
	//Private Functionality
	void loadCustomers();
	void storeCustomers();
	bool customerExists(int);
	Customer* findCustomer(int);
};