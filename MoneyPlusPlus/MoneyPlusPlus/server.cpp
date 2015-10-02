#include "server.h"

//Checks if the id and password are valid for authentication 
bool Server::auth(Customer* customer)
{
	if (customerExists(customer->getID))
	{
		if (customer->getPass() == findCustomer(customer->getID)->getPass())
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool Server::signup(Customer* customer)
{
	return true;
}

//Traverse array and find return a pointer to the customer with that ID
Customer* Server::findCustomer(int id)
{

}

//Traverse the array and confirm the id is contained within the array
bool Server::customerExists(int id)
{

}

//read file and store all records as customers
void Server::loadCustomers()
{

}

//write one record for each customer
void Server::storeCustomers()
{

}