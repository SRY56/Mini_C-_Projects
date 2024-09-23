/** 
    In this assignment, you will learn about variables
    in C++ and how they are used to store and manipulate data.
 **/

#include <iostream>
using namespace std;

// Follow the Instructions to solve the lab and execute the code
int main()
{
	int myInt = 56;
	double myDouble = 11.3;
	myDouble = (int) myDouble;
	int sum = myInt + myDouble;
	cout << sum << endl;

	cout << "" << endl;
	int userInt;
	cout << "Enter an Integer Value: ";
	cin >> userInt;
	int product = userInt + myInt;
	cout << product << endl;

	cout << "" << endl;
	{
		std::string myString = "Hello World!";
		cout << myString << endl;
	}
	return 0;
}
