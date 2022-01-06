#include <iostream>
#include <sstream>
#include <vector>
#include <ostream>
#include <string.h>

#include"Account.h"




void Account::History()
{
	if (history.size() == 0)
	{
		std::cout << "There is no Transaction history:\n";
	}
	else
	{
		for (int i = 0; i < history.size(); i++)
		{
			std::cout << i << " \n";
		}

	}
}

std::string Account::toString(float input)
{
	return std::to_string(input);
}

std::string Account::getAcname()
{
	return acname;
}

void Account::setAcname(std::string input)
{
	acname = input;
}

int Account::getAcnumber()
{
	return  acnumber;
}

void Account::setAcnumber()
{
	acnumber = 6;
}

std::string Account::getActype()
{
	return actype;
}

void Account::setActype(std::string input)
{
	actype = input;
}

Account::Account()
{
	balance = 0;
	std::string t_name;
	std::cout << "account name:";
	std::cin >> t_name;
	setAcname(t_name);
	setAcnumber();
}
