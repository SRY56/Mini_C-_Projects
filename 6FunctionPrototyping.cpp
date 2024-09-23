/**
    In this assignment, you will write a C++ program
    that uses function prototyping to define and call functions.
 **/

#include <iostream>

using namespace std;

// Function prototypes
int cube(int n);
int add(int a, int b);
int subtract(int a, int b);

int main() {
    int x, y;

    // Part 1: Cube function
    cout << "Enter an integer value for x: ";
    cin >> x;
    cout << "The cube of " << x << " is " << cube(x) << endl;

    // Part 2: Add and Subtract functions
    cout << "Enter two integer values for x and y (ex. ""2 5""): ";
    cin >> x >> y;
    cout << "The sum of " << x << " and " << y << " is " << add(x, y) << endl;
    cout << "The difference between " << x << " and " << y << " is " << subtract(x, y) << endl;

    return 0;
}

// Function definitions
int cube(int n) {
    return n * n * n;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}
