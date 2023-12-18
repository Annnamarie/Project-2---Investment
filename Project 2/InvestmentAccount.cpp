#include "InvestmentAccount.h"

//Implementation for InvestmentAccount
InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate)
	:initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(0.0)
{
	//constructor for investment acct with 0 monthly deposit
}

InvestmentAccount::InvestmentAccount(double initialAmount, double annualInterestRate, double monthlyDeposit)
	:initialAmount(initialAmount), annualInterestRate(annualInterestRate), monthlyDeposit(monthlyDeposit)
{
	//constructor for investment acct with montly deposit
}

double InvestmentAccount::getEndingBalance(int numberOfYears)
{
	int monthsInYear = 12;
	double closingBalance = initialAmount;

	//calculate the ending balance for the month (sum of last balance + deposit + interest earned)
	int i;
	for (i = 0; i < numberOfYears * monthsInYear; i++) {
		double monthInterest = (closingBalance + monthlyDeposit) * ((annualInterestRate / 100) / monthsInYear);
		closingBalance = closingBalance + monthlyDeposit + monthInterest;
	}
	return closingBalance;
}

double InvestmentAccount::getInterestEarned(int numberOfYears)
{
	//calculating the interest earned for the each year except for year 1
	double interestEarned;
	if (numberOfYears != 1) {
		interestEarned = getEndingBalance(numberOfYears) - getEndingBalance(numberOfYears - 1) - (monthlyDeposit * 12);
	}
	//calculating the interest earned for year 1 (subtracted from the initial deposit instead of the previous year)
	else {
		interestEarned = getEndingBalance(numberOfYears) - initialAmount - (monthlyDeposit * 12);
	}

	return interestEarned;
}

std::string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears)
{
	//formatting the ending balance using the round and format method
	double endingBalance = round(getEndingBalance(numberOfYears),2);
	return format(endingBalance);
}

std::string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears)
{
	//formatting the interest earned using the round and format method
	double interestEarned = round(getInterestEarned(numberOfYears),2);
	return format(interestEarned);
}

double InvestmentAccount::getInitialAmount()
{
	//getter method for initialAmount
	return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit()
{
	//getter method for monthly deposits
	return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate()
{
	//getter method for annual interest rate
	return annualInterestRate;
}


//The following method rounds a value to the specified number of places.
//NOTE: It works for most values...but is not guaranteed to work for all values!
//@param value - the value to round
//@param places - the number of places to round
//@returns - the rounded number
double InvestmentAccount::round(double value, int places) {
	const int multiplier = pow(10, places);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

//Formats a double value for output purposes.
//This method will not append with any 0s...so the value should be rounded prior to use.
//@param value - the value to format
//@returns - the formatted value.
std::string InvestmentAccount::format(double value) {
	std::string valueAsString = std::to_string(value);
	std::string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		}
		else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(std::string(1, currentChar));
	}

	return formatted;
}