/*Create a class called AccountStore (shown in class diagram) to maintain an array of 
pointers to Account objects (from Exercise 1). Assume account store has a max capacity 
of 10 accounts to maintain. Provide public accessor methods to create account, get 
number of accounts, get account at index, and to delete the account from the account 
store. CreateAccount() and DeleteAt() functions should return the status true if 
accounts created or deleted and false otherwise.*/
#include <iostream>

using namespace std;


// copied class here
class Account{
  int accountNumber;
  double balance;

  static int numOfAccounts;

public:
    Account(double balance){
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

/*the better way to do this exercise is to use account numbers instead of indices.
This makes more sense as someone like an end user will reasonably have access to 
an account number but not an index*/
class AccountStore{
    Account *accounts[10];
    int numOfAccounts;

public:
    AccountStore(){
        for(int i = 0; i < 10; i++) accounts[i] = nullptr;
        numOfAccounts = 0;
    }

    int createAccount(double balance){
        // search for an empty slot
        for(int i = 0; i < 10; i++){
            if(!accounts[i]){ // this is equivalent to saying accounts[i] == nullptr
                accounts[i] = new Account(balance); // store pointer to newly created account
                return i; // return index;
            }
        }

        return -1; // if there is no space in our array, return -1s
    }

    bool deleteAccount(int accountNumber){
        for(int i = 0; i < 10; i++){
            if(accounts[i]->getAccountNumber() == accountNumber){
                delete accounts[i];     // free up allocated space to avoid memory leaks
                accounts[i] = nullptr;  // set that location to nullptr to signify its an empty space
                return true;            // to signify that the account was deleted successfuly
            }
        }

        cout << "Account with A/C no: " << accountNumber << " does not exist\n";
        return false;
    }
};