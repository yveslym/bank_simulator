#include "Bank_account.h"

bank_account::bank_account()
{
	this->customer_info.initialization();
	this->checking.initialization();
	this->saving.initialization();
}


bank_account::~bank_account()
{
	//delete this;
}

const bank_account & bank_account::operator=(const bank_account & otherbank)
{
	if (this != &otherbank)
		this->copybank(otherbank);
	return *this;
}

bank_account::bank_account(const bank_account & otherbank)
{
	this->copybank(otherbank);
}

void bank_account::copybank(const bank_account & otherbank)
{
	this->checking = otherbank.checking;
	this->saving = otherbank.saving;
	this->customer_info = otherbank.customer_info;
}

// constructor initialise bank account with checking,saving,and info parameter
bank_account::bank_account(checking_account checking, saving_account saving, client_info info)
{
	this->checking = checking;
	this->saving = saving;
	this->customer_info = info;
}

bank_account::bank_account(const client_info & info)
{
	this->customer_info = info;
	this->checking.initialization();
	this->saving.initialization();
}

checking_account bank_account::get_checking() const
{
	return this->checking;
}

saving_account bank_account::get_saving() const
{
	return this->saving;
}

client_info bank_account::get_customer_info() const
{
	return this->customer_info;
}

void bank_account::set_checking(const checking_account & other)
{
	this->checking = other;
}

void bank_account::set_saving(const saving_account & other)
{
	this->saving = other;
}

void bank_account::set_customer_info( client_info & other)
{
	this->customer_info.copyclient(other);
}



