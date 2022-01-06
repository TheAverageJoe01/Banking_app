#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include "Transaction.h"
// initalising functions and method for the account class 

class Account
{
public:
	std::string toString(float input);
	virtual void deposit(float amount) = 0;// expecting no return 
	virtual void withdraw(float amount) = 0;// making a pure virtual function 
	std::string getAcname();
	void setAcname(std::string input);
	int getAcnumber();
	void setAcnumber();
	std::string getActype();
	void setActype(std::string input);
	void History();

	Account();
protected:// to be inherited in other classes 
	float balance;
	std::vector <Transaction> history;
private:
	std::string acname;
	int acnumber;
	std::string actype;
};
