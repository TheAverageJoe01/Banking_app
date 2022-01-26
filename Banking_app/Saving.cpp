#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <math.h>
#include "Saving.h"

Saving::Saving(float tempBalance, bool isISA)//isISA boolean to determine whcih account is made in main
{
	balance = tempBalance;
	if (isISA)
	{
		std::cout << "Your ISA account has been created:\n";
		setIr(1.15);//sets interest rate
		setacType("ISA");
	}
	else 
	{
		std::cout << "Your savings account has been created:\n";
		setIr(0.85);
		setacType("savings");

	}
}


float Saving::getIr()
{
	return interest_rate;
}

void Saving::setIr(float input)
{
	interest_rate = input;
}


void Saving::deposit(float amount)
{
	balance += amount;
	std::cout << "Deposited Money\n";
	Transaction transaction("--deposit", amount);
	add_history(transaction);// adds to history
}

bool Saving::withdraw(float amount)
{
	if (balance-amount < 0)
	{
		std::cout << "There is not enough money in the savings account:\n";
		return false;
	}
	else
	{
		balance -= amount;
		std::cout << "withdrew amount\n";
		Transaction transaction("--Withdraw", amount);
		add_history(transaction);
		return true;
	}
}
float Saving::getbalance()
{
	return balance;
}

void Saving::setbalance(float amount)
{
	balance = amount;
}

void Saving::showHistory()
{
	for (Transaction transaction : history)//runs through history vector and prints it out
	{
		std::cout << transaction.toString();
	}
}

std::string Saving::toString(std::string input)
{
	return input;
}


void Saving::setacType(std::string type)
{
	acType = type;
}


std::string Saving::getacType()
{
	return acType;
}

float Saving::computeInterest(float years)
{
	float projection;
	projection = balance * pow((1 + (interest_rate / 100)), years); // calcualtes projection 
	return projection;
}

void Saving::add_history(Transaction transaction)
{
	history.push_back(transaction);
}

void Saving::searchTransaction( float amount)// using a bubble sort for stretch task
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
	int low = 0;// using a binary search 
	int high = SortHistory.size() - 1;
	bool isfound = false;
	while (low <= high)
	{
		int mid = (high + low) / 2;

		if (SortHistory[mid].getValue() == amount) // checks to see if the value is in the middle index
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
			std::cout << "value is not found:";// if user inputs value that could not be found 
		}
	}
}