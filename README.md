# Banking System (C++)

## Project Overview

The **Banking System** is a menu-driven C++ console application that demonstrates object-oriented programming through a simple banking simulation. It includes a base `BankAccount` class and three derived account types: `SavingsAccount`, `CheckingAccount`, and `FixedDepositAccount`.

The application lets users deposit and withdraw money, check balances, view account information, calculate interest for eligible accounts, and check the overdraft limit for a checking account.

## Main Features

- **Deposit Money:** Add a valid amount to an account balance.
- **Withdraw Money:** Withdraw money from the selected account when sufficient funds are available.
- **Check Balance:** View the current balance of a selected account.
- **Display Account Information:** View the account number, account holder, and balance.
- **Calculate Interest:** Calculate interest for savings and fixed-deposit accounts.
- **Check Overdraft Limit:** View the overdraft limit for a checking account.
- **Menu-Based Navigation:** Select an operation and account type from the console menu.

---

## 1. Main Menu

The main menu displays the available banking operations. The user selects an option and then chooses the account to use.

### Screenshot

![Banking System Main Menu](screenshot/menu.png)

---

## 2. Deposit Money

The Deposit Money option asks for an amount and adds it to the selected account's balance. A success message is displayed for a valid positive amount; invalid amounts are rejected.

### Screenshots

![Deposit Money](screenshot/deposit-1.png)

![Deposit Result](screenshot/deposit-2.png)

---

## 3. Withdraw Money

The Withdraw Money option allows the user to withdraw money from the selected account. A withdrawal is accepted when the amount is valid and within the account's available balance.

### Screenshot

![Withdraw Money](screenshot/withdraw.png)

---

## 4. Check Balance, Display Account Information, and Calculate Interest

This section shows how users can check an account's current balance, view account details, and calculate interest for savings and fixed-deposit accounts.

### Screenshots

**Check Balance**

![Check Balance](screenshot/check-balance.png)

**Display Account Information**

![Display Account Information](screenshot/display-account.png)

**Calculate Interest**

![Interest Calculation](screenshot/interest.png)

---

## 5. Overdraft Facility

The Overdraft Facility is available for checking accounts. It allows a withdrawal to exceed the available balance up to the configured overdraft limit. This feature is shown separately from the regular Withdraw Money section.

### Screenshot

![Overdraft Facility](screenshot/overdraft.png)
