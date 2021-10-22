#include <iostream>
using namespace std;

static int accNo = 100;
class Bank {
  private:
    string name_;
    int accNo_ = 100;
    string address_;
    char type_;
    float balance_;

  public:
    void createAccount() {
      cout<<"Enter your name"<<"\n";
      cin>>name_;
      cout<<"Enter your address"<<"\n";
      cin>>address_;
      cout<<"Enter type of account 'S' for savings 'C' for current"<<"\n";
      char t;
      cin>>t;
      accNo_ = accNo++;
      balance_ = 0;

      cout<<"Your account created successfully!!"<<endl;
      cout<<name_<<" Account number is: "<<accNo_<<endl;
      cout<<name_<<" current balance is: "<<balance_<<endl;
      cout<<"Type of account: "<<type_<<endl;
      
    }


    //4
    void depositAmt() {
      cout<<"Enter the amount to be deposited into your account:"<<"\n";
      float amt;
      cin>>amt;
      balance_ += amt;
      cout<<"Amount deposited successfully! Your current balance is "<<balance_<<"\n";

    }

    
    //4
    void withdrawAmt() {
      cout<<"Enter the amount to be withdrawed from your account"<<"\n";
      float amt;
      cin>>amt;
      if(amt <= balance_) {
        balance_ -= amt;
        cout<<"Amount withdrawed successfully! Your current balance is "<<balance_<<"\n";
      }
      else {
        cout<<"Sorry! Insuffient balance. Please enter a valid amount. Your current balance is "<<balance_<<"\n";
      }  

    }

    void checkBalance() {
      cout<<"Your current balance is "<<balance_<<"\n";
    }

    int getAccNo() {
      return accNo_;
    }
    
    string getName() {
      return name_;
    }
    float getBalance() {
      return balance_;
    }
    string getAddress() {
      return address_;
    }


    void displayAllCustomers(); 
    void displayLastEntryAccNo();
    bool accountExists(int accNo);
    void retreiveAddressOfCustomer(int accNo);
    void retreiveNameOfCustomer(int accNo);
    void retreiveBalanceOfCustomer(int accNo);
    //void 
};

Bank bank[10];
static int users = 0;

//2
void Bank::displayAllCustomers() {
  for(int i = 0; i < users; i++) {
    cout<<"User "<<i+1<<":"<<endl;
    // cout<<"Name: "<<bank[i].getName()<<endl;
    cout<<"Account Number: "<<bank[i].getAccNo()<<endl;
    cout<<"Balance: "<<bank[i].getBalance()<<endl;
  }
}


//5
void Bank::displayLastEntryAccNo() {
    cout<<"Account number of last entry: "<<bank[users].getAccNo();
}

//6
bool Bank::accountExists(int accNo) {
  for(int i = 0; i < users; i++) {
    if(bank[i].getAccNo() == accNo) {
      return true;
    }
  }
  return false;
}


//7
void Bank::retreiveNameOfCustomer(int accNo) {
  for(int i = 0; i < users; i++) {
    if(bank[i].getAccNo() == accNo) {
      cout<<"Name of the Customer is: "<<bank[i].getName();
    }
  }
  
}


//8
void Bank::retreiveAddressOfCustomer(int accNo) {
  for(int i = 0; i < users; i++) {
    if(bank[i].getAccNo() == accNo) {
      cout<<"Address of customer is: "<<bank[i].getAddress();
    }
  }
  
}

//9
void Bank::retreiveBalanceOfCustomer(int accNo) {
  for(int i = 0; i < users; i++) {
    if(bank[i].getAccNo() == accNo) {
      cout<<"Balance of the customer is: "<<bank[i].getBalance();
    }
  } 
}







int main() {
  Bank b;
  int userOption, userContinue;
  do {
    cout<<"\n\nEnter 1 to create an account"<<"\n";
    cout<<"Enter 2 to deposit an amount"<<"\n";
    cout<<"Enter 3 to withdraw an amount"<<"\n";
    cout<<"Enter 4 to check balance"<<"\n";
    cout<<"Enter 5 to display the account number of the last entry"<<"\n";
    cout<<"Enter 6 to check whether an account exists or not"<<"\n";
    cout<<"Enter 7 retrieve the name of the account holder"<<"\n";
    cout<<"Enter 8 retrieve the address of the account holder"<<"\n";
    cout<<"Enter 9 retrieve the balance of the account holder"<<"\n";
    cout<<"Enter 10 to display all account holders"<<"\n";
    cout<<"Enter 11 to exit"<<"\n";


    
    
    cin>>userOption;
    int acc;
    switch(userOption) {
      case 1:
        bank[users].createAccount();
        users++;
        break;
      case 2:
        cout<<"Enter your account no: "<<endl;
        cin>>acc;
        for(int i = 0; i < users; i++) {
          if(bank[i].getAccNo() == accNo) {
            bank[i].depositAmt();
          }
        }
        break;
      case 3:
        cout<<"Enter your account no: "<<endl;
        cin>>acc;
        for(int i = 0; i < users; i++) {
          if(bank[i].getAccNo() == acc) {
            bank[i].withdrawAmt();
          }
        }
        break;
      case 4:
        cout<<"Enter your account no: "<<endl;
        cin>>acc;
        for(int i = 0; i < users; i++) {
          if(bank[i].getAccNo() == acc) {
            bank[i].checkBalance();
          }
        }
        break;


      case 5:
        b.displayLastEntryAccNo();
        break;

      case 6:
        cout<<"Enter your account no: "<<endl;
         cin>>acc;
         if(b.accountExists(acc)) {
           cout<<"Exists"<<endl;
         }
         else {
           cout<<"Not Exists"<<endl;
         }

      case 7:
          cout<<"Enter your account no: "<<endl;
          cin>>acc;
          b.retreiveNameOfCustomer(acc);
          break;

      case 8:
          cout<<"Enter your account no: "<<endl;
          cin>>acc;
          b.retreiveAddressOfCustomer(acc);
          break;

      case 9:
          cout<<"Enter your account no: "<<endl;
          cin>>acc;
          b.retreiveBalanceOfCustomer(acc);
          break;

      case 10:
          b.displayAllCustomers();
          break;

      case 11:
        cout<<"Thanks for using Bank Management System"<<"\n";
         break;

      default:
        cout<<"Enter a valid option"<<endl;
        break;
    }
    cout<<"Do you want to continue then enter 1 otherwise enter 2"<<"\n";
    cin>>userContinue;

  }while(userContinue == 1);
  
 
}
