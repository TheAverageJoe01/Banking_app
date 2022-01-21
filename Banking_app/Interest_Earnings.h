#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
// initalising functions and method for the Interest class

class Interest_Earnings
{
public:
	virtual void computeInterest(int amount, float interest_rate, float year) = 0;
};
