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
	
	virtual void deposit(float amount) = 0;// expecting no return 
	virtual bool withdraw(float amount) = 0;// making a pure virtual function 
	virtual float getbalance() = 0;
	virtual void setbalance(float amount) = 0;
	virtual std::string toString(std::string input) = 0;
	virtual void History() = 0;
protected:// to be inherited in other classes 
	float balance;
	std::vector <Transaction> history;
};
