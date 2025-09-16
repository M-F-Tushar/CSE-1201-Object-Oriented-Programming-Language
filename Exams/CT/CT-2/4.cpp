/*Q.4 Banking System with Runtime Polymorphism [7 Marks]*/
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Account {
protected:
    string accountNumber;
    string ownerName;
    double balance;

public:
    Account(string accNum, string owner, double initialBalance = 0.0) 
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {}
    
    virtual ~Account() {} // Virtual destructor
    
    // Pure virtual functions for polymorphic behavior
    virtual bool withdraw(double amount) = 0;
    virtual void deposit(double amount) = 0;
    virtual void displayAccountInfo() const = 0;
    
    // Common functionality
    double getBalance() const { return balance; }
    string getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }
};

class SavingsAccount : public Account {
private:
    double minimumBalance;
    
public:
    SavingsAccount(string accNum, string owner, double initialBalance = 0.0, 
                   double minBalance = 100.0) 
        : Account(accNum, owner, initialBalance), minimumBalance(minBalance) {}
    
    // Override withdraw - no overdraft allowed
    bool withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
            return false;
        }
        
        if (balance - amount < minimumBalance) {
            cout << "Withdrawal denied! Insufficient funds. ";
            cout << "Minimum balance of $" << minimumBalance << " must be maintained." << endl;
            return false;
        }
        
        balance -= amount;
        cout << "Withdrawal successful! Amount: $" << amount << endl;
        cout << "New balance: $" << balance << endl;
        return true;
    }
    
    void deposit(double amount) override {
        if (amount <= 0) {
            cout << "Invalid deposit amount!" << endl;
            return;
        }
        
        balance += amount;
        cout << "Deposit successful! Amount: $" << amount << endl;
        cout << "New balance: $" << balance << endl;
    }
    
    void displayAccountInfo() const override {
        cout << "\n=== SAVINGS ACCOUNT ===" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "Minimum Balance: $" << minimumBalance << endl;
        cout << "Overdraft: Not Allowed" << endl;
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;
    
public:
    CurrentAccount(string accNum, string owner, double initialBalance = 0.0, 
                   double overdraft = 1000.0) 
        : Account(accNum, owner, initialBalance), overdraftLimit(overdraft) {}
    
    // Override withdraw - overdraft allowed up to limit
    bool withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
            return false;
        }
        
        double availableBalance = balance + overdraftLimit;
        
        if (amount > availableBalance) {
            cout << "Withdrawal denied! Exceeds overdraft limit of $" << overdraftLimit << endl;
            cout << "Available balance (including overdraft): $" << availableBalance << endl;
            return false;
        }
        
        balance -= amount;
        cout << "Withdrawal successful! Amount: $" << amount << endl;
        cout << "New balance: $" << balance;
        
        if (balance < 0) {
            cout << " (Overdraft: $" << (-balance) << ")";
        }
        cout << endl;
        return true;
    }
    
    void deposit(double amount) override {
        if (amount <= 0) {
            cout << "Invalid deposit amount!" << endl;
            return;
        }
        
        balance += amount;
        cout << "Deposit successful! Amount: $" << amount << endl;
        cout << "New balance: $" << balance << endl;
    }
    
    void displayAccountInfo() const override {
        cout << "\n=== CURRENT ACCOUNT ===" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
        cout << "Available Balance: $" << (balance + overdraftLimit) << endl;
    }
};

// Banking system demonstration
int main() {
    // Create different account types
    Account* accounts[] = {
        new SavingsAccount("SAV001", "Alice Johnson", 500.0, 100.0),
        new CurrentAccount("CUR001", "Bob Smith", 300.0, 1000.0)
    };
    
    cout << "=== BANKING SYSTEM DEMONSTRATION ===" << endl;
    
    // Display initial account information
    for (int i = 0; i < 2; i++) {
        accounts[i]->displayAccountInfo();
    }
    
    cout << "\n=== TRANSACTION TESTING ===" << endl;
    
    // Test savings account (overdraft not allowed)
    cout << "\n--- Testing Savings Account ---" << endl;
    accounts[0]->withdraw(200.0);  // Should succeed
    accounts[0]->withdraw(250.0);  // Should fail (below minimum balance)
    accounts[0]->deposit(100.0);   // Should succeed
    
    // Test current account (overdraft allowed)
    cout << "\n--- Testing Current Account ---" << endl;
    accounts[1]->withdraw(500.0);  // Should succeed (goes into overdraft)
    accounts[1]->withdraw(900.0);  // Should fail (exceeds overdraft limit)
    accounts[1]->deposit(400.0);   // Should succeed
    
    // Display final account states
    cout << "\n=== FINAL ACCOUNT STATES ===" << endl;
    for (int i = 0; i < 2; i++) {
        accounts[i]->displayAccountInfo();
    }
    
    // Clean up memory
    for (int i = 0; i < 2; i++) {
        delete accounts[i];
    }
    
    return 0;
}
