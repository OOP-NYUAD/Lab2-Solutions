#include <iostream>

using namespace std;

class Account{
  int accountNumber;
  double balance;

  static int numOfAccounts;

public:
  Account(double balance = 0){
      // I chose to assign account number sequentially using a static variable
      accountNumber = numOfAccounts++;
      this->balance = balance;
  }

  int getAccountNumber(){ return accountNumber; }
  double getBalance(){ return balance; } 

  void debit(double amount){
    if(amount > balance){
      cout << "amount withdrawn exceeds the current balance!\n";
      return; // return without actually debiting the account
    }
  }

  void credit(double amount){
    if(amount < 0){
      cout << "can't credit a negative amount\n";
      return;
    }

    balance += amount;
  }

  void print(){
    cout << "A/C no: " << accountNumber << " Balance = " << balance << "$\n";
  }
};
/* A class called Account, which models a bank account, is designed as shown in the class diagram. It contains:
    - Two private data members: accountNumber (int) and balance (double), which
      maintains the current account balance.
    - Public functions credit() and debit(), which adds or subtracts the given 
      amount from the balance, respectively. The debit() function shall print 
      "amount withdrawn exceeds the current balance!" if amount is more than 
      balance.
    - A public function print(), which shall print "A/C no: xxx Balance=xxx“ 
    (e.g., A/C no: 991234 Balance=$88.88), with balance rounded to two decimal 
    places.
*/