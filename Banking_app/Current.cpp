#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Current.h"

Current::Current(float tempBalance)
{
	std::cout << "Your current account has been created\n";
	overdraft = 500;
	balance = tempBalance;
	std::cout << "overdraft: " << overdraft << "\n";
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

float Current::getbalance()
{
	return balance;
}

void Current::setbalance(float amount)
{
	balance = amount;
}

void Current::History()
{
	std::cout << "poggers";
}

std::string Current::toString(std::string input)
{
	return input;
}