#include <iostream>
#include <fstream>

using namespace std;
int main(){
  ifstream input_file("input.txt");
  ofstream output_file("output.txt");

  if (input_file.is_open() && output_file.is_open()) {
    char c;
    while (input_file.get(c)) {
      output_file.put(c);
    }
    cout << "File Copied Successfully.\n";
  } else {
    cerr << "Error Opening file\n";
  }

  input_file.close();
  output_file.close();
  
  return 0;
}
