#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
// initalising functions and method for the Interest class

class Interest_Earnings
{
public:
	virtual float computeInterest(float year) = 0;
};
