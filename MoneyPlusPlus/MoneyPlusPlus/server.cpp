#include "server.h"

bool Server::auth(Customer* customer)
{
	customer -> setFirstName("poop");
	return false;
}

bool Server::signup(Customer* customer)
{
	return true;
}

//read file and store all records as customers
void Server::loadCustomers()
{

}

//write one record for each customer
void Server::storeCustomers()
{

}