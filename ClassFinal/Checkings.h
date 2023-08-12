#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "CustomerFile.h"
#include "customers.h"
using namespace std;

class Checkings {
private:
	int custID = 0;
	int actID = 0;
	double apy = 0.0002;
	double overdraftFee = 25.00;
	double Balance = 0;
	double amount = 0;
	char choice = 'N';
public:
	Checkings() {
		cout << "Choose option below\n";
		cout << "A) Deposit into checkings\nB) Withdraw from checkings\nC) Check balance\n";
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
	Checkings(int customerID, int accountID, int zip, double amount, string Fname, string Lname, string address, string city, string state, string phone) {
		CustomerFile custFile;
		customers cust;
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
	Checkings(int customerID, int accountID) {
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
		custFile.CheckingsUpdate(custID, actID, amount, overdraftFee);
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
		custFile.CheckingsUpdate(custID, actID, amount, overdraftFee);
	}
	void balance() {
		cout << "Enter customer ID: ";
		cin >> custID;
		cout << "Enter account ID: ";
		cin >> actID;
		CustomerFile custFile;
		custFile.load(custID, actID);
		double i = apy * 100;
		cout << "Overdraft Fee: $" << fixed << setprecision(2) << overdraftFee << endl;
		cout << "APY: " << fixed << setprecision(2) << i << "%" << endl;
	}
};