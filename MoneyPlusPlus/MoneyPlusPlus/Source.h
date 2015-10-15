#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include "customer.h"
#include "server.h"

using namespace std;

Server server;

void mainMenu(Customer *customer);
void applyForAccount(Customer *customer);
void applyForAccountforManager(Customer *customer, Customer *managerCustomer);
Customer* registerNewFromManager();
void managerDeleteAccount(Customer *);
void viewAwaitingApproval(Customer *);
void changeYourPassword(Customer*);
void registerNew();
void login();
int main();