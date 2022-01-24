#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <vector>
#include <string.h>
#include <ctime>
#include <iostream>

#include "Transaction.h"


Transaction::Transaction(std::string Input_Descr, float Input_value)
{
	setDescr(Input_Descr);
	setValue(Input_value);
	setTimeStamp();
}

// return input as a string 
std::string Transaction::toString()
{
	std::string ret = getDescr() + std::to_string(getValue()) + getTimeStamp();
	return ret;
}
// returns description 
std::string Transaction::getDescr()
{
	return descr;
}
void Transaction::setDescr(std::string input)
{
	descr = input;
}

char Transaction::getTimeStamp()
{
	return timeStamp;
}

void Transaction::setTimeStamp()
{
	time_t timeStamp = time(0);
	char* time = ctime(&timeStamp);
}

float Transaction::getValue()
{
	return value;

}

void Transaction::setValue(float input)
{
	value = input;
}

