#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <iomanip>
#include <chrono>


class Transaction
{
private:
	std::string descr;
	std::string timeStamp;
	float value;
public:
	Transaction(std::string Input_Descr, float Input_value);
	std::string toString();
	std::string getDescr();
	void setDescr(std::string input);
	std::string TimeStamp();
	float getValue();
	void setValue(float input);
};
