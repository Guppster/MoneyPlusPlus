#include "server.h"

//Checks if the id and password are valid for authentication 
bool Server::auth(Customer* customer)
{
	if (idExists(customer->getID()))
	{
		found = findCustomer(customer->getID());

		if (customer->getPass() == found->getPass())
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
}

bool Server::getTrace()
{
	return trace;
}

void Server::setTrace(bool trace_)
{
	trace = trace_;
}

void Server::logData(Customer* customer, int data)
{
	if (trace)
	{
		ofstream list("log.txt", ios::app);
		time_t currentTime;
		//Time function will only work on windows
		//currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
		// ctime(&currentTime)
		list << "ID: " << customer->getID() << ", Option Entered: " << data << endl;

		list.close();
	}
}

void Server::logData(Customer* customer, string data)
{
	if (trace)
	{
		ofstream list("log.txt", ios::app);
		time_t currentTime;
		//Time function will only work on windows
		//currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
		// ctime(&currentTime)
		list << "ID: " << customer->getID() << ", Option Entered: " << data << endl;

		list.close();
	}
}

//Returns ID if successfull, Returns -1 if unsuccessful
int Server::signup(Customer* customer)
{
	if (emailExists(customer->getEmail()))
	{
		return -1;
	}

	customer->setID(generateID(customer));
	customers.push_back(customer);

	return customer->getID();
}

//Traverse array and find return a pointer to the customer with that ID
Customer* Server::findCustomer(int id)
{
	for(std::vector<Customer>::size_type i = 0; i != customers.size(); i++) 
	{
		if (customers[i]->getID() == id)
		{
			return customers[i];
		}
	}

	return NULL;
}

//Traverse the array and confirm the id is contained within the array
bool Server::idExists(int id)
{
	for (vector<Customer>::size_type i = 0; i != customers.size(); i++)
	{
		if (customers[i]->getID() == id)
		{
			return true;
		}
	}

	return false;
}

//Traverse the array and confirm the email is contained within the array
bool Server::emailExists(string email)
{
	for (vector<Customer>::size_type i = 0; i != customers.size(); i++)
	{
		if (customers[i]->getEmail() == email)
		{
			return true;
		}
	}

	return false;
}

//read file and store all records as customers
void Server::deserialize()
{
	customers.clear();
	vector<string> tempCustomer;
	vector<string> tempAccounts;
	vector<string> tempAcc;
	Account *newAccount;
	Customer* newCustomer;
	string line;
	string fname;
	string lname;
	string email;
	string pass;

	ifstream list("Customers.txt");
	if (list.is_open())
	{
		while (getline(list, line))
		{
			//Put retrieved data in vector for easier access
			tempCustomer = split(line, ',');

			//Create new customer object with data read in
			newCustomer = new Customer(atoi(tempCustomer[0].c_str()), tempCustomer[1], tempCustomer[2], tempCustomer[3], tempCustomer[4], atoi(tempCustomer[5].c_str()));
			
			if (newCustomer->getRole() == 0)
			{
				//Read in the accounts line for this customer
				getline(list, line);

				//Put retrieved data in vector for easier access
				tempAccounts = split(line, '|');

				for (int i = 0; i != tempAccounts.size(); i++)
				{
					tempAcc = split(tempAccounts[i], ',');

					newAccount = new Account(atoi(tempAcc[0].c_str()), tempAcc[1], atoi(tempAcc[2].c_str()), atoi(tempAcc[3].c_str()));
					newCustomer->addAccount(newAccount);
				}
			}
			customers.push_back(newCustomer);
		}
		list.close();
	}
	else cout << "Unable to open file";
}

//write one record for each customer
void Server::serialize()
{
	vector<Account*> accs;

	ofstream list("Customers.txt");
	if (list.is_open())
	{
		for (vector<Customer>::size_type i = 0; i != customers.size(); i++)
		{
			accs = customers[i]->getAccounts();

			list << customers[i]->getID() << "," << customers[i]->getFirstName() << "," << customers[i]->getLastName() << "," << customers[i]->getEmail() << "," << customers[i]->getPass() << "," << customers[i]->getRole() << "\n";

			if (customers[i]->getRole() == 0)
			{
				for (vector<Account>::size_type z = 0; z != accs.size(); z++)
				{
					list << accs[z]->getType() << "," << accs[z]->getName() << "," << accs[z]->getBalance() << "," << accs[z]->getApproved() << "|";
				}

				list << "\n";
			}
		}
		list.close();
	}
	else cout << "Error: Unable to save";
}

vector<string> Server::splitHelper(const string &s, char delim, vector<string> &elems)
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) 
	{
		elems.push_back(item);
	}
	return elems;
}


vector<string> Server::split(const string &s, char delim) 
{
	vector<string> elems;
	splitHelper(s, delim, elems);
	return elems;
}

//Generates a UniqueID for the user
int Server::generateID(Customer* customer)
{
	int result;
	string total;
	string fname = customer->getFirstName();
	string lname = customer->getLastName();
	string email = customer->getEmail();

	for (int i = 0; i != fname.size() && i < 5; i++)
	{
		if ((int)fname.at(i) > 0)
		{
			total.append(to_string((int)fname.at(i)));
		}
			
	}

	for (int j = 0; j != lname.size() && j < 5; j++)
	{
		if ((int)lname.at(j) > 0)
		{
			total.append(to_string((int)lname.at(j)));
		}
			
	}

	for (int k = 0; k != email.size() && k < 5; k++)
	{
		if ((int)email.at(k) > 0)
		{
			total.append(to_string((int)email.at(k)));
		}
			
	}

	result = atoi(total.c_str()) % 1000000000;

	while (idExists(result))
	{
		result++;
	}

	return result;
}//End of generateID Method
