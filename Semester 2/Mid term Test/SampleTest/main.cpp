#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account{
public:
    Account(string accountNumber, double balance) : accountNumber_(accountNumber), balance_(balance){
        //
    }

    void deposit(double amount){
        balance_ = balance_ + amount;
    }

    void withdraw(double amount){
        balance_ = balance_ - amount;
    }

    double getBalance(){
        return balance_;
    }

    string getAccountNumber(){
        return accountNumber_;
    }
protected:
    string accountNumber_;
    double balance_;

};

class CheckingAccount : public Account{
public:
    CheckingAccount(string accountNumber, double balance) : Account("C10002", 4000.0){
        accountNumber_ = accountNumber;
        balance_ = balance;
    }

    void withdraw(double amount){
        balance_ = balance_ - amount;
    }
};

class SavingsAccount : public Account{
public:
    SavingsAccount(string accountNumber, double balance, double interestRate) : Account("C20003", 5000){
        accountNumber_ = accountNumber;
        balance_ = balance;
        interestRate_ = interestRate;
    }

    void addInterest(){
        balance_ = balance_ + (balance_*interestRate_)/100.0;
    }

    double getInterestRate(){
        return interestRate_;
    }
protected:
    double interestRate_;
};

class Client{
public:
    Client(string name) : name_(name){
        //
    }

    void addAccount(Account* account){
        accounts.emplace_back(account);
    }

    void printAccount(){
        for (Account *value : accounts){
            std::cout << value->getAccountNumber() << "---" << value->getBalance() << " ";
        }
    }

    string getName(){
        return name_;
    }

private:
    string name_;
    vector <Account*> accounts;
};

class Bank{
public:
    void addClient(Client* client){
        clients.emplace_back(client);
    }

    void printClients(){
        for (auto * value : clients){
            std::cout << value->getName() << " ";
            value->printAccount();
            std::cout << endl;
        }
    }

private:
    vector <Client *> clients;
};

int main()
{
    // Create accounts
    Account account1("A10001", 5000);
    SavingsAccount account2("S10001", 10000, 2.5);
    CheckingAccount account3("C10001", 2000);

    // Deposit and withdraw from accounts
    account1.deposit(1000);
    account1.withdraw(2000);
    account2.deposit(500);
    account2.addInterest();
    account3.withdraw(500);

    // Create clients and add accounts to them
    Client client1("John Doe");
    client1.addAccount(&account1);
    client1.addAccount(&account2);
    //client1.printAccount();

    Client client2("Jane Smith");
    client2.addAccount(&account3);
    //client2.printAccount();

    // Create bank and add clients to it
    Bank bank;
    bank.addClient(&client1);
    bank.addClient(&client2);

    // Print bank clients and their accounts
    bank.printClients();
    return 0;
}
