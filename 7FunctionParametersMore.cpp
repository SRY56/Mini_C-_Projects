/**
    In this assignment, you will write a C++ program
    that uses functions with parameters, arguments and
    return values, and scope.
 **/

#include <iostream>
#include <cmath>
using namespace std;

void add(int a, int b) {
	int sum = a + b;
	cout << "Value of Sum: " << sum << endl;
}

void power(double base, double exponent) {
	double result = pow(base, exponent);
	cout << "value of double: " << result << endl;
}

int x;

void print_x() {
	cout << "Value of x: " << x << endl;
}

// Follow the Instructions to solve the lab and execute the code
int main()
{
	add(2, 7);
	power(2.0, 3.0);

	x = 56;
	print_x();

	return 0;
}
