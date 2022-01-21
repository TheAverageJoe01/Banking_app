#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Account.h"
// initalising functions and method for the current class

class Current :public Account
{
public:
	Current(float balance);
	void deposit(float amount);
	bool withdraw(float amount);
	float getbalance();
	void setbalance(float amount);
	std::string toString(std::string input);
	void History();
	float overdraft;
	std::string getacType();
	void setacType(std::string type);
private:
	std::string acType;
};
