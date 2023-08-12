#pragma once
#include <iostream>
#include <string>
#include "account.h"
using namespace std;

class customers : account{
private:
	int customerID, accountID, zip;
	double balance;
	char Firstname[20], Lastname[20], Address[50], City[20], State[5], Phone[15];
public:
	customers() {
		customerID = 0;
		accountID = 0;
		zip = 0;
		balance = 0;
		strcpy_s(Firstname, "");
		strcpy_s(Lastname, "");
		strcpy_s(Address, "");
		strcpy_s(City, "");
		strcpy_s(State, "");
		strcpy_s(Phone, "");
	}
	customers(int customerID, int accountID, int zip, double amount, string Fname, string Lname, string address, string city, string state, string phone) : account(accountID, customerID) {
		this->customerID = customerID;
		this->accountID = accountID;
		this->zip = zip;
		balance = amount;
		setName(Fname, Lname);
		setAddress(address);
		setCityState(city, state);
		setPhone(phone);
	}
	void setCustomerID(int customerID) {
		this->customerID = customerID;
	}
	void setAccountID(int accountID) {
		this->accountID = accountID;
	}
	void setZip(int zip) {
		this->zip = zip;
	}
	void setName(string Fname, string Lname) {
		strcpy_s(Firstname, Fname.c_str());
		strcpy_s(Lastname, Lname.c_str());
	}
	void setAddress(string address) {
		strcpy_s(Address, address.c_str());
	}
	void setCityState(string city, string state) {
		strcpy_s(City, city.c_str());
		strcpy_s(State, state.c_str());
	}
	void setBalance(double balance) {
		this->balance = balance;
	}
	void setPhone(string phone) {
		strcpy_s(Phone, phone.c_str());
	}
	int getCustomerID() {
		return customerID;
	}
	int getAccountID() {
		return accountID;
	}
	double getBalance() {
		return balance;
	}
	void printCustomer() {
		cout << "Full Name: " << Firstname << " " << Lastname << endl;
		cout << "Address: " << Address << " " << City << ", " << State << " " << zip << endl;
	}
};