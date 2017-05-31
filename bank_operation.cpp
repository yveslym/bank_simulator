#include "bank_operation.h"

// checking operation declaration

void checking_operation::deposit(bank_account& client)
{
	double amount = 0.0;
	system("cls");
	std::cout << " \n Enter your amount, muliple of 10: ";
	std::cin >> amount;

	if (amount < 10.00)
	{
		std::cout << " \nthis amount is less than 10 and cannot be takken\n";
		system("pause");
		user_interface::checking_account();
	}
	else if (amount > 10000.00)
	{
		std::cout << "\nThis amount is more than the daily maximun deposit\n";
		system("pause");
		user_interface::checking_account();
	}
	else if (amount > 10.00 || amount < 10000.00)
	{
		client.get_checking().deposit(amount);
		

		record::update_CHE(client);
		std::cout << "\n deposit succesful..\n";
		system("pause");
		user_interface::checking_account();
	}
	else
	{
		std::cout << " \nInput not valid \n";
		system("pause");
		user_interface::checking_account();
	}
	record::update_CHE(client);
}
void checking_operation::view_balance(bank_account clientr)
{
	client_info info(clientr.get_customer_info());
	system("cls");
	std::cout << "\t\t\t BALANCE\n";
	std::cout << info.get_first_name() << " " << info.get_last_name();
	clientr.get_checking().check_balance();
	std::cout << std::endl;
	system("pause");
	user_interface::checking_account();

}
void checking_operation::view_transaction()
{
	//nothing yet
}
void checking_operation::withdraw_money(bank_account & client)
{
	double amount;
	std::cout << " \n please enter the amount: ";
	std::cin >> amount;

	if (amount <= 10.00 || amount >= 1000.00)
	{
		std::cout << "\n the amount entered is incorect\n";
		system("pause");
		user_interface::checking_account();
	}
	else
	{
		if (client.get_checking().withdraw(amount) == true)
		{
			std::cout << "\nwithdraw succesful...";
			system("pause");
			record::update_CHE(client);
			user_interface::checking_account();
		}
		else
			user_interface::checking_account();
	}
}

// saving operation declaration

void saving_operation::deposit(bank_account& client)
{
	double amount = 0.0;
	system("clr");
	std::cout << " \n Enter your amount, muliple of 10: ";
	std::cin >> amount;

	if (amount < 10.00)
	{
		std::cout << " \nthis amount is less than 10 and cannot be takken\n";
		system("pause");
		user_interface::saving_Account();
	}
	else if (amount > 10000.00)
	{
		std::cout << "\nThis amount is more than the daily maximun deposit\n";
		system("pause");
		user_interface::saving_Account();
	}
	else if (amount > 10.00 || amount < 10000.00)
	{
		client.get_saving().deposit(amount);
		std::cout << "\n deposit succesful..\n";
		system("pause");
		user_interface::saving_Account();
	}
	else
	{
		std::cout << " \nInput not valid \n";
		system("pause");
		user_interface::saving_Account();
	}
	record::update_SAV(client);
}
void saving_operation::view_balance(bank_account & client)
{
	client_info info;
	info.copyclient(client.get_customer_info());
	system("cls");
	std::cout << "\t\t\t BALANCE\n";
	std::cout << info.get_first_name() << " " << info.get_last_name() << " \n balance: $"<<  client.get_saving().get_balance();
	system("pause");
	user_interface::saving_Account();
}
void saving_operation::withdraw_money(bank_account& client)
{
	double amount;
	std::cout << " \n please enter the amount: ";
	std::cin >> amount;

	if (amount <= 10.00 || amount >= 1000.00)
	{
		std::cout << "\n the amount entered is incorect\n";
		system("pause");
		user_interface::saving_Account();
	}
	else if (client.get_saving().withdraw(amount) == true)
		{
			std::cout << "\nwithdraw succesful...\n";
			system("pause");
			record::update_SAV(client);
			user_interface::saving_Account();
		}
		else
			user_interface::saving_Account();
	}

void saving_operation::transaction()
{
	//nothing yet
}

