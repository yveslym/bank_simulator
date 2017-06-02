#pragma once
#include<iostream>
//#include<fstream>
#include"checking_account.h"
#include"client_info.h"
#include"Saving_Account.h"
#include"database_file.h"
#include"Bank_account.h"

//using namespace record;
//using namespace user_interface;
//using namespace std;
namespace checking_operation
{
	void view_balance(bank_account& mybank);
	void withdraw_money(bank_account& mybank);
	void deposit(bank_account& mybank);
	void view_transaction();

}
namespace saving_operation
{
	void view_balance(bank_account& mybank);
	void withdraw_money(bank_account& mybank);
	void deposit(bank_account& mybank);
	void transaction(bank_account& mybank);
}
