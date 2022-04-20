#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include "Account.h"
using namespace std;
void Account::BalanceCheck()
{
	if (Balance < 100) {
		cout << "Low Balance: $" << Balance << endl;
	}
	else {
		cout << "Current Balance: $" << Balance << endl;
	}
	system("PAUSE");

}
void Account::Deposit(){
	int i = 0;
	int amountToDeposit;

	cout << "Enter Amount to Deposit: $";
	cin >> amountToDeposit;

	while (i < 1) {
		if (amountToDeposit > 0) {
			Balance += amountToDeposit;
			i += 2;
			cout << "$" << amountToDeposit << " deposited into your account.\n";
			system("PAUSE");
		}
		else {
			i += 1;
			cout << "Invalid Amount, please try again:\n";
			cin >> amountToDeposit;
		}

	}
}
void Account::WithdrawCheck(int amount) {
	int j = 0;
	while (j < 1) {
		if (amount > Balance) {
			j += 1;
			cout << "Insufficient Funds.\n Current Balance: $" << Balance << endl;
			cout << "Enter New Amount: $";
			cin >> amount;
		}
		else {
			j += 2;
			Balance -= amount;

		}
	}
}