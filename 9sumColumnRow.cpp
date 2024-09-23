/**
    Write a program that dynamically creates a two-dimensional
    integer array using pointers to pointers and fill it with user
    input. The program should then find the sum of each row and
    column and store them in a class object. Finally, the program
    should print the original array and the row and column sums
    to the console.
**/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

// Function prototypes
int add(int, int, int);
void printArray(int*, int);
void printReverseArray(int*, int);
void printReverse2DArray(int**, int, int);
int* returnIntPointer();

// Function definitions
int add(int a, int b, int c) {
    return a + b + c;
}

void printArray(int* p, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;
}

void printReverseArray(int* p, int size) {
    for (int i = (size - 1); i >= 0; i--) {
        cout << *(p + i) << " ";
    }
    cout << endl;
}

void printReverse2DArray(int** p, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        cout << "The elements of row " << (i + 1) << " in reverse order: ";
        for (int j = (cols - 1); j >= 0; j--) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

int* returnIntPointer() {
    int* p = new int;
    *p = 1000;
    return p;
}

int main() {
    int rowSum = 0, colSum = 0;
    int row, col;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;

    int** matrix = new int*[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        cout << "Enter " << col << " elements in row " << (i + 1) << ": ";
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << endl << "Original matrix:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Row sums:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            rowSum += matrix[i][j];
        }
        cout << rowSum << " ";
        rowSum = 0;
    }
    cout << endl;

    cout << "Column sums:" << endl;
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            colSum += matrix[i][j];
        }
        cout << colSum << " ";
        colSum = 0;
    }
    cout << endl;

    // Free allocated memory
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
