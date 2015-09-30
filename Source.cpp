
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char selection;
	
	cout << "(L)ogin or (R)egister: \t";
	cin >> selection;

	if(selection=='L' || selection=='l')
	{
		login()
	}
	else if(selection=="R" || selection == "r")
	{
		registerNew();
	}
}//End of main method

void login()
{
	int id; 
	string pass;

	cout << "Enter your account ID: \t";
	cin >> id;

	cout << "Enter your password: \t";
	cin >> pass;
}

void registerNew()
{

}