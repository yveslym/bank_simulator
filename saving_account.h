#ifndef saving_account_H
#define saving_account_H
#include<iostream>

// class saving account derivate class of bank_account class

class saving_account
{
private:
	const double withdraw_fee = 10.00; // fee for every withdrawal
	double annual_interest;
	double Balance;
	int count;

public:
	const saving_account& operator=(const saving_account& otheraccount);// overload assignment operator
	virtual ~saving_account();
	void destroy();
	saving_account();// default constructor
	//saving_account(const client_info& info);// initialise with client info data
	saving_account(const saving_account& otheraccount);//coppy constructor

	void initialization();
	void copy_saving(const saving_account& otheraccount);// copy othe account
	bool withdraw(const double& amount);// overload withdraw that add withdraw fee for every transaction
	void deposit(const double&amount);
	bool can_i_withdraw(const double& amount);// check wether the withdraw does not go over draft, and prompt the user if it is the case
	bool overdraft_warning(); //warning the user about the overdraft and prompt him to choose to continue or nah.
	void check_saving_account();
	double get_balance()const;
	double get_annual_interest()const;
	void set_balance(const double& amount);
	void increment_count();
};
#endif
