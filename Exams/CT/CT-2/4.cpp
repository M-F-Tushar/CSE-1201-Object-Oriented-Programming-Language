/*Q.4 Banking System with Runtime Polymorphism [7 Marks]*/
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber, ownerName;
    double balance;
public:
    Account(string accNum, string owner, double bal = 0.0) 
        : accountNumber(accNum), ownerName(owner), balance(bal) {}
    virtual ~Account() {}
    virtual bool withdraw(double) = 0;
    virtual void deposit(double) = 0;
    virtual void displayAccountInfo() const = 0;
};

class SavingsAccount : public Account {
    double minBalance;
public:
    SavingsAccount(string acc, string owner, double bal = 0, double minB = 100)
        : Account(acc, owner, bal), minBalance(minB) {}
    
    bool withdraw(double amt) override {
        if (amt <= 0) { cout << "Invalid amount!\n"; return false; }
        if (balance - amt < minBalance) { 
            cout << "Withdrawal denied! Minimum balance $" << minBalance << endl; 
            return false; 
        }
        balance -= amt; 
        cout << "Withdrawal successful: $" << amt << ", New balance: $" << balance << endl;
        return true;
    }

    void deposit(double amt) override {
        if (amt <= 0) { cout << "Invalid deposit!\n"; return; }
        balance += amt; 
        cout << "Deposit successful: $" << amt << ", New balance: $" << balance << endl;
    }

    void displayAccountInfo() const override {
        cout << "\n--- SAVINGS ACCOUNT ---\nAcc#: " << accountNumber 
             << ", Owner: " << ownerName << ", Balance: $" << balance
             << ", Min Balance: $" << minBalance << endl;
    }
};

class CurrentAccount : public Account {
    double overdraft;
public:
    CurrentAccount(string acc, string owner, double bal = 0, double od = 1000)
        : Account(acc, owner, bal), overdraft(od) {}

    bool withdraw(double amt) override {
        if (amt <= 0) { cout << "Invalid amount!\n"; return false; }
        if (amt > balance + overdraft) { 
            cout << "Withdrawal denied! Exceeds overdraft limit $" << overdraft << endl;
            return false; 
        }
        balance -= amt; 
        cout << "Withdrawal successful: $" << amt << ", New balance: $" << balance;
        if (balance < 0) cout << " (Overdraft: $" << -balance << ")";
        cout << endl;
        return true;
    }

    void deposit(double amt) override {
        if (amt <= 0) { cout << "Invalid deposit!\n"; return; }
        balance += amt; 
        cout << "Deposit successful: $" << amt << ", New balance: $" << balance << endl;
    }

    void displayAccountInfo() const override {
        cout << "\n--- CURRENT ACCOUNT ---\nAcc#: " << accountNumber 
             << ", Owner: " << ownerName << ", Balance: $" << balance
             << ", Overdraft Limit: $" << overdraft << endl;
    }
};

int main() {
    Account* accounts[] = {
        new SavingsAccount("SAV001","Alice",500,100),
        new CurrentAccount("CUR001","Bob",300,1000)
    };

    cout << "=== Initial Accounts ===\n";
    for (auto acc : accounts) acc->displayAccountInfo();

    cout << "\n--- Transactions ---\n";
    accounts[0]->withdraw(200); accounts[0]->withdraw(250); accounts[0]->deposit(100);
    accounts[1]->withdraw(500); accounts[1]->withdraw(900); accounts[1]->deposit(400);

    cout << "\n=== Final Account States ===\n";
    for (auto acc : accounts) acc->displayAccountInfo();

    for (auto acc : accounts) delete acc;
}

