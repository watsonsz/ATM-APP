#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include "Account.h"
using namespace std;


//The only Local functions are the Main Menu, vector selection (Sign in) and Exit functions
//FIXME: Deposit and Withdraw Functions need to be transferred to their respective functions in the class "Account"
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
void WithdrawOption(Account& currAccount) {
	int amountToWithdraw;

	cout << "Please enter amount to Withdraw: $";
	cin >> amountToWithdraw;
	currAccount.WithdrawCheck(amountToWithdraw);
}

int main()
{
	//Variable Declaration
	vector<Account> AccountChoice(10);
	Account currAccount;
	int i;
	bool accountChosen = false;
	int option = 0;

	//The while loop contains the program, with option = 6 being a killswitch only avaiable when account is NOT chosen.
	while (option != 6) {
		if (accountChosen) {

			//This while loop is the sign-in instance. It also displays a welcome message with the Account being used displayed
			while (accountChosen) {
				cout << "Welcome Account Number: " << i << endl;
				option = MainMenu();
				if (option == 1) {
					cout << "You are already signed in\n";
				}

				else if (option == 2) {
					currAccount.BalanceCheck();
				}

				else if (option == 3) {
					currAccount.Deposit();
				}
				else if (option == 4) {
					WithdrawOption(currAccount);
				}

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

