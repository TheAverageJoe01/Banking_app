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
	Transaction transaction("--Deposit", amount);
	std::cout << "Deposited Money\n";
	add_history(transaction);
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
		Transaction transaction("--Withdraw", amount);
		std::cout << "withdrew amount\n";
		add_history(transaction);
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
	for (Transaction transaction : history)
	{
		std::cout << transaction.toString();
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


void Current::searchTransaction(float amount)// using a bubble sort for stretch task
{
	std::vector<Transaction>SortHistory(history);
	for (int x = 0; x < SortHistory.size() - 1; x++)
	{
		for (int i = 0; i < SortHistory.size() - 1; i++)
		{
			if (SortHistory[i].getValue() > SortHistory[i + 1].getValue())
			{
				Transaction temp = SortHistory[i];
				SortHistory[i] = SortHistory[i + 1];
				SortHistory[i + 1] = temp;
			}
		}
	}
	int low = 0;//binary search
	int high = SortHistory.size() - 1;
	bool isfound = false;
	while (low <= high)
	{
		int mid = (high + low) / 2;

		if (SortHistory[mid].getValue() == amount)
		{
			std::cout << "value found:";
			isfound = true;
		}


		if (SortHistory[mid].getValue() < amount)
		{
			low = mid + 1;
		}

		else
		{
			high = mid - 1;
		}

		if (isfound == false)
		{
			std::cout << "value is not found:";
		}
	}
}