/**
    In this assignment, you will practice logical operators
    in C++ and how they are used to combine and evaluate
    logical expressions.
 **/
#include <iostream>
using namespace std;

// Logical Operators Lab
int main(){
  bool a = true;
  bool b = false;
  bool result = a && b;
  cout << result << endl;

  result = a || b;
  cout << result << endl;

  result = !a;
  cout << result << endl;

  bool c = false;
  int x = 0;
  result = (c || (x = 42));
  cout << x << endl;

  return 0;
}