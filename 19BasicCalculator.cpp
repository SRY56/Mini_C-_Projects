#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Calculator{
  public:
    T add(T num1, T num2) {
      return num1 + num2;
    }

    T subtract(T num1, T num2) {
      return num1 - num2;
    }
    
    T multiply(T num1, T num2) {
      return num1 * num2;
    }
    
    T divide(T num1, T num2) {
      if (num2 == 0) {
        throw runtime_error("Attempt to divide by Zero!");
      } else {
        return num1 / num2;
      }
    }

    T modulus(T num1, T num2) {
      return num1 % num2;
    }
};

int main(){
  Calculator<int> intBasic;
  int num1 = 10;
  int num2 = 5;

  cout << "Integer Calculation:\n";
  cout << "Sum: " << intBasic.add(num1, num2) << endl;
  cout << "Difference: " << intBasic.subtract(num1, num2) << endl;
  cout << "Product: "  << intBasic.multiply(num1, num2) << endl;
  cout << "Quotient: " << intBasic.divide(num1, num2) << endl;
  cout << "Remainder: " << intBasic.modulus(num1, num2) << endl;

  cout << endl;

  Calculator<double> doubleBasic;
  double dou1 = 3.14;
  double dou2 = 2.71;
  
  cout << "Double Calculation:\n";
  cout << "Sum: " << doubleBasic.add(dou1, dou2) << endl;
  cout << "Difference: " << doubleBasic.subtract(dou1, dou2) << endl;
  cout << "Product: "  << doubleBasic.multiply(dou1, dou2) << endl;
  cout << "Quotient: " << doubleBasic.divide(dou1, dou2) << endl;

  cout << endl;
  
  try {
    int zero = 0;
    intBasic.divide(num1, zero);
  } catch (runtime_error& e) {
    cerr << "Error: " << e.what() << endl;
  }
  
  return 0;
}
