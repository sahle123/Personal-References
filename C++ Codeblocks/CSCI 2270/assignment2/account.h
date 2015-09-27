#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

/* FILE: account.h
// Written by Shivakant Mishra, Completed by Sahle Alturaigi
// Last modification: February 26, 2012
//
// CLASS PROVIDED: account (an ADT for a bank account)
//
// CONSTRUCTOR for the account class:
//      account (char* i_name, size_t i_acnum, size_t i_hsize);
//	Precondition: strlen(i_name) < MAX_NAME_SIZE.
//	Postcondition: A new account object has been created:
// 	               name: a copy of i_name; ac_number = i_acnum;
//	               history: a dynamic array of size i_hsize of empty
//                     strings; history_size = i_hsize; history_count = 0.
//
// COPY CONSTRUCTOR for the account class:
//      account (const account& ac);
//	Postcondition: A new account object has been created. Its state
//	is a complete copy of the state of account object ac.
//
// DESTRUCTOR for the account class
//	~account( )
//	Postcondition: All dynamic memory of the object has been deallocated.
//
// MODIFICATION MEMBER FUNCTIONS for the account class:
//      void set_name(char* new_name);
//	Precondition: strlen(new_name) < MAX_NAME_SIZE.
//	Postcondition: name has been changed to new_name.
//
//      void set_account_number(size_t new_acnum) {ac_number = new_acnum;}
//	Postcondition: ac_number has been changed to new_acnum.
//
//      void set_balance(double new_balance);
//	Postcondition: balance has been changed to new_balance.
//
//      void add_history(char* new_history);
//	Postcondition: If history_count < history_size, a copy of new_history
//	has been appended in the next available spot in the array history and
//	history_count has been incremented
//
// CONSTANT MEMBER FUNCTIONS for the slot class:
//	char* get_name ( ) const;
//	Postcondition: Pointer to a copy of name has been returned. Memory
// 	for the copy has been allocated using new operator.
//
//      size_t get_account_number ( ) const;
//	Postcondition: The value of ac_number has been returned.
//
// 	double get_balance( ) const;
//	Postcondition: The value of balance has been returned.
//
//	size_t get_max_history_size( ) const;
//	Postcondition: The value of history_size has been returned.
//
//      size_t get_current_history_size ( ) const;
//	Postcondition: The value of history_count has been returned.
//
//      string* get_history( ) const;
//	Postcondition: A copy of the history array has been returned. Memory
//	for the copy has been created using the the new operator.
//
// FRIEND FUNCTION
//      friend ostream& operator <<(ostream& outs, const account& target);
//	overload << to print the current state of the account object. */

#include<iostream>
#include<cstdlib>
#include<string.h>

class account
{
public:
    typedef char* string;
    static const std::size_t MAX_NAME_SIZE = 15; // A strings length cannot exceed this value. strlen(i_name) <= MAX_NAME_SIZE;

    // CONSTRUCTOR
    // Pre: History characters may not exceed 80.
    account();
    account (char* i_name, std::size_t i_acnum, std::size_t i_hsize);
    account (const account& ac);

    // DESTRUCTOR
    ~account( );

    // MODIFICATION MEMBER FUNCTIONS
    void set_name(char* new_name);
    void set_account_number(std::size_t new_acnum);
    void set_balance(double new_balance);
    void set_history_size(std::size_t new_history_size);
    void add_history(char* new_history);

    // CONSTANT MEMBER FUNCTIONS
    char* get_name() const;
    double get_balance() const;
    string* get_history() const;
    std::size_t get_max_history_size() const;
    std::size_t get_current_history_size() const;
    std::size_t get_account_number() const;

    account& operator = (const account& cSource);
    friend std::ostream& operator << (std::ostream& outs, const account& target);

private:
    char name[MAX_NAME_SIZE+1];    // Name of the account holder
    double balance;                              // Current account balance
    string* history;                               // Array to store history of transactions
    std::size_t history_size;                // Maximum size of transaction history
    std::size_t history_count;              // Current size of transaction history
    std::size_t ac_number;                  // Account number
};

// Default history size is 40
account::account()
{
    // Precondition for history size.
    history_size = 40;
    history_count = 0;
    balance = 0;
    ac_number = 0;
    name[0] = NULL;

    // Intializing all history elements to 0
    history = new string[history_size];
    for(std::size_t i = 0; i < history_size; ++i)
    {
        history[i] = new char[80];
        for(int j = 0; j < 80; ++j)
        {
            history[i][j] = 0;
        }
    }
    *history = "No history.";
}

