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
	Saving();
	bool getIsa();
	void setIsa(bool input);
	float getIr();
	void setIr(float input);
	void deposit(float amount);
	void withdraw(float amount);
private:
	bool ISA;
	float interest_rate;

};
