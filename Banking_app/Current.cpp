#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Current.h"

Current::Current()
{
	overdraft = 500;
	setActype("Current");
	std::cout << "Your current account has been created\n";
}

void Current::deposit(float amount)
{
	if (overdraft == 500)
	{
		balance += amount;
	}
	else
	{
		overdraft += amount;
		if (overdraft > 500)
		{
			float t_amount = overdraft - 500;
			overdraft = 500;
			balance += t_amount;
		}
	}
	Transaction transaction("Deposit", amount);
	history.push_back(transaction);
	std::cout << "Deposited Money\n";
}

void Current::withdraw(float amount)
{
	if (balance < 0)
	{
		std::cout << "do you want to go into your overdraft y/n:\n";
		char User_input = 'o';
		while (User_input != 'y')
		{
			std::cin >> User_input;
			User_input = islower(User_input);
			if (User_input != 'y' && User_input != 'n')
			{
				std::cout << "please Input a valid answer:\n";
			}
			else if (User_input == 'n')
			{
				std::cout << "Withdrawl cancelled\n";
			}
			else
			{
				if (overdraft - amount < 0)
				{
					std::cout << "You do not have enough overdraft to cover this withdrawl:\n";
				}
				else
				{
					overdraft -= amount;
				}
			}
		}
	}
	else
	{
		balance -= amount;
	}
	Transaction transaction("Withdraw", amount);
	history.push_back(transaction);
	std::cout << "withdrawed amount\n";
}