#include "saving_account.h"

const saving_account & saving_account::operator=(const saving_account & otheraccount)
{
	if (this != &otheraccount)
		this->copy_saving(otheraccount);
	return *this;
}

saving_account::~saving_account()
{
	this->destroy();
}

void saving_account::destroy()
{
	//nothing yet
	//delete this;
}

bool saving_account::overdraft_warning()
{
	char choise = ' ';
	system("clr");
	std::cout << "\n If you continue this transaction you will be charge for overdrafting \n will you like to continue? ";
	std::cout << " 'y' to continue and 'n' for cancel ";
	std::cin >> choise;
	while (choise != 'y' || choise != 'Y' || choise != 'n' || choise != 'N')
	{
		std::cout << "\n please enter y or n ";
		std::cin >> choise;
	}

	if (choise == 'y' || choise == 'Y')
		return true;
	else if (choise == 'n' || choise == 'N')
		return false;
	else
		std::cout << "\n enter the right choise";
	return false;
}

void saving_account::check_saving_account()
{
	std::cout << " \n you have $" << this->Balance << " in your account";
}

double saving_account::get_balance() const
{
	return this->Balance;
}

double saving_account::get_annual_interest() const
{
	return this->annual_interest;
}

void saving_account::set_balance(const double & amount)
{
	this->Balance = amount;
}

void saving_account::increment_count()
{
	count++;
}

bool saving_account::can_i_withdraw(const double& amount)
{
	if (this->Balance - amount - withdraw_fee >= 0)
		return true;
	else if (overdraft_warning())
		return true;
	else if (!overdraft_warning())
		return false;
	else return false;
}
saving_account::saving_account()
{
	this->Balance = 0.00;
	this->annual_interest = 0;
}

saving_account::saving_account(const saving_account & otheraccount)
{
	this->copy_saving(otheraccount);
}
void saving_account::initialization()
{
	this->Balance = 0;
	this->annual_interest = 0;
	this->count = 0;
}
void saving_account::copy_saving(const saving_account & otheraccount)
{
	this->annual_interest = otheraccount.annual_interest;
	this->Balance = otheraccount.Balance;
	//this->set_client(otheraccount.get_client());
	//this->myclient = otheraccount.myclient;
}
bool saving_account::withdraw(const double& amount)
{
	if (can_i_withdraw(amount))
	{
		Balance = Balance - amount - withdraw_fee;
		increment_count();
		return true;
	}
	else
		return false;

}

void saving_account::deposit(const double & amount)
{
	Balance =+ amount;
	increment_count();
}


