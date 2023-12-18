#include <iostream>
#include <iomanip>
#include "InvestmentAccount.h"

using namespace std;


//Main Class function prototypes
void displayOutput(InvestmentAccount account, int numberOfYears);    //Displays the account details, as well as account balances and interest earned for each year.



int main()
{
    // Get the input...validate that the values are non-negative.
    double initialAmount;
    double annualInterestRate;
    double monthlyDeposit;
    int numberOfYears;
    char anyKey;

    // display and getting user input
    cout << "************************************" << endl;
    cout << "************ Data Input ************" << endl;
    cout << "Initial Investment Amount: ";
    cin >> initialAmount;
    //input validation for initialAmount - has to be non-negative
    while (initialAmount < 0) {
        cout << "initial amount must be non-negative. Please try again: ";
        cin >> initialAmount;
    }
    // user input for monthly deposit
    cout << "Monthly Deposit: ";
    cin >> monthlyDeposit;
    //input validation for montly deposit - non-negative values
    while (monthlyDeposit < 0) {
        cout << "Deposit amount must be non-negative. Please try again: : ";
        cin >> monthlyDeposit;
    }

    // user input for annualInterestRate
    cout << "Annual Interest: ";
    cin >> annualInterestRate;
    //input validation for annualInterestRate
    while (annualInterestRate < 0) {
        cout << "Annual interest rate must be non-negative. Enter again: ";
        cin >> annualInterestRate;
    }


    // user prompt for num of years
    cout << "Number of years: ";
    cin >> numberOfYears;
    //input validation for num of years, cannot be negative
    while (numberOfYears < 0) {
        cout << "Number of years must be non-negative. Enter again: ";
        cin >> numberOfYears;
    }

    //wait for user to enter key to continue
     cout << "Enter any key to continue.....";
     cin >> anyKey;
     cin.get();
   
   

    // T InvestmentAccount variables - one with monthly deposit and one without monthly deposit
    InvestmentAccount withMonthlyDeposit(initialAmount, annualInterestRate, monthlyDeposit);
    InvestmentAccount withoutMonthlyDeposit(initialAmount, annualInterestRate);

    // Display the output investment acct without monthly deposit
    cout << endl;
    cout << "     Balance and Interest Without Additional Monthly Deposits" << endl;;
    displayOutput(withoutMonthlyDeposit, numberOfYears);

    // Display the output investment acct with monthly deposit
    cout << endl;
    cout << "     Balance and Interest With Additional Monthly Deposits" << endl;
    displayOutput(withMonthlyDeposit, numberOfYears);


    return 0;
}

// Implement displayOutput function
void displayOutput(InvestmentAccount account, int numberOfYears)
{
    cout << "===========================================================================" << endl;
    cout << setw(5) << "Year" << setw(30) << "Year End Balance" << setw(40) << "Year End Earned Interest" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    // Display the results for each year
    for (int year = 1; year <= numberOfYears; ++year)
    {
        cout << setw(5) << year;
        cout << setw(20) << "$" << account.getEndingBalanceFormatted(year);
        cout << setw(30) << "$" << account.getInterestEarnedFormatted(year) << endl;
    }


}

