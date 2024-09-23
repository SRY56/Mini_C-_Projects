/**
	Write a program that reads in an array of integers
	from the user and reverses it using a function that
	takes an integer array pointer and its size as arguments.
	The program should print the original and reversed arrays to the console.
**/

#include <iostream>
using namespace std;

// Follow the Instructions to solve the lab and execute the code

void reverseArray(int *arr, int size) {
	int *start = arr;
	int *end = arr + size - 1;
	while (start < end) {
		int middle = *start;
		*start = *end;
		*end = middle;
		end--;
		start++;
	}
}

int main()
{
	int size;
	cout << "Enter the Size of the array: ";
	cin >> size;
	cout << endl;

	int *arr = new int[size];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; ++i){
		cin >> arr[i];
	}
	
	cout << "Original Array: ";
	for (int i = 0; i < size; ++i) {
		cout << *(arr + i) << " ";
	}
	cout << endl;

	reverseArray(arr, size);

	cout << "Reversed Array: ";
	for (int i = 0; i < size; ++i){
		cout << *(arr + i) << " ";
	}
	cout << endl;

	delete[] arr;

	return 0;
}
