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
	setacType("current");
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
	add_history(transaction);
	std::cout << "Deposited Money\n";
}

bool Current::withdraw(float amount)
{
	if (balance - amount <= -500)
	{
		std::cout << "Exceeding overdraft:\n";
		return false;

	}
	else
	{
		balance -= amount;
		Transaction transaction("Withdraw", amount);
		add_history(transaction);
		std::cout << "withdrew amount\n";
		return true;
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

void Current::showHistory()
{
	for (Transaction trans : history)
	{
		std::cout << trans.toString();
	}
}

std::string Current::toString(std::string input)
{
	return input;
}

void Current::setacType(std::string type)
{
	acType = type;
}


std::string Current::getacType()
{
	return acType;
}

void Current::add_history(Transaction transaction)
{
	history.push_back(transaction);
}
