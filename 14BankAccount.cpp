#include <iostream>
using namespace std;

class BankAccount {
  private:
    string accountNumber;
    string accountHolderName;
    string accountType;
    float accountBalance;
  public:
    BankAccount(string number, string holderName, string type, float balance) {
      accountNumber = number;
      accountHolderName = holderName;
      accountType = type;
      accountBalance = balance;      
    }
    void setAccountNumber(string number) {
      accountNumber = number;
    }
    void setAccountHolderName(string holderName){
      accountHolderName = holderName;
    }
    void setAccountType(string type) {
      accountType = type;
    }
    void setAccountBalance(float balance) {
      accountBalance = balance;
    }

    string getAccountNumber() {
      return accountNumber;
    }
    string getAccountHolderName() {
      return accountHolderName;
    }
    string getAccountType() {
      return accountType;
    }
    float getAccountBalance() {
      return accountBalance;
    }

    void deposit(float amount) {
      accountBalance += amount;
    }
    void withDraw(float take) {
      if (accountBalance >= take) {
        accountBalance -= take;
      } else {
        cout << "Error: Insufficient Funds!" << endl;
      }
    }
    
    BankAccount operator+(const BankAccount& other) {
      BankAccount result("", "", "", 0);
      result.accountBalance = accountBalance + other.accountBalance;
      return result;
    }
    bool operator==(const BankAccount& other) {
      return accountNumber == other.accountNumber;
    }
    virtual float getInterestRate() {
      return 0.0;
    }

    bool transferFunds(BankAccount& transfer, float amount) {
      if (amount <= 0) {
        cout << "Transfer amount must be positive or grater than 0" << endl;
        return false;
      }
      if (accountBalance < amount) {
        cout << "insufficient funds in the account!" << endl;
        return false;
      }

      accountBalance -= amount;
      transfer.accountBalance += amount;

      cout << "Transfer successful! " << amount << " has been transferred from account number " << accountNumber << " to account number " << transfer.accountNumber << "." << endl; 
      return true;
    }
};

class SavingsAccount : public BankAccount {
  public:
    SavingsAccount(string number, string holderName, float balance) : BankAccount(number, holderName, "Savings", balance) {}
    float getInterestRate() override {
      return 0.01;
    }
};

class CheckingsAccount : public BankAccount {
  public:
    CheckingsAccount(string number, string holderName, float balance) : BankAccount(number, holderName, "Checking", balance) {}
    float getInterestRate() override {
      return 0.07;
    }
};

int main(){
  BankAccount account1("123", "James Maddison", "Savings", 25000.0);
  BankAccount account2("231", "Cuti Romero", "Checking", 47500.0);
  BankAccount account3("312", "Son Heung-Min", "Savings", 95000.0);
  SavingsAccount account4("321", "Ben Davies", 12500.0);
  CheckingsAccount account5("213", "Wilson Odobert", 7500.0);

  //Have Fun With Deposit and Withdraw Functions
  account1.deposit(125000.0);
  account1.withDraw(12000.0);
  cout << "James Maddison's Account Balance: " << account1.getAccountBalance() << endl;

  account2.withDraw(2000.0);
  account2.deposit(180000.0);
  cout << "Cuti Romero's Account Balance: " << account2.getAccountBalance() << endl;

  account3.deposit(375000.0);
  account3.withDraw(33000.0);
  cout << "Son Heung-Min's Account Balance: " << account3.getAccountBalance() << endl;

  account4.withDraw(10000.0);
  account4.deposit(60000.0);
  cout << "Ben Davis's Account Balance: " << account4.getAccountBalance() << endl;

  account5.withDraw(500.0);
  account5.deposit(22000.0);
  cout << "Wilson Odobert's Account Balance: " << account5.getAccountBalance() << endl;

  cout << endl;
  // Add two Bank Accounts
  BankAccount account6 = account1 + account4;
  cout << "Combined balance of James Maddison and Ben Davis: " << account6.getAccountBalance() << endl;

  //Compare two bank accounts
  if (account1 == account3) {
      cout << "Account numbers match" << endl;
  }
  else {
      cout << "Account numbers do not match" << endl;
  }

  // Call getInterestRate method on child objects
  cout << "Savings account interest rate: " << account4.getInterestRate() << endl;
  cout << "Checking account interest rate: " << account5.getInterestRate() << endl;

  cout << endl;

  account1.transferFunds(account3, 1250);
  cout << "James Maddison's Account Balance: " << account1.getAccountBalance() << endl;
  cout << "Son Heung-Min's Account Balance: " << account3.getAccountBalance() << endl;

  return 0;
}