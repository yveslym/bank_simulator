#pragma once
#include"checking_account.h"
#include"client_info.h"
#include"saving_account.h"


class bank_account
{
public:
	bank_account();// default constructor
	virtual ~bank_account();
	// overload assignment
	const bank_account& operator=(const bank_account& otherbank);

	//copy constructor
	bank_account(const bank_account& otherbank);

	// copy bank
	void copybank(const bank_account& otherbank);

private:
	client_info customer_info;
	checking_account checking;
	saving_account saving;
public:
	// constructor initialise bank account with checking,saving,and info parameter
	bank_account (const checking_account checking,const saving_account saving,const client_info info);

	// initialize with customer info
	bank_account(const client_info& info);
	// accessor method
	checking_account get_checking()const;
	saving_account get_saving()const;
	client_info get_customer_info()const;

	//mutator method
	void set_checking(const checking_account& other);
	void set_saving(const saving_account& other);
	void set_customer_info( client_info& other);

};

