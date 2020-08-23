#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(double initBalance)
{
	if (initBalance >= 0.0)
		balance = initBalance;
	else
	{
		cout << "Negative balance" << endl;
		balance = 0.0;
	}
}

void Account::credit(double amount)
{
	balance = balance + amount;
}

bool Account::debit(double amount)
{
	if (amount > balance)
	{
		cout << "Debit amount exceeded account bal ance." << endl;
		return false;
	}
	else
	{
		balance = balance - amount;
		return true;
	}
}
void Account::setBalance(double newBalance)
{
	balance = newBalance;
}

double Account::getBalance()
{
	return balance;
}
