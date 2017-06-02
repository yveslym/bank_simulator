#include "bank_operation.h"

// checking operation declaration

void checking_operation::deposit(bank_account& mybank)
{
	double amount = 0.0;
	system("cls");
	std::cout << " \n Enter your amount, muliple of 10: ";
	std::cin >> amount;

	if (amount < 10.00)
	{
		std::cout << " \nthis amount is less than 10 and cannot be takken\n";
		system("pause");
		user_interface::checking_account(mybank);
	}
	else if (amount > 10000.00)
	{
		std::cout << "\nThis amount is more than the daily maximun deposit\n";
		system("pause");
		user_interface::checking_account(mybank);
	}
	else if (amount > 10.00 || amount < 10000.00)
	{
		checking_account checking(mybank.get_checking());
		checking.set_balance(amount);
		mybank.set_checking(checking);
		

		record::update_CHE(mybank);
		std::cout << "\n deposit succesful..\n";
		system("pause");
		user_interface::checking_account(mybank);
	}
	else
	{
		std::cout << " \nInput not valid \n";
		system("pause");
		user_interface::checking_account(mybank);
	}
	record::update_CHE(mybank);
}
void checking_operation::view_balance(bank_account& mybank)
{
	client_info info(mybank.get_customer_info());
	checking_account checking(mybank.get_checking());
	system("cls");
	std::cout << "\t\t\t BALANCE\n";
	std::cout << info.get_first_name() << " " << info.get_last_name() << std::endl;
	std::cout << " your balance is: $" << checking.balance();
	
	std::cout << std::endl;
	system("pause");
	user_interface::checking_account(mybank);

}
void checking_operation::view_transaction()
{
	//nothing yet
}
void checking_operation::withdraw_money(bank_account& mybank)
{
	double amount;
	checking_account checking(mybank.get_checking());
	system("cls");
	std::cout << " \n please enter the amount: ";
	std::cin >> amount;

	if (amount <= 10.00 || amount >= 1000.00)
	{
		std::cout << "\n the amount entered is incorect\n";
		system("pause");
		user_interface::checking_account(mybank);
	}
	else
	{
		if (checking.withdraw(amount) == true)
		{
			std::cout << "\nwithdraw succesful...\n";
			system("pause");
			mybank.set_checking(checking);
			record::update_CHE(mybank);
			user_interface::checking_account(mybank);
		}
		else
			user_interface::checking_account(mybank);
	}
}

// saving operation declaration

void saving_operation::deposit(bank_account& mybank)
{
	double amount = 0.0;
	system("cls");
	std::cout << " \n Enter your amount, muliple of 10: ";
	std::cin >> amount;

	if (amount < 10.00)
	{
		std::cout << " \nthis amount is less than 10 and cannot be takken\n";
		system("pause");
		user_interface::saving_Account(mybank);
	}
	else if (amount > 10000.00)
	{
		std::cout << "\n you can only deposit less than $1000 at time\n";
		system("pause");
		user_interface::saving_Account(mybank);
	}
	else if (amount > 10.00 || amount < 10000.00)
	{
		saving_account saving(mybank.get_saving());
		saving.deposit(amount);
		std::cout << "\n deposit succesful..\n";
		system("pause");
		mybank.set_saving(saving);
		record::update_SAV(mybank);
		user_interface::saving_Account(mybank);
	}
	else
	{
		std::cout << " \nInput not valid \n";
		system("pause");
		user_interface::saving_Account(mybank);
	}
	record::update_SAV(mybank);
}
void saving_operation::view_balance(bank_account& mybank)
{
	mybank = record::get_data_DB(mybank);// get the latest data in the file

	saving_account saving(mybank.get_saving());
	client_info info(mybank.get_customer_info());

	system("cls");
	std::cout << "\t\t\t BALANCE\n";
	std::cout << info.get_first_name() << " " << info.get_last_name() << " \n balance: $"<<  saving.get_balance();
	system("pause");

	user_interface::saving_Account(mybank);
}
void saving_operation::withdraw_money(bank_account& mybank)
{
	double amount;
	saving_account saving(mybank.get_saving());
	system("cls");
	std::cout << " \n please enter the amount: ";
	std::cin >> amount;

	if (amount <= 10.00 || amount >= 1000.00)
	{
		std::cout << "\n the amount entered is incorect\n";
		system("pause");
		user_interface::saving_Account(mybank);
	}
	else
	{
		if (saving.withdraw(amount) == true)
		{
			std::cout << "\nwithdraw succesful...\n";
			system("pause");
			mybank.set_saving(saving);
			record::update_SAV(mybank);
			user_interface::saving_Account(mybank);
		}
		else
			user_interface::saving_Account(mybank);
	}
}
void saving_operation::transaction(bank_account& mybank)
{
	//nothing yet
}

