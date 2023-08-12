#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "CustomerFile.h"
#include "customers.h"
using namespace std;

class Savings {
private:
	int custID = 0;
	int actID = 0;
	double apy = 0.0105;
	double minBalance = 5.00;
	double withdrawFee = 50.00;
	double Balance, amount;
	char choice;
public:
	Savings() {
		Balance = 0;
		amount = 0;
		cout << "Choose option below\n";
		cout << "A) Deposit into savings\nB) Withdraw from savings\nC) Check balance\n";
		cin >> choice;
		choice = toupper(choice);
		if (choice == 'A') {
			deposit();
		}
		else if (choice == 'B') {
			withdraw();
		}
		else if (choice == 'C') {
			balance();
		}
		else {
			cout << "Invalid choice." << endl;
			cin >> choice;
			return;
		}
	}
	Savings(int customerID, int accountID, int zip, double amount, string Fname, string Lname, string address, string city, string state, string phone) {
		customers cust;
		CustomerFile custFile;
		cust.setCustomerID(customerID);
		cust.setAccountID(accountID);
		cust.setZip(zip);
		cust.setBalance(amount);
		cust.setName(Fname, Lname);
		cust.setAddress(address);
		cust.setCityState(city, state);
		cust.setPhone(phone);
		custFile.add(cust);
	}
	Savings(int customerID, int accountID) {
		CustomerFile custFile;
		custFile.deleteAccount(customerID, accountID);
	}
	void deposit() {
		cout << "Enter amount you wish to deposit: ";
		cin >> amount;
		cout << "Enter customer ID: ";
		cin >> custID;
		cout << "Enter account ID: ";
		cin >> actID;
		CustomerFile custFile;
		custFile.SavingsUpdate(custID, actID, amount, withdrawFee);
	}
	void withdraw() {
		cout << "Enter amount you wish to withdraw: ";
		cin >> amount;
		amount -= amount * 2;
		cout << "Enter customer ID: ";
		cin >> custID;
		cout << "Enter account ID: ";
		cin >> actID;
		CustomerFile custFile;
		custFile.SavingsUpdate(custID, actID, amount, withdrawFee);
	}
	void balance() {
		cout << "Enter customer ID: ";
		cin >> custID;
		cout << "Enter account ID: ";
		cin >> actID;
		CustomerFile custFile;
		custFile.load(custID, actID);
		int i = apy * 100;
		cout << "Minimum balance: $" << fixed << setprecision(2) << minBalance << endl;
		cout << "Withdraw Fee: $" << fixed << setprecision(2) << withdrawFee << endl;
		cout << "APY: " << i << "%" << endl;
	}
};