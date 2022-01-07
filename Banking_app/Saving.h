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
	float Savings(float balance);
	float ISA(float balance);
	float getIr();
	void setIr(float input);
	void deposit(float amount);
	void withdraw(float amount);
private:
	float interest_rate;

};
