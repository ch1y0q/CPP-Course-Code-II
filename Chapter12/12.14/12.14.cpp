#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main() {
	Account account(200.0);
	SavingsAccount saving(100.0, 0.03);
	CheckingAccount checking(40.0, 1.0);
	cout << fixed << setprecision(3);

	vector< Account* > acc(3);
	acc[0] = &account;
	acc[1] = &saving;
	acc[2] = &checking;
	
	for (int i = 0; i < 3; ++i) {
		Account* aPtr = acc[i];
		cout << "No."<<i<<" Account is a "<<typeid(*aPtr).name()<<", balance: "<<aPtr->getBalance() << endl;
	}

	acc[1]->credit(10.0);
	acc[2]->debit(5.0);
	double interestEarned = ((SavingsAccount *)(acc[1]))->calculateInterest();
	cout << "Adding $" << interestEarned << " interest to saving account." << endl ;
	acc[1]->credit(interestEarned);
	for (int i = 0; i < 3; ++i) {
		Account* aPtr = acc[i];
		cout << "No." << i << " Account is a " << typeid(*aPtr).name() << ", balance: " << aPtr->getBalance() << endl;
	}
	cout << endl;
	return 0;
}