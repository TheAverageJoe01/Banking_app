#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Account.h"
#include "Interest_Earnings.h"


class Saving :public Interest_Earnings, public Account
{
public:
	Saving(float balance, bool isISA);
	float getIr();
	void setIr(float input);
	void deposit(float amount);
	void withdraw(float amount);
	float getbalance();
	void setbalance(float amount);
	std::string toString(std::string input);
	void History();
private:
	float interest_rate;

};
