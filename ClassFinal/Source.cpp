#include <iostream>
#include <string>
#include "Checkings.h"
#include "Savings.h"
using namespace std;

int main() {
	int customerID, accountID, zip;
	double amount;
	string Firstname, Lastname, Address, City, State, Phone;
	char choice;

	do {
		cout << "\t\tBank Accounts\n\n";
		cout << "Chose a option below\n";
		cout << "A) Checking account\nB) Savings account\nC) Add a new account\nD) Delete an existing account\n";
		cin >> choice;
		choice = toupper(choice);
		if (choice == 'A') {
			Checkings checking;
		}
		else if (choice == 'B') {
			Savings saveings;
		}
		else if(choice =='C') {
			cout << "Enter customer ID:\n";
			cin >> customerID;
			cout << "Enter account ID:\n";
			cin >> accountID;
			cout << "Enter your first deposit:\n";
			cin >> amount;
			cin.ignore();
			cout << "Enter First Name:\n";
			getline(cin, Firstname);
			cout << "Enter Last Name:\n";
			getline(cin, Lastname);
			cout << "Enter address:\n";
			getline(cin, Address);
			cout << "Enter city name:\n";
			getline(cin, City);
			cout << "Enter state (e.g. CA):\n";
			getline(cin, State);
			cout << "Enter Zip code:\n";
			cin >> zip;
			cin.ignore();
			cout << "Enter phone number (Format (xxx)xxx-xxxx:\n";
			getline(cin, Phone);
			cout << "Would you like to add a Checkings (C) or a Savings (S) account?\n";
			cin >> choice;
			choice = toupper(choice);
			if (choice == 'C') {
				Checkings Checking(customerID, accountID, zip, amount, Firstname, Lastname, Address, City, State, Phone);
			}
			else if (choice == 'S') {
				Savings Savings(customerID, accountID, zip, amount, Firstname, Lastname, Address, City, State, Phone);
			}
			else{
				cout << "Invalid input." << endl;
			}
		}
		else if (choice == 'D') {
			cout << "Enter customer ID: ";
			cin >> customerID;
			cout << "Enter customer ID: ";
			cin >> accountID;
			cout << "Would you like to delete a Checkings (C) or a Savings (S) account?\n";
			cin >> choice;
			choice = toupper(choice);
			if (choice == 'C') {
				Checkings Checkings(customerID, accountID);
			}
			else if (choice == 'S') {
				Savings Savings(customerID, accountID);
			}
		}
		else {
			cout << "Invalid input." << endl;
		}
		cout << "Would you like to run the program again? (Y/N)\n";
		cin >> choice;
		choice = toupper(choice);
	} while (choice == 'Y');

	return 0;
}