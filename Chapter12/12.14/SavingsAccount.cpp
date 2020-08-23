#include "SavingsAccount.h"
SavingsAccount::SavingsAccount(double initBalance,
	double rate) : Account(initBalance)
{
	interestRate = (rate < 0) ? 0.0 : rate;
}

double SavingsAccount::calculateInterest()
{
	return getBalance() * interestRate;
}