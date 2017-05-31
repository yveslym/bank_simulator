#include "database_file.h"

// namespace user_interface definition

void user_interface::checking_account()
{
	system("cls");
	std::cout << " choose operation to perform: ";
	std::cout << "\n 1. VIEW BALANCE \n 2. WITHDRAW \n 3. DEPOSIT \n 4. VIEW TRANSACTION \n 5. CHANGE THE ACCOUNT \n ";
	int choice = 0;
	std::cin >> choice;
	if (choice <= 0 && choice >= 5)
	{
		system("cls");
		std::cout << "\n your choice is not in the list...\n";
		checking_account();
	}

	switch (choice)
	{
	case 1: checking_operation::view_balance(*record::mybank);
		break;
	case 2:checking_operation::withdraw_money(*record::mybank);
		break;
	case 3:checking_operation::deposit(*record::mybank);
		break;
	case 4:checking_operation::view_transaction();
		break;
		case 5: menu();
		break;
	}

}
void user_interface::saving_Account()
{
	system("cls");
	std::cout << " choose operation to perform: ";
	std::cout << "\n 1. VIEW BALANCE \n 2. WITHDRAW \n 3. DEPOSIT \n 4. VIEW TRANSACTION \n 5. CHANGE THE ACCOUNT \n ";
	int choice = 0;
	std::cin >> choice;
	if (choice <= 0 && choice >= 5)
	{
		system("cls");
		std::cout << "\n your choice is not in the list...\n";
		std::system("pause");
		checking_account();
	}

	switch (choice)
	{
	case 1: saving_operation::view_balance(*record::mybank);
		break;
	case 2:saving_operation::withdraw_money(*record::mybank);
		break;
	case 3:saving_operation::deposit(*record::mybank);
		break;
	case 4:saving_operation::transaction();
		break;
		//		case 5:helper::return_menu();
		//break;

	}

}
void user_interface::intro()
{
	system("cls");
	std::cout << "\n register or login?\n r for register, l for login: ";
	char choise = ' ';
	std::cin >> choise;
	if (choise == 'l' || choise == 'L' || choise == 'r' || choise == 'R')
	{
		switch (choise)
		{
		case 'l':
		case 'L':login();
			break;
		case'r':
		case 'R':register_log();
			break;
		}
	}
	else
	{
		std::cout << "\n your choice wasn't accepted...";
		system("pause");
		intro();
	}

}
void user_interface::check_connection()
{
	if (record::SAV_exist(*record::mybank) == true)
	{
		std::cout << " \nconnection to saving account database success...";
		sleep_for(milliseconds(5000));
	}
	else
	{
		std::cout << " not connection establish...\n wait while reconnecting... ";
		sleep_for(milliseconds(5000));
		record::update_SAV(*record::mybank);
		if (record::SAV_exist(*record::mybank) == true)
			std::cout << "\n connection updated...";
		else
			std::cout << "\n couldn't update checking account connection...\n";
	}
	if (record::CHE_exist(*record::mybank) == true)
	{
		std::cout << " \nconnection to checking account database success...";
		sleep_for(milliseconds(5000));
	}
	else
	{
		std::cout << " not connection establish...\n wait while reconnecting... ";
		sleep_for(milliseconds(5000));
		record::update_CHE(*record::mybank);
		if (record::CHE_exist(*record::mybank) == true)
			std::cout << "\n connection updated...";
		else
			std::cout << "\n couldn't update checking account connection...\n";
		}

		menu();
}
void user_interface::login()
{
	std::string fname = " ";
	std::string pword = " ";
	bank_account client;
	std::cout << "\n Please, Enter your username: "; std::cin >> fname;
	std::cout << "\n Please, Enter your password: "; std::cin >> pword;


	if (record::check_login(fname, pword) == false)
	{
		std::cout << "\nthose info is not matching the record ";
		intro();
	}
	else menu();
}
void user_interface::register_log()
{
	std::string fname = "";
	std::string lname = " ";
	std::string uname = "";
	std::string pword = " ";


	std::cout << "\n Please, Enter your first name: "; std::cin >> fname;
	std::cout << "\n Please, Enter your Last name: "; std::cin >> lname;
	std::cout << "\n Please, Enter username: "; std::cin >> uname;
	std::cout << "\n Please, Enter password: "; std::cin >> pword;

	
	client_info info(fname, lname);

	record::mybank->set_customer_info(info);

	record::create_saving_DB(*record::mybank);// create a new saving account database

	record::create_checking_DB(*record::mybank);// create a new checking account database

	record::new_log(info, uname, pword);// create a new user login information
	menu();
}
void user_interface::menu()
{
	system("cls");
	std::cout << " choose one of the option: \n";
	std::cout << " 1. DEBIT ACCOUNT\n 2. SAVING ACCOUNT\n 3. CHECK CONNECTION \n 4. LOGOUT\n";
	int choise = 0;
	std::cin >> choise;
	if (choise == 1 || choise == 2 || choise == 3 || choise == 4)
	{
		switch (choise)
		{
		case 1:system("cls");
			checking_account();
			break;
		case 2:system("cls");
			saving_Account();
		case 3: system("cls");
			user_interface::check_connection();
			break;
		case 4:system("cls");
			std::cout << " logout success...\n thank you for using YVESLYM APP DEMO..";
			system("pause");
		}
	}
	else
	{
		std::cout << "\n choose either 1, 2, 3, or 4\n";
		system("pause");
		menu();
	}
}


