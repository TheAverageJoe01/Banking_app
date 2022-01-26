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
	bool withdraw(float amount);
	float getbalance();
	void setbalance(float amount);
	std::string toString(std::string input);
	void showHistory();
	std::string getacType();
	void setacType(std::string type);
	float computeInterest( float years);
	void add_history(Transaction transaction);
	void searchTransaction(float amount);
private:
	float interest_rate;
	float overdraft;
	std::string acType;
};
