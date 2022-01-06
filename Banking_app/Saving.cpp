#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Saving.h"

float Saving::Savings(float balance)
{
	std::cout << "Would like to open a ISA account(y/n)\n";
	char User_input= 'o';
	while (User_input != 'y')
	{
		std::cin >> User_input;
		User_input = islower(User_input);
		if (User_input != 'y' && User_input != 'n')
		{
			std::cout << "please Input a valid answer:";
		}
		else if (User_input == 'n')
		{
			setIsa(false);
		}
		else
		{
			setIsa(true);
		}
	}
	if (getIsa() == false)
	{
		setIr(0.85);
		std::cout << "your Savings account has been made:";
	}
	else
	{
		setIr(1.15);
		std::cout << "your ISA account has been made:";
	}
	balance = 0;
}


bool Saving::getIsa()
{
	return ISA;
}

void Saving::setIsa(bool input)
{
	ISA = input;
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

