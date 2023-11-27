#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string& number, const std::string& holder, double initialBalance)
        : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    void displayDetails() const {
        std::cout << "Account Details for Account (ID: " << accountNumber << "):\n";
        std::cout << "   Holder: " << accountHolder << "\n";
        std::cout << "   Balance: $" << balance << "\n";
    }

    const std::string& getAccountNumber() const {
        return accountNumber;
    }

    const std::string& getAccountHolder() const {
        return accountHolder;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit: $" << amount << "\n";
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal: $" << amount << "\n";
        } else {
            std::cout << "Insufficient funds for withdrawal.\n";
        }
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate)
        : Account(number, holder, initialBalance), interestRate(rate) {}

    void withdraw(double amount) override {
        const double minBalance = 100; // Minimum balance for savings account
        if (balance - amount >= minBalance) {
            balance -= amount;
            std::cout << "Withdrawal: $" << amount << "\n";
        } else {
            std::cout << "Withdrawal failed. Minimum balance not maintained.\n";
        }
    }

    double getInterestRate() const {
        return interestRate;
    }

    ~SavingsAccount() {}
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit)
        : Account(number, holder, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            std::cout << "Withdrawal: $" << amount << "\n";
        } else {
            std::cout << "Withdrawal failed. Overdraft limit exceeded.\n";
        }
    }

    double getOverdraftLimit() const {
        return overdraftLimit;
    }

    ~CurrentAccount() {}
};

// Operator overloading for transferring money between accounts
CurrentAccount operator+(CurrentAccount& current, SavingsAccount& savings) {
    double transferAmount = 300;
    if (savings.withdraw(transferAmount), true) {
        current.deposit(transferAmount);
    }
    std::cout << "Transfer from " << savings.getAccountHolder() << " to " << current.getAccountHolder() << " successful.\n";
    return current;
}

// Operator overloading for displaying account details
std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account Details for Account (ID: " << account.getAccountNumber() << "):\n";
    os << "   Holder: " << account.getAccountHolder() << "\n";
    os << "   Balance: $" << account.getBalance() << "\n";
    return os;
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    savings.displayDetails();
    current.displayDetails();

    // Transfer 300 from savings to current
    current = current + savings;

    savings.displayDetails();
    current.displayDetails();

    return 0;
}
