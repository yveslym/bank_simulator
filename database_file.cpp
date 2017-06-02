#include "database_file.h"

// namespace user_interface definition

void user_interface::checking_account(bank_account& mybank)
{
	system("cls");
	std::cout << " Hello " << mybank.get_customer_info().get_first_name() << "\n";
	std::cout << " Welcome back to your checking account.\n";
	std::cout << " choose operation to perform: ";
	std::cout << "\n 1. VIEW BALANCE \n 2. WITHDRAW \n 3. DEPOSIT \n 4. VIEW TRANSACTION \n 5. CHANGE THE ACCOUNT \n 6. LOGOUT\n";
	int choice = 0;
	std::cin >> choice;
	if (choice <= 0 && choice >= 5)
	{
		system("cls");
		std::cout << "\n your choice is not in the list...\n";
		checking_account(mybank);
	}

	switch (choice)
	{
	case 1: checking_operation::view_balance(mybank);
		break;
	case 2:checking_operation::withdraw_money(mybank);
		break;
	case 3:checking_operation::deposit(mybank);
		break;
	case 4:checking_operation::view_transaction();
		break;
	case 5: menu(mybank);
		break;
	case 6:std::cout << " logout success...\n thank you for using YVESLYM APP DEMO..\n";
		system("pause");
		logout();
		break;
	}

}
void user_interface::saving_Account(bank_account& mybank)
{
	system("cls");
	std::cout << " Hello " << mybank.get_customer_info().get_first_name() << "\n";
	std::cout << " Welcome back to your saving Account.\n";
	std::cout << " choose operation to perform: ";
	std::cout << "\n 1. VIEW BALANCE \n 2. WITHDRAW \n 3. DEPOSIT \n 4. VIEW TRANSACTION \n 5. CHANGE THE ACCOUNT \n 6. LOGOUT\n ";
	int choice = 0;
	std::cin >> choice;
	if (choice <= 0 && choice >= 5)
	{
		system("cls");
		std::cout << "\n your choice is not in the list...\n";
		std::system("pause");
		saving_Account(mybank);
	}

	switch (choice)
	{
	case 1: saving_operation::view_balance(mybank);
		break;
	case 2:saving_operation::withdraw_money(mybank);
		break;
	case 3:saving_operation::deposit(mybank);
		break;
	case 4:saving_operation::transaction(mybank);
		break;
	case 5: menu(mybank);
		break;
	case 6:
		std::cout << " logout success...\n thank you for using YVESLYM APP DEMO..\n";
		system("pause");
		logout();
		break;
}

}

void user_interface::intro()
{
	system("cls");
	std::cout << "\n register or login?\n r for register, l for login: ";
	char choise = ' ';
	std::cin >> choise;

		switch (choise)
		{
		case 'l':
		case 'L':login();
			break;
		case'r':
		case 'R':register_log();
			break;

		default:
			std::cout << "\n your choice wasn't accepted...\n";
			system("pause");
			intro();
			break;
		}
	}

void user_interface::check_connection(bank_account& mybank)
{
	if (record::SAV_exist(mybank) == true)
	{
		std::cout << " \nconnection to saving account database success...";
		sleep_for(milliseconds(3000));
	}
	else
	{
		std::cout << " not connection establish...\n wait while reconnecting... ";
		sleep_for(milliseconds(3000));
		record::update_SAV(mybank);
		if (record::SAV_exist(mybank) == true)
			std::cout << "\n connection updated...";
		else
			std::cout << "\n couldn't update checking account connection...\n";
	}
	if (record::CHE_exist(mybank) == true)
	{
		std::cout << " \nconnection to checking account database success...";
		sleep_for(milliseconds(3000));
	}
	else
	{
		std::cout << " not connection establish...\n wait while reconnecting... ";
		sleep_for(milliseconds(3000));
		record::update_CHE(mybank);
		if (record::CHE_exist(mybank) == true)
			std::cout << "\n connection updated...";
		else
			std::cout << "\n couldn't update checking account connection...\n";
		}

		menu(mybank);
}
int user_interface::logout()
{
	return 0;
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

	else { 
		std::string un = " ", pw = " ", fn = " ", ln = " ";
		std::ifstream get_f;

		get_f.open(fname + "_log.txt");

			get_f >> fn >> ln;

				client_info info(fn, ln);

				bank_account Mybank(info);

				if (record::CHE_exist(Mybank) && record::SAV_exist(Mybank))
				{
					Mybank = record::get_data_DB(Mybank);
				}
				else
				{
					record::update_CHE(Mybank);
					record::update_SAV(Mybank);
				}
		menu(Mybank); 
	}
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
	bank_account mybank(info);
	

	record::create_saving_DB(mybank);// create a new saving account database

	record::create_checking_DB(mybank);// create a new checking account database

	record::new_log(info, uname, pword);// create a new user login information
	menu(mybank);
}
void user_interface::menu(bank_account& mybank)
{
	system("cls");
	std::cout << " choose one of the option: \n";
	std::cout << " 1. CHECKING ACCOUNT\n 2. SAVING ACCOUNT\n 3. CHECK CONNECTION \n 4. LOGOUT\n";
	int choise = 0;
	std::cin >> choise;

		switch ((int)choise)
		{
		case 1:system("cls");
			checking_account(mybank);
			break;
		case 2:system("cls");
			saving_Account(mybank);
		case 3: system("cls");
			user_interface::check_connection(mybank);
			break;
		case 4:system("cls");
			std::cout << " logout success...\n thank you for using YVESLYM APP DEMO..\n";
			system("pause");
			logout();
			break;
		default:
			std::cout << "\n choose either 1, 2, 3, or 4\n";
			system("pause");
			menu(mybank);
			break;
		}
	
}


