/**
    In this assignment, you will write a C++ program
    that uses switch statements to perform conditional 
    logic based on a user input.
**/


#include <iostream>
using namespace std;

// Follow the Instructions to solve the lab and execute the code
int main()
{
	int choice;
	cout << "Enter a number between 1 and 5: ";
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "You Chose Option 1" << endl;
			break;
		case 2:
			cout << "You Chose Option 2" << endl;
			break;
		case 3:
			cout << "You Chose Option 3" << endl;
			break;
		case 4: 
			cout << "You Chose option 4" << endl;
			break;
		case 5:
			cout << "You Chose Option 5" << endl;
		default:
			cout << "Invalid Response!" << endl;
	}

	return 0;
}
