#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "customer.h"

using namespace std;

class Server
{
public:
	//Number of customers in system. (testing limit set to 100)
	vector<Customer*> customers;
	Customer* found;

	//Public functionality
	bool auth(Customer*);
	int signup(Customer*);
	void deserialize();
	void serialize();
	Customer* findCustomer(int);

private:
	//Private Functionality
	int generateID(Customer*);
	bool idExists(int);
	bool emailExists(string);
	vector<string> split(const string &s, char delim);
	vector<string> splitHelper(const string &s, char delim, vector<string> &elems);

};


