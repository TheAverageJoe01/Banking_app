#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Saving.h"

float Saving::Savings(float balance)
{
	setActype("Savings");
	std::cout << "Your savings account has been created:\n";
	setIr(0.85);
	return balance;
}

float Saving::ISA(float balance)
{
	setActype("ISA");
	std::cout << "Your ISA account has been created:\n";
	setIr(1.15);
	return balance;
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

