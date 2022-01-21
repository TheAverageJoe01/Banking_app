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
		setacType("saving");
	}
	else 
	{
		std::cout << "Your savings account has been created:\n";
		setIr(0.85);
		setacType("ISA");

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

void Saving::History()
{
	std::cout << "poggers";
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

void Saving::computeInterest(int amount, float interest_rate, float years)
{
	float projection;
	projection = pow(balance * (1 + (interest_rate / 12)), 12 * years);
}