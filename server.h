#include <string>
#include "customer.h"

using namespace std;

class Server
{
public:

	Customer customer[69];
	bool auth(Customer*);
	bool signup();
};