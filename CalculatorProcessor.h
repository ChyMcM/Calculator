#pragma once
#include "wx/wx.h"
#include "Calculator.h"
class CalculatorProcessor
{
private:
	CalculatorProcessor(std::string num1, std::string num2);
public:
	static CalculatorProcessor* getproc(std::string num1, std::string num2);
	std::string data;
	static CalculatorProcessor* cal;
	bool add = false;
	bool sub = false;
	bool diva = false;
	bool mult = false;
	bool modu = false;
	bool deci = false;
};

