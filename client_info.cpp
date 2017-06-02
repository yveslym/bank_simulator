#include"client_info.h"
const client_info & client_info::operator=(const client_info & other_client)
{
	if (this != &other_client)
		copyclient(other_client);
	return *this;
}
void client_info::copyclient(const client_info & other_client)
{

	this->first_name = other_client.first_name;
	this->last_name = other_client.last_name;
	this->account_number = other_client.account_number;
}
client_info::client_info(const client_info & other_client)
{
	this->copyclient(other_client);
}
void client_info::destroy()
{
	// nothing here delete this;
}
client_info::client_info()
{
	first_name = " ";
	last_name = " ";
	this->account_number = 0;
}

void client_info::initialization()
{
	this->account_number = 0;
	this->first_name = " ";
	this->last_name = " ";
}

client_info::client_info(const std::string& fname, const std::string& lname)
{
	first_name = fname;
	last_name = lname;
	generate_account_number();
}
std::string client_info::get_first_name()const
{
	return first_name;
}
std::string client_info::get_last_name()const
{
	return last_name;
}
unsigned int client_info::get_Account_number()const
{
	return account_number;
}
void client_info::set_first_name(const std::string fname)
{
	first_name = fname;
}
void client_info::set_last_name(const std::string lname)
{
	last_name = lname;
}
void client_info::generate_account_number()
{

}

void client_info::set_account_number(const unsigned int& acn)
{
	this->account_number = acn;
}
