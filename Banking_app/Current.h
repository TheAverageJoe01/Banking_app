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
	Current();
	float overdraft;
	void deposit(float amount);
	void withdraw(float amount);

};