// namespace record definition

void record::create_checking_DB(bank_account & new_account)
{
	client_info info;
	info = new_account.get_customer_info();
	std::ofstream open_file;

	open_file.open(info.get_first_name() + info.get_last_name() + "CHE.txt");

	open_file << info.get_first_name() << " " << info.get_last_name() << " " << info.get_Account_number() << " " << new_account.get_checking().balance();
	//info.destroy();
}
void record::create_saving_DB(bank_account& new_account)
{
	client_info info;
	info = new_account.get_customer_info();

	std::ofstream open_file;

	open_file.open(info.get_first_name() + info.get_last_name() + "SAV.txt");

	open_file << new_account.get_saving().get_balance() <<"  "<<new_account.get_saving().get_annual_interest();
	open_file.close();
	//info.destroy();
}
bool record::check_login(std::string& uname, std::string pword)
{
	std::string un = " ", pw = " ", fn = " ", ln = " ";
	std::ifstream get_f;
	
	
	bool login = false;

	get_f.open(uname + "_log.txt");

	if (!get_f.is_open())
	{
		std::cout << "\ncouldn't open the database";
	}
	else
	{
	get_f >> fn >> ln >> un >> pw;

	if (un == uname && pw == pword)
	{
		login = true;
		client_info info(fn, ln);

		mybank->set_customer_info(info);

		*mybank = record::get_data_DB(*mybank);

	}		
}
	return login;
};
void record::new_log(client_info& info, std::string& un, std::string& pw)
{
	std::ofstream sample;
	std::ofstream new_user;
	new_user.open(un + "_log.txt");
	new_user << info.get_first_name() << " " << info.get_last_name() << " " << un << " " << pw;

	new_user.close();
}
bool record::SAV_exist(bank_account & bank)
{
	bool exist = false;
	std::ifstream open_f;
	client_info info(bank.get_customer_info());
	open_f.open(info.get_first_name() + info.get_last_name() + "SAV.txt");

	if (open_f.is_open())
		exist = true;
	return exist;
}
bool record::CHE_exist(bank_account & bank)
{

	bool exist = false;
	std::ifstream open_f;
	client_info info(bank.get_customer_info());
	open_f.open(info.get_first_name() + info.get_last_name() + "CHE.txt");

	if (open_f.is_open())
		exist = true;
	return exist;
}
bank_account record::get_data_DB(bank_account & bank)
{
	if (record::CHE_exist(bank) == true && record::SAV_exist(bank) == true)
	{
		std::string fn = " ", ln = " "; unsigned int acn = 0;double balance_CHE = 0.0, balance_SAV = 0.0;
		double interest = 0.0;
		std::ifstream open_checking, open_saving;
		client_info info(bank.get_customer_info());
		open_checking.open(info.get_first_name() + info.get_last_name() + "CHE.txt");
		open_saving.open(info.get_first_name() + info.get_last_name() + "SAV.txt");

		open_checking >> fn >> ln >> acn >> balance_CHE;
		open_saving >> balance_SAV >> interest;

		info.set_first_name(fn);info.set_last_name ( ln);

		if (fn != " " && ln != " ")
			bank.set_customer_info(info);
		bank.get_checking().set_account_number(acn);
		bank.get_checking().get_balance(balance_CHE);
		bank.get_saving().set_balance(balance_SAV);
	
	}
	return bank;
}
void record::update_CHE(bank_account& update)
{
	std::ofstream open_file;
	client_info info;

	info = update.get_customer_info();
	open_file.open(info.get_first_name() + info.get_last_name() + "CHE.txt");
	open_file << info.get_first_name() << " " << info.get_last_name() << " " << info.get_Account_number() << " " << update.get_checking().balance();
	info.destroy();

}
void record::update_SAV(bank_account& update)
{
	std::ofstream open_file;
	client_info info;

	info = update.get_customer_info();
	open_file.open(info.get_first_name() + info.get_last_name() + "SAV.txt");
	open_file << info.get_first_name() << " " << info.get_last_name() << " " << info.get_Account_number() << " " << update.get_saving().get_balance();
	info.destroy();
}

