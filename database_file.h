
#ifndef client_file_H
#define client_file_H

#include<iostream>
#include<fstream>
#include"checking_account.h"
#include"client_info.h"
#include"Saving_Account.h"
#include"bank_operation.h"
#include"Bank_account.h"
#include<cstdlib>
#include<chrono>
#include<thread>


using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

//using namespace debit_operation;

//static bank_account *client_checking = new bank_account;
//static saving_account *client_saving = new saving_account;

namespace record
{
	//static bank_account mybank;

	void create_checking_DB(bank_account& mybank);//function to create a new customer
	void create_saving_DB(bank_account &mybank);
	void update_SAV(bank_account& mybank);
	void update_CHE(bank_account& mybank);
	void new_log(client_info& info, std::string& un, std::string& pw);
	
	bool check_login(std::string& uname, std::string pword);
	
	bool SAV_exist(bank_account& mybank);	// check wether the saving database exist
	bool CHE_exist(bank_account& mybank);// check wether the checking data base exist
	bank_account & get_data_DB(bank_account& mybank);// retrieve data from database
	
}

namespace user_interface
{
	void checking_account(bank_account& mybank);
	void saving_Account(bank_account& mybank);
	void menu(bank_account &mybank);
	void register_log();
	void login();
	void intro();
	void check_connection(bank_account& mybank);
	int logout();
}

#endif // !client_file_H