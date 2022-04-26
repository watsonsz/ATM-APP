#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Account.h"
using namespace std;
// Balance check
void Account::BalanceCheck()
{
	if (Balance <= 100) {
		cout << "Low Balance: $" << Balance << endl;
	}
	else {
		cout << "Current Balance: $" << Balance << endl;
	}
	system("PAUSE");

}

//Deposit Function
void Account::Deposit(){
	int i = 0;
	int amountToDeposit;

	cout << "Enter Amount to Deposit: $";

	while (i < 2) {
		cin >> amountToDeposit;
		if (amountToDeposit > 0) {
			Balance += amountToDeposit;
			i += 2;
			cout << "$" << amountToDeposit << " deposited into your account.\n";
			system("PAUSE");
		}
		else {
			i += 1;
			cout << "Invalid Amount, please try again:\n";
			
		}
	}
}

//Withdraw Function
void Account::Withdraw() {
	int j = 0;
	int amount;
	cout << "Please enter amount to Withdraw: $";
	

	while (j < 2) {
		cin >> amount;
		if (amount > Balance) {
			j += 1;
			cout << "Insufficient Funds.\n Current Balance: $" << Balance << endl;
			cout << "Enter New Amount: $";
		}
		else {
			j += 2;
			Balance -= amount;

		}
	}
}