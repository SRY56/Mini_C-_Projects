#include <iostream>
using namespace std;

class BankAccount {
  private:
    double balance;
    int accountNumber;
  public:
    BankAccount(double initialBalance, int accountNum) {
      balance = initialBalance;
      accountNumber = accountNum;
    }
    void deposit(double amount) {
      balance += amount;
    }
    void withdraw(double amount) {
      if (balance >= amount) {
        balance -= amount;
      } else {
        cout << "Insufficient funds in the account!" << endl;
      }
    }
    double getBalance() {
      return balance;
    }

    double getAccountNumber() {
      return accountNumber;
    }
};

int main(){
  //Create BankAccount object with initial balance and account number
  BankAccount account(0, 315355);

  account.deposit(100);

  account.withdraw(50);

  cout << "Current account balance is: $" << account.getBalance() << endl;
  cout << "account number: " << account.getAccountNumber() << endl;

  return 0;
}
