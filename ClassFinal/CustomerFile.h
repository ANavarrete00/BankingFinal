#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include "customers.h"
using namespace std;

class CustomerFile : public vector <customers> {
private:

public:
	CustomerFile() {
		int count = 0;
		customers temp;
		ifstream infile("customers.dat", ios::in | ios::binary);
		if (!infile) {
			cout << "File did not open." << endl;
			return;
		}
		infile.seekg(0, ios::end);
		count = infile.tellg() / sizeof(customers);
		infile.seekg(0, ios::beg);
		for (int i = 0; i < count; i++) {
			infile.read((char*)&temp, sizeof(customers));
			this->push_back(temp);
		}
		infile.close();
	}
	void add(customers cust) {
		int count = this->size();
		bool exist = false;
		customers temp;
		ofstream outfile("customers.dat", ofstream::out | ofstream::binary);
		if (!outfile) {
			cout << "File did not open." << endl;
			return;
		}
		for (int i = 0; i < count; i++) {
			temp = this->at(i);
			if (temp.getCustomerID() == cust.getCustomerID() && temp.getAccountID() == cust.getAccountID()) {
				cout << "This account already exists.\n";
				exist = true;
				continue;
			}
			outfile.write((char*)&temp, sizeof(customers));
			exist = false;
		}
		if (exist == false) {
			outfile.write((char*)&cust, sizeof(customers));
		}
		outfile.close();
	}
	void load(int customerID, int accountID) {
		int count = this->size();
		customers temp;
		for (int i = 0; i < count; i++) {
			temp = this->at(i);
			if (temp.getCustomerID() == customerID && temp.getAccountID() == accountID) {
				cout << "Balance: $" << temp.getBalance() << endl;
			}
		}
	}
	void deleteAccount(int customerID, int accountID) {
		int count = this->size();
		customers temp;
		ofstream outfile("customers.dat", ios::out | ios::binary);
		for (int i = 0; i < count; i++) {
			temp = this->at(i);
			if (temp.getCustomerID() == customerID && temp.getAccountID() == accountID) {
				char sure;
				temp.printCustomer();
				cout << "Are you sure you want to delete this account? (Y/N)\n";
				cin >> sure;
				sure = toupper(sure);
				if (sure == 'Y') {
					continue;
				}
			}
			outfile.write((char*)&temp, sizeof(customers));
		}
		outfile.close();
	}
	void SavingsUpdate(int customerID, int accountID, double amount, double fee) {
		double newBalance;
		int count = this->size();
		customers temp;
		ofstream outfile("customers.dat", ios::out | ios::binary);
		if(!outfile) {
			cout << "File did not open." << endl;
			return;
		}
		for (int i = 0; i < count; i++) {
			temp = this->at(i);
			if (temp.getCustomerID() == customerID && temp.getAccountID() == accountID) {
				newBalance = temp.getBalance() + amount;
				temp.setBalance(newBalance);
				if (newBalance < 1000) {
					newBalance -= fee;
					temp.setBalance(newBalance);
				}
			}
			outfile.write((char*)&temp, sizeof(customers));
		}
		outfile.close();
	}
	void CheckingsUpdate(int customerID, int accountID, double amount, double fee) {
		double newBalance;
		int count = this->size();
		customers temp;
		ofstream outfile("customers.dat", ios::out | ios::binary);
		if (!outfile) {
			cout << "File did not open." << endl;
			return;
		}
		for (int i = 0; i < count; i++) {
			temp = this->at(i);
			if (temp.getCustomerID() == customerID && temp.getAccountID() == accountID) {
				newBalance = temp.getBalance() + amount;
				temp.setBalance(newBalance);
				if (newBalance < 0) {
					newBalance -= fee;
					temp.setBalance(newBalance);
				}
			}
			outfile.write((char*)&temp, sizeof(customers));
		}
		outfile.close();
	}
};