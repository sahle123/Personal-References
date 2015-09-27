#ifndef BANK_LEDGER_H_INCLUDED
#define BANK_LEDGER_H_INCLUDED

/*
*
*    Author:       Sahle A. Alturaigi
*    Date:          June 30, 2012
*    Description: Check Below
*
*/

/*
// The bank_ledger class implements a database of currently active and closed
// accounts. It uses the account class. The bank_ledger class consists of TWO
// set bank accounts: Bank accounts that are currently active and bank accounts
// that have been closed. The maximum number of active/closed bank accounts
// that the bank_ledger object can store is determined at run time. The
// bank_ledger class should provide the support for the following functions:
//
// Create a new bank_ledger object
// Create a copy of a bank_ledger object
// Create a new account
// Close a current account
// Determine the current balance of a current account
// Deposit money into a current account
// Withdraw money from a current account
// Transfer money from one current account to another current account
// Print account history of a current account
// Print account details of a current account
// Print account details of all current accounts
// Print account details of all closed accounts.
*/

// Directives
#include "account.h"
#include <string.h>
#include <iostream>

/// Problem in account class.  Need to fix set_name function as well as
/// refactor code in constructors for set_name.
/// Problem with history not showing up in bank_ledger

class bank_ledger
{
public:
    typedef char* string;
    // Constructor
    bank_ledger(unsigned int max_number_of_accounts); // Done
    bank_ledger(account info, unsigned int max_number_of_accounts); // INC

    // Copy Constructor

    // Destructor
    ~bank_ledger(); // Done

    // Mod functions

protected:
    bool check_free_space();

private:
    account* active_bank_accounts;
    account* closed_bank_accounts;
    unsigned int number_of_accounts;
    unsigned int max_accounts;
};

//-----------------------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------------------

// Constructor
bank_ledger::bank_ledger(unsigned int max_number_of_accounts)
{
    // Initialize Private variables
    max_accounts= max_number_of_accounts;
    number_of_accounts = 0;

    // Initialize active_bank_accounts
    active_bank_accounts = new account[max_accounts];

    // Initialize closed_bank_accounts
    closed_bank_accounts = new account[max_accounts];

    // Message to User.
    std::cout << "Bank ledger initialized" << std::endl;
}

// Constructor
bank_ledger::bank_ledger(account info ,unsigned int max_number_of_accounts)
{
    // Initialize Private variables
    max_accounts = max_number_of_accounts;
    number_of_accounts = 1;

    // Turning active_bank_accounts into a a dynamic array of type account.
    active_bank_accounts = new account[max_accounts];
    active_bank_accounts[0] = info;

    // Initializing closed_bank_accounts
    closed_bank_accounts = new account[max_accounts];

    // Printing out info to User
    /// Change later. Overload output operator
    string temp_str = active_bank_accounts[0].get_name();
    double balance = active_bank_accounts[0].get_balance();
    std::cout << info.get_name() << std::endl;
    std::cout << "Bank ledger initialized with: " << temp_str << std::endl;
    std::cout << "Balance = " << balance << std::endl;
    std::cout << "History: " << *active_bank_accounts[0].get_history() << std::endl;


    std::cout << "Bank ledger initialized." << std::endl;
}

// Destructor
bank_ledger::~bank_ledger()
{
    delete[] active_bank_accounts;
    delete[] closed_bank_accounts;
}

//-----------------------------------------------------------------------------
//  Protected functions
//-----------------------------------------------------------------------------
bool bank_ledger::check_free_space()
{
    if(number_of_accounts >= max_accounts)
    {
        // Produce error message + stop operation
        std::cout << "You may not exceed your max account limit." << std::endl;
        return false;
    }

    return true;
    // Else, nothing happens. All clear! :D
}








///-----------------
/*
class bank_ledger
{
public:
    // Constructors
        /// Number of Max bank accounts is determined at run-time (3rd parameter)
    // Copy Constructor

    // Destructors

    // Mod Functions
    void account_status(bool _bank_account_status); //(0 = closed; 1 = open)
    void pull_balance();
    void deposit_funds(unsigned int amount);
    void withdraw_funds(unsigned int amount);

protected:
    // Helper functions
    bool check_account_status();
    void print_error_msg();

private:
    bool bank_account_status;
    int account_balance;
};

//-----------------------------------------------------------------------------
// Public Functions
//-----------------------------------------------------------------------------

void bank_ledger::account_status(bool _bank_account_status)
{
    bank_account_status = _bank_account_status;
    std::cout << "Account = " << bank_account_status << std::endl;
    // Create message string for user.
    //std::cout << "Your bank account status is now " <<
}

void bank_ledger::pull_balance()
{
    std::cout << "Your Balance is: " << account_balance << std::endl;
    return;
}

void bank_ledger::deposit_funds(unsigned int amount)
{
    account_balance = account_balance + amount;
    std::cout << "You have deposited: " << amount << "in to your account." << std::endl;
    return;
}

void bank_ledger::withdraw_funds(unsigned int amount)
{

}

//-----------------------------------------------------------------------------
// Protected functions
//-----------------------------------------------------------------------------
*/

#endif // BANK_LEDGER_H_INCLUDED
