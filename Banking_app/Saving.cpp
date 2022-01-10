#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Saving.h"

Saving::Saving(float tempBalance, bool isISA)
{
	balance = tempBalance;
	if (isISA)
	{
		std::cout << "Your ISA account has been created:\n";
		setIr(1.15);
	}
	else 
	{
		std::cout << "Your savings account has been created:\n";
		setIr(0.85);
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
}

void Saving::withdraw(float amount)
{
	if (balance < 0)
	{
		std::cout << "There is not enough money in the savings account:\n";
	}
	else
	{
		balance -= amount;
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

void Saving::History()
{
	std::cout << "poggers";
}

std::string Saving::toString(std::string input)
{
	return input;
}

