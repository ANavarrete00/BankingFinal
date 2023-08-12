#pragma once
#include <iostream>
using namespace std;

class account {
private:
	int accountID, customerID;
public:
	account() {
		accountID = 0;
		customerID = 0;
	}
	account(int accountID, int customerID) {
		this->accountID = accountID;
		this->customerID = customerID;
	}
	int getAccontID() {
		return accountID;
	}
	int getCustomerID() {
		return customerID;
	}
	void printAccount() {
		cout << "Account ID: " << accountID << endl;
	}
};