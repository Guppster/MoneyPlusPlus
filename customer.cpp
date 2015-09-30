#include "customer.h"

void Customer::setFirstName(string name)
{
    firstname = name;
}

void Customer::setLastName(string name)
{
    lastname = name;
}

string Customer::getFirstName()
{
    return firstname;
}

string Customer::getLastName()
{
    return lastname;
}