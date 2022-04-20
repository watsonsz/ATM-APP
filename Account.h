#pragma once

class Account
{
public:

	void BalanceCheck();
	void Deposit();
	void WithdrawCheck(int amount);

private:
	int Balance = 1000;
};
