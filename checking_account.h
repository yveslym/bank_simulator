

/*
1. Write your own simple
Account
class. You should be able to make deposits and withdrawals
and read out the balance — a private double variable. Member f
unctions should be:
void Account::withdraw(const double &amount); //Take fro
m account
void Account::deposit(const double &amount); // Put into a
ccount
double account::balance(void); //Return the balance
Make sure that the
Account
constructor function initialises the balance to zero. If you l
ike,
add an overloaded constructor function to set an initial balan
ce.
2. Modify your
Account
class so that it writes a record of every transaction into a file. Ma
ke
sure that you handle file opening and closing properly. If you hav
e multiple accounts where
will you write the transactions?
3. Write a derived class
DepositAccount
that inherits from the
Account
class. The account
should pay interest at an annual rate that is private member dat
a, but impose a
£
10 fee for
every withdrawal. You should overload the member functions o
f
Account
where necessary.
How will you determine when to pay interest?*/

#ifndef checking_account_H
#define checking_account_H

#include<iostream>
#include<fstream>
#include"client_info.h"

//declaration

class checking_account
{
private:
	double Balance;
	int count;
	


public:
	const checking_account& operator= (const checking_account& otherbank);
	void copybank(const checking_account& otherbank);
	checking_account(const checking_account& otherbank);// copy constructor

	checking_account();
	checking_account(const double& amount);
	//checking_account(const client_info& new_client);// initialisation with client info
	bool withdraw(const double& amount);// function to withdraw
	void deposit(const double& amount);// function to deposit
	void check_balance();
	double balance()const; //return the current balance
	void initialization();
	void set_account_number(const int& acn);
	void set_balance(const double& bal);
	void increment_count();	// incremment the count by one after any transaction
	bool can_i_withdraw(const double& amount); // check wether the amountasking to withdraw is not greater than the current balance
	void destroy();
};




#endif 

