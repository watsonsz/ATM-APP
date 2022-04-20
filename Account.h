#pragma once

class Account
{
public:

	void BalanceCheck();
	void Deposit();
	void Withdraw();

private:
	int Balance = 1000;
};
