#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include "customer.h"
#include "server.h"

using namespace std;

Server server;

void applyForAccount(Customer *customer);
void mainMenu(Customer *customer);
void registerNew();
void login();
int main();