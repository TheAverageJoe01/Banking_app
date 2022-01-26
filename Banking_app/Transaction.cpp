#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <vector>
#include <string.h>
#include <iostream>
#include <chrono>
#include <iostream>

#include "Transaction.h"


Transaction::Transaction(std::string Input_Descr, float Input_value)
{
	setDescr(Input_Descr);
	setValue(Input_value);
	timeStamp = TimeStamp();
}

// return input as a string 
std::string Transaction::toString()// turning the stored history into a string
{
	std::string ret = getDescr() +":" + " " + std::to_string(getValue()) +" " + "on" + " " + timeStamp;
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

std::string Transaction::TimeStamp()
{
	std::time_t newTimeStamp = std::time(nullptr);
	timeStamp = std::asctime(std::localtime(&newTimeStamp));// takes local pc time
	return timeStamp;
}

float Transaction::getValue()
{
	return value;

}

void Transaction::setValue(float input)
{
	value = input;
}