// namespace record definition

void record::create_checking_DB(bank_account& mybank)
{
	client_info info;
	info = mybank.get_customer_info();
	std::ofstream open_file;

	open_file.open(info.get_first_name() + info.get_last_name() + "CHE.txt");

	open_file << info.get_first_name() << " " << info.get_last_name() << " " << info.get_Account_number() << " " << mybank.get_checking().balance();
	//info.destroy();
}
void record::create_saving_DB(bank_account& mybank)
{
	client_info info;
	info = mybank.get_customer_info();

	std::ofstream open_file;

	open_file.open(info.get_first_name() + info.get_last_name() + "SAV.txt");

	open_file << mybank.get_saving().get_balance() <<"  "<<mybank.get_saving().get_annual_interest();
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
bool record::SAV_exist(bank_account & mybank)
{
	bool exist = false;
	std::ifstream open_f;
	client_info info(mybank.get_customer_info());
	open_f.open(info.get_first_name() + info.get_last_name() + "SAV.txt");

	if (open_f.is_open())
		exist = true;
	return exist;
}
bool record::CHE_exist(bank_account& mybank)
{

	bool exist = false;
	std::ifstream open_f;
	client_info info(mybank.get_customer_info());
	open_f.open(info.get_first_name() + info.get_last_name() + "CHE.txt");

	if (open_f.is_open())
		exist = true;
	return exist;
}
bank_account &record::get_data_DB(bank_account& mybank)
{
	if (record::CHE_exist(mybank) == true && record::SAV_exist(mybank) == true)
	{
		std::string fn = " ", ln = " "; unsigned int acn = 0;double balance_CHE = 0.0, balance_SAV = 0.0;
		double interest = 0.0;

		checking_account checking(mybank.get_checking());
		saving_account saving(mybank.get_saving());
		client_info info(mybank.get_customer_info());

		std::ifstream open_checking, open_saving;


		open_checking.open(info.get_first_name() + info.get_last_name() + "CHE.txt");

		open_saving.open(info.get_first_name() + info.get_last_name() + "SAV.txt");

		open_checking >> fn >> ln >> acn >> balance_CHE;
		open_saving >> balance_SAV >> interest;

		info.set_first_name(fn);info.set_last_name ( ln);

		
		mybank.set_customer_info(info);

		mybank.get_checking().set_account_number(acn);

		checking.set_balance(balance_CHE);
		
		saving.set_balance(balance_SAV);
		
		mybank.set_checking(checking);
		mybank.set_saving(saving);
	}
	return mybank;
}
void record::update_CHE(bank_account & mybank)
{
	std::ofstream open_file;
	client_info info;

	info = mybank.get_customer_info();
	open_file.open(info.get_first_name() + info.get_last_name() + "CHE.txt");
	open_file << info.get_first_name() << " " << info.get_last_name() << " " << info.get_Account_number() << " " << mybank.get_checking().balance();
	info.destroy();

}
void record::update_SAV(bank_account& mybank)
{
	std::ofstream open_file;
	client_info info(mybank.get_customer_info());
	saving_account saving(mybank.get_saving());
	
	open_file.open(info.get_first_name() + info.get_last_name() + "SAV.txt");
	open_file << saving.get_balance() << " " << saving.get_annual_interest();
	info.destroy();
}

