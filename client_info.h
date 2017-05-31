#pragma once
#ifndef client_info_H
#define client_info_H

#include<string>
class client_info
{
private:
	std::string first_name;
	std::string last_name;
	unsigned int account_number;

public:
	const client_info& operator=(const client_info& other_client);// overload assignment operator
	void copyclient(const client_info& other_client);// function to copy client
	client_info(const client_info& other_client); // copy constructor

	void destroy();// desttructor
	client_info();//default constructor
	void initialization();
	client_info(const std::string& fname, const std::string& lname); // initialisation with parameter for new client
	std::string get_first_name()const; //function to return first_name
	std::string get_last_name()const;//function to return last_name
	unsigned int get_Account_number() const;

	void set_first_name(const std::string fname); // function to set first-name
	void set_last_name(const std::string lname);// function to set last name
	void generate_account_number();// function to generate account number
	void set_account_number(const unsigned int& acn);
};

#endif
