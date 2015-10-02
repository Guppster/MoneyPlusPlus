#include <string>
#include "customer.h"

using namespace std;

class Server
{
public:

	//Number of customers in system. (testing limit set to 100)
	Customer customer[100];

	//Functionality
	bool auth(Customer*);
	bool signup(Customer*);
	void loadCustomers();
	void storeCustomers();
};