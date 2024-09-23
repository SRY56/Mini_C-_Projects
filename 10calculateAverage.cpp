/**
  Write a program that prompts the user to enter five integers,
  stores them in an array using pointers, and then finds the
  average of those integers. The program should then display
  the average to the user.
**/

#include <iostream>
using namespace std;

void input(int *arr);
double average(int *arr);

void input(int *arr) {
  cout << "Enter 5 Integers: ";
  for (int i = 0; i < 5; ++i) {
    cin >> arr[i];
  }
  cout << endl;
}


double average(int *arr){
  int add = 0;
  for (int i = 0; i < 5; ++i) {
    add += *(arr + i);
  }
  return (double)add/5.0;
}


int main(){
  //Enter 5 integers 
  int five = 5;
  int arr[five];
  int *ptr = arr;
  input(ptr);

  cout << "Original Array: ";
  for (int j = 0; j < five; ++j){
    cout << *(arr + j) << " ";
  } cout << endl;

  double avg = average(ptr);

  cout << "Average of the Five Integers: " << avg << endl;
  return 0;
}