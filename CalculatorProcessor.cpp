#include "CalculatorProcessor.h"
CalculatorProcessor::CalculatorProcessor(std::string num1, std::string numo2)
{
	if (cal->deci == true)
	{
		float dec1 = std::stof(num1);
		float dec2 = std::stof(numo2);
		if (cal->add == true)
		{
			data = std::to_string(dec1 + dec2);
		}
		else if (cal->sub == true)
		{
			data = std::to_string(dec1 - dec2);
		}
		else if (cal->mult == true)
		{
			data = std::to_string(dec1 * dec2);
		}
		else if (cal->diva == true)
		{
			data = std::to_string(dec1 / dec2);
		}
	}
	else
	{
	    int numo = std::stoi(num1);
		int num2 = std::stoi(numo2);
		if (cal->add == true)
		{
			data = std::to_string(numo + num2);
		}
		else if (cal->sub == true)
		{
			data = std::to_string(numo - num2);
		}
		else if (cal->mult == true)
		{
			data = std::to_string(numo * num2);
		}
		else if (cal->diva == true)
		{
			data = std::to_string(numo / num2);
		}
		else if (cal->modu == true)
		{
			data = std::to_string(numo % num2);
		}
	}
}
CalculatorProcessor* CalculatorProcessor::getproc(std::string num1, std::string num2)
{
	cal = new CalculatorProcessor(num1, num2);
	return cal;
}