#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Current.h"

float Current::accountCurrent(float balance)
{
	overdraft = 500;
	setActype("Current");
	std::cout << "Your current account has been created\n";
	overdraft = 500;
	std::cout << "overdraft: " << overdraft << "\n";
	return balance;
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
	if (balance - amount <= -500)
	{
		std::cout << "Exceeding overdraft:\n";

	}
	else
	{
		balance -= amount;
		Transaction transaction("Withdraw", amount);
		history.push_back(transaction);
		std::cout << "withdrawed amount\n";
	}
}