#include"checking_account.h"

void checking_account::copybank(const checking_account & otherbank)
{
	this->Balance = otherbank.Balance;
	this->count = otherbank.count;
}

const checking_account & checking_account::operator=(const checking_account & otherbank)
{
	if (this != &otherbank)
		this->copybank(otherbank);
	return *this;
}

checking_account::checking_account(const checking_account & otherbank)
{
	this->copybank(otherbank);
}

checking_account::checking_account() // default constructor
{
	Balance = 0;
	count = 0;
}


checking_account::checking_account(const double& amount)// constructor with parameter
{
	Balance = amount;
	increment_count();
}


bool checking_account::withdraw(const double & amount)// function to withdraw money, return true if money withdraw
{
	if (can_i_withdraw(amount))
	{
		Balance = Balance - amount;
		increment_count();
		return true;
	}

	else return false;
}
void checking_account::deposit(const double& amount)// function to deposit
{
	double temp = 0.0;
	temp = amount;
	temp = temp + this->Balance;
	this->Balance = temp;
	//this->Balance = this->Balance + amount;
	increment_count();
}
double checking_account::balance()const// function to return the current balance
{
	return Balance;
}

void checking_account::initialization()
{
	this->Balance = 0.0;
	this->count = 0;
}


void checking_account::set_account_number(const int & acn)
{
	this->Balance = acn;
}

void checking_account::set_balance(const double & bal)
{
	Balance += bal;
	//Balance = bal;
}

void checking_account::check_balance()// function to return to print out the current balance
{
	std::cout << "\n you have $" << this->Balance << " in your acount";
}
bool checking_account::can_i_withdraw(const double& amount)// function to check wether the is it possible to withdraw or not
{
	if (amount <= this->Balance)
		return true;
	else
	{
		std::cout << " \nAlert message, the amount is greather than your balance...\n";
		system("pause");
		return false;
	}
}

void checking_account::destroy()
{
	delete this;
}

void checking_account::increment_count() // function to incremment the count after every transaction
{
	count++;
}
