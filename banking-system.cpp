#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string num, string name, double bal)
    {
        accountNumber = num;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful." << endl;
        }
        else
        {
            cout << "Invalid amount." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    double getBalance()
    {
        return balance;
    }

    void reduceBalance(double amount)
    {
        balance -= amount;
    }

    void displayAccountInfo()
    {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(string num, string name, double bal, double rate)
        : BankAccount(num, name, bal)
    {
        interestRate = rate;
    }

    double calculateInterest()
    {
        return getBalance() * interestRate / 100;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(string num, string name, double bal, double limit)
        : BankAccount(num, name, bal)
    {
        overdraftLimit = limit;
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= getBalance() + overdraftLimit)
        {
            if (amount > getBalance())
            {
                double remaining = amount - getBalance();
                reduceBalance(getBalance());
                // The remaining amount uses the overdraft facility.
                cout << "Withdrawal successful using overdraft." << endl;
                cout << "Overdraft used: " << remaining << endl;
            }
            else
            {
                BankAccount::withdraw(amount);
            }
        }
        else
        {
            cout << "Overdraft limit exceeded." << endl;
        }
    }

    void checkOverdraft()
    {
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(string num, string name, double bal,
                        int t, double rate)
        : BankAccount(num, name, bal)
    {
        term = t;
        interestRate = rate;
    }

    double calculateInterest()
    {
        return getBalance() * interestRate * term / 1200;
    }
};

// Function overloading
void calculateInterest(SavingsAccount &s)
{
    cout << "Savings Interest: " << s.calculateInterest() << endl;
}

void calculateInterest(FixedDepositAccount &f)
{
    cout << "Fixed Deposit Interest: " << f.calculateInterest() << endl;
}

int main()
{
    SavingsAccount savings("1001", "Usman", 10000, 5);
    CheckingAccount checking("1002", "Ahmed", 5000, 2000);
    FixedDepositAccount fixed("1003", "Ali", 50000, 12, 6);

    BankAccount *accounts[3] = {&savings, &checking, &fixed};

    int choice, accountType;
    double amount;

    do
    {
        cout << "\n===== BANKING SYSTEM =====" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Display Account Information" << endl;
        cout << "5. Calculate Interest" << endl;
        cout << "6. Check Overdraft Limit" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 6)
        {
            cout << "\n1. Savings Account" << endl;
            cout << "2. Checking Account" << endl;
            cout << "3. Fixed Deposit Account" << endl;
            cout << "Select Account: ";
            cin >> accountType;

            if (accountType < 1 || accountType > 3)
            {
                cout << "Invalid account type." << endl;
                continue;
            }

            BankAccount *account = accounts[accountType - 1];

            switch (choice)
            {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account->deposit(amount);
                break;

            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                if (accountType == 2)
                    checking.withdraw(amount);
                else
                    account->withdraw(amount);
                break;

            case 3:
                cout << "Balance: " << account->getBalance() << endl;
                break;

            case 4:
                account->displayAccountInfo();
                break;

            case 5:
                if (accountType == 1)
                    calculateInterest(savings);
                else if (accountType == 3)
                    calculateInterest(fixed);
                else
                    cout << "Interest calculation not available." << endl;
                break;

            case 6:
                if (accountType == 2)
                    checking.checkOverdraft();
                else
                    cout << "Overdraft is only available for checking accounts." << endl;
                break;
            }
        }
        else if (choice == 7)
        {
            cout << "Thank you for using the Banking System." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 7);

    return 0;
}