account::account(char* i_name, std::size_t i_acnum, std::size_t i_hsize)
{
    if(strlen(i_name) < MAX_NAME_SIZE + 1)
    {
        set_name(i_name);

        history_size = i_hsize;
        history_count = 0;
        balance = 0;
        ac_number = i_acnum;

        // Initializing all elements to 0 (safe practice.)
        history = new string[i_hsize];
        for(std::size_t i = 0; i < i_hsize; ++i)
        {
            history[i] = new char[80];
            for(int j = 0; j < 80; ++j)
            {
                history[i][j] = 0;
            }
        }

        // This is not needed. Makes it look nice though
        *history = "No history.";
    }
}

// COPY CONSTRUCTOR
// CHECK
account::account(const account& ac)
{

    // CHECK THIS STATEMENT \(^0^)/
    if(this != &ac)
    {
        set_name(ac.get_name());

        ac_number = ac.ac_number;
        history_size = ac.history_size;
        history_count = ac.history_count;
        balance = ac.balance;

        // History strings may not have more than 80 characters
        history = new string[history_size];
        for(std::size_t i = 0; i < history_size; ++i)
        {
            history[i] = new char[80];
            for(int j = 0; j < 80; ++j)
            {
                history[i][j] = 0;
            }
        }

        for(size_t i = 0; i < history_count; ++i)
        {
            strcpy(history[i], ac.history[i]);
        }
    }
}

// DESTRUCTOR
account::~account()
{

    delete[] name;

    for(std::size_t i = 0; i < history_size; ++i)
    {
        delete[]history[i];
    }
    delete[]history;
}

// MOD member function: Changes the name.
void account::set_name(char* new_name)
{
    if(strlen(new_name) < MAX_NAME_SIZE)
    {
        for(std::size_t i = 0; i < strlen(new_name); ++i)
        {
            name[i] = new_name[i];
        }
        name[strlen(new_name)+1] = 0;
    }
}

// MOD member function: Changes the account number.
void account::set_account_number(std::size_t new_acnum)
{
    ac_number = new_acnum;
}

// MOD member function: Changes the balance of the account.
void account::set_balance(double new_balance)
{
    balance = balance + new_balance;
}

void account::set_history_size(std::size_t new_history_size)
{
    history_size = new_history_size;
}

// MOD member function: Appends new_history to the history array.
void account::add_history(char* new_history)
{
    if(history_count < history_size)
    {
        history[history_count] = new_history;
        ++history_count;
    }
}

// CONST member function: Gets the name of the object
char* account::get_name() const
{
    std::cout << strlen(name) << std::endl;
    char* name_ptr;
    name_ptr = new char[MAX_NAME_SIZE + 1];

    // Initialize all values in name_ptr to 0
    for(std::size_t i = 0; i < MAX_NAME_SIZE + 1; ++i)
        name_ptr[i] = 0;

    // Copy values over to name_ptr
    for(std::size_t i = 0; i < strlen(name); ++i)
        name_ptr[i] = name[i];

    return name_ptr;
}

// CONST member function: Gets the account number of the object
size_t account::get_account_number() const
{
    return ac_number;
}

// CONST member function: Gets the balance of the object.
double account::get_balance() const
{
    return balance;
}

// CONST member function: Gets the history size of the object.
std::size_t account::get_max_history_size() const
{
    return history_size;
}

// CONST member function: Gets the history size of the object.
std::size_t account::get_current_history_size() const
{
    return history_count;
}

// CONST member function: A copy of the history array is returned.
char** account::get_history() const
{
    /*
    char** history_ptr;
    history_ptr = new char* [history_size];

    // Copies the history to history_ptr
    for(unsigned int i = 0; i < history_count; ++i)
    {
        //history_ptr[i] = new char[100];
        history_ptr[i] = history[i];
    }
    for(unsigned int i = 0; i < history_count; ++i)
    {
        std::cout << "History_ptr = " << history_ptr[i];
    }
    std::cout << std::endl; */

    // Return the double dereferenced history pointer. (Must derefence to get string (char*))
    return history;
}

account& account::operator = (const account& cSource)
{
    if(this != &cSource)
    {
        for(std::size_t i = 0; cSource.name[i] != 0; ++i)
        {
            name[i] = cSource.name[i];
        }

        ac_number = cSource.ac_number;
        history_size = cSource.history_size;
        history_count = cSource.history_count;
        balance = cSource.balance;

        // Copies all elements from the rightside object's history array to the leftside object's history array.
        for(size_t i = 0; i < history_count; ++i)
        {
            strcpy(cSource.history[i], history[i]);
        }
    }
    return *this;
}

// FRIEND function
std::ostream& operator << (std::ostream& outs, const account& target)
{
    outs << target.get_name() << ", " << target.ac_number << ", " << std::endl;
    outs << "$"<< target.balance << ", " << *target.get_history() << "\n";

    return outs;
}

#endif // ACCOUNT_H_INCLUDED
