#include "server.h"

//Checks if the id and password are valid for authentication 
bool Server::auth(Customer* customer)
{
	if (customerExists(customer->getID()))
	{
		found = findCustomer(customer->getID());

		if (customer->getPass() == found->getPass())
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
	//Check if valid + duplication
	customers.push_back(customer);
	return true;
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

	return nullptr;
}

//Traverse the array and confirm the id is contained within the array
bool Server::customerExists(int id)
{
	for (std::vector<Customer>::size_type i = 0; i != customers.size(); i++)
	{
		if (customers[i]->getID() == id)
		{
			return true;
		}
	}

	return false;
}

//read file and store all records as customers
void Server::deserialize()
{

}

//write one record for each customer
void Server::serialize()
{

}