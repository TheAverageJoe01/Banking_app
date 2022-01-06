#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip>
#include <chrono>
#include<time.h>

#include "Transaction.h"


Transaction::Transaction(std::string Input_Descr, float Input_value)
{
	setDescr(Input_Descr);
	setValue(Input_value);
	setTimeStamp();
}

// return input as a string 
std::string Transaction::toString(float input)
{
	return std::to_string(input);
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
	//return ctime(&timeStamp);
	return 'o';
}

void Transaction::setTimeStamp()
{
	timeStamp = time(0);
}

float Transaction::getValue()
{
	return value;

}

void Transaction::setValue(float input)
{
	value = input;
}

