#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int MainMenu() {
	int optionchoice;
	cout << "1. Sign in\n";
	cout << "2. Balance\n";
	cout << "3. Deposit\n";
	cout << "4. Withdraw\n";
	cout << "5. Exit\n";
	cin >> optionchoice;

	return optionchoice;
}

int AccountPick() {
	int number;
	cout << "Enter Account Number: ";
	cin >> number;
	while ((number < 0) || (number > 9)) {
		cout << "Invalid Account Number, Please try Again:\n";
		cin >> number;
	}

	return number;

}



class Account
{
public:

	int BalanceCheck();
	void Deposit(int amountToDeposit);
	void WithdrawCheck(int amount);
	
private:
	int Balance = 1000;
};

int Account::BalanceCheck()
{
	return Balance;
}

void Account::Deposit(int amountToDeposit)
{
	int i = 0;
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


void BalanceOption(Account& currAccount) {
	int currBalance = currAccount.BalanceCheck();
	if (currBalance < 100) {
		cout << "Low Balance: $" << currBalance << endl;		
	}
	else {
		cout << "Current Balance: $" << currBalance << endl;
	}
	system("PAUSE");

}
void DepositOption(Account& currAccount) {
	
	int amountToDeposit;
	cout << "Enter Amount to Deposit: $";
	cin >> amountToDeposit;
	currAccount.Deposit(amountToDeposit);

}
void WithdrawOption(Account& currAccount) {
	int amountToWithdraw;

	cout << "Please enter amount to Withdraw: $";
	cin >> amountToWithdraw;
	currAccount.WithdrawCheck(amountToWithdraw);
}

int main()
{
	vector<Account> AccountChoice(10);
	Account currAccount;
	int i;
	bool accountChosen = false;
	int option = 0;
	while (option != 6) {
		if (accountChosen) {
			cout << "Welcome Account Number: " << i << endl;
			while (accountChosen) {
				option = MainMenu();
				if (option == 1) {
					cout << "You are already signed in\n";
				}

				else if (option == 2) {
					BalanceOption(currAccount);
				}

				else if (option == 3) {
					DepositOption(currAccount);
				}
				else if (option == 4) {
					WithdrawOption(currAccount);
				}

				//FIXME: MORE OPTIONS
				else if (option == 5) {
					system("CLS");
					AccountChoice.at(i) = currAccount;
					accountChosen = false;
					cout << "GoodBye!\n";
					system("PAUSE");
				}
				else {
					cout << "\t\t Invalid Option \n Please Select and Option from the List Above\n";
					system("PAUSE");
				}
				system("CLS");

			}
		}
		else {
			option = MainMenu();
		}

		if (option == 1) {
			i = AccountPick();
			currAccount = AccountChoice.at(i);
			system("CLS");
			accountChosen = true;
		}
		else {
			cout << "Please Sign in to continue\n";		
			system("PAUSE");
		}
		system("CLS");

	}

	return 0;
}

