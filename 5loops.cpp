/**
    In this assignment, you will write a C++ program
    that uses loops to perform simple repetitive tasks.
**/

#include <iostream>
using namespace std;

// Follow the Instructions to solve the lab and execute the code
int main()
{
	int n = 56;

	for (int i; i <= n; ++i){
		cout << i << endl;
	}

	cout << "" << endl;

	int sum = 0;
	int i = 0;
	while (i <= 10) {
		sum += i;
		i++;
	}
	cout << sum << endl;

	cout << "" << endl;

	int x = 25;
	int userInt = 0;
	do {
		cout << "Enter a Number greater than or equal to x: ";
		cin >> userInt;
	} while (userInt < x);
	cout << "Your value is: " << userInt << endl;


	return 0;
}
