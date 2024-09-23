#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main(){
  vector<int> v;
  int num;
  
  cout << "Enter a series of integers (Add non-integer to stop): " << endl;
  while (cin >> num) {
    v.push_back(num);
  }

  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "You entered: ";
  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;

  sort(v.begin(), v.end());

  cout << "Sorted: ";
  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  
  return 0;
}
