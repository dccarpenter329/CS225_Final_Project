#include <iostream>
#include <unistd.h>
#include "Gringotts.h"
using namespace std;

/*Operator overloading*/
ostream& operator<<(ostream& out, BankAccount& temp) {
	out << endl;
	out << "Bank Balance: " << endl;
	out << "Galleons: " << temp.Galleons << endl;
	out << "Sickles: " << temp.Sickles << endl;
	out << "Knuts: " << temp.Knuts << endl;
	return out;
}

/*Wallet class- checking wallet balance function*/
void Wallet:: walletBalance() {
	cout << "Wallet balance: " << endl;
	cout << "Galleons: " << walletGalleons << endl;
	cout << "Sickles: " << walletSickles << endl;
	cout << "Knuts: " << walletKnuts << endl;
}

/*Wallet class- conversion function*/
int Wallet::getConversion() {
	/* Converting change to Knuts*/
	int galleonsToKnuts = walletGalleons* 493; // 493 Knuts in a Galleon
	int sicklesToKnuts = walletSickles* 29; // 29 Knuts in a Sickle
	int total = walletKnuts + galleonsToKnuts + sicklesToKnuts; // Total in knuts
	return total;
}

/*Gringotts class- Withdraw function*/
void Gringotts::withdraw() {
	int choice, count;
	walletBalance();
	cout << bankAccount << endl;
	if (bankAccount.getGalleons()>0) {
		cout << "Would you like to withdraw any Galleons (Yes=1, No=2)? ";
		cin >> choice;
		choice = Error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to deposit any Galleons? (Yes=1, No=2)";
			cin >> choice;
			choice = Error(choice);
		}
		if (choice == 1) {
			cout << "How many Galleons would you like to withdraw? ";
			cin >> count;
			count = Error(count);
			while (count > bankAccount.getGalleons()) {
				cout << "You only have " << bankAccount.getGalleons() << " Galleons. Enter again." << endl;
				cout << "How many would you like to withdraw?";
				cin >> count;
				count = Error(count);
			}
			bankAccount.getGalleons()-=count;
			walletGalleons+=count;
		}
	}
	else {
		cout << "You have no Galleons to withdraw." << endl;
	}
	if (bankAccount.getSickles()>0) {
		cout << "Would you like to withdraw any Sickles (Yes=1, No=2)? ";
		cin >> choice;
		choice= Error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to withdraw any Sickles? (Yes=1, No=2)";
			cin >> choice;
			choice = Error(choice);
		}
		if (choice == 1) {
			cout << "How many Sickles would you like to withdraw? ";
			cin >> count;
			count = Error(count);
			while (count > bankAccount.getSickles()) {
				cout << "You only have " << bankAccount.getSickles() << " Sickles. Enter again." << endl;
				cout << "How many would you like to withdraw?";
				cin >> count;
				count = Error(count);
			}
			bankAccount.getSickles()-=count;
			walletSickles+=count;
		}
	}
	else {
		cout << "You have no Sickles to withdraw." << endl;
	}
	if (bankAccount.getKnuts()>0) {
		cout << "Would you like to withdraw any Knuts (Yes=1, No=2)? ";
		cin >> choice;
		choice= Error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to withdraw any Knuts? (Yes=1, No=2)";
			cin >> choice;
			choice = Error(choice);
		}
		if (choice == 1) {
			cout << "How many Knuts would you like to withdraw? ";
			cin >> count;
			count = Error(count);
			while (count > bankAccount.getKnuts()) {
				cout << "You only have " << bankAccount.getKnuts() << " Knuts. Enter again." << endl;
				cout << "How many would you like to withdraw?";
				cin >> count;
				count = Error(count);
			}
			bankAccount.getKnuts()-=count;
			walletKnuts+=count;
		}
	}
	else {
		cout << "You have no Knuts to withdraw." << endl;
	}
}

/*Gringotts class- Transaction function*/
int Gringotts:: Transaction(int tempGalleons, int tempSickles, int tempKnuts) {
	int choice;
	int x;
	/*Converting charge total to Knuts*/
	int GalleonsToKnuts = tempGalleons* 493; // 493 Knuts in a Galleon
	int SicklesToKnuts = tempSickles* 29; // 29 Knuts in a Sickle
	int transactionTotal = tempKnuts + GalleonsToKnuts + SicklesToKnuts; //Transaction total in Knuts
	int walletTotal = getConversion(); // Wallet total in Knuts
	if (walletTotal < transactionTotal) {
		cout << "You do not have enough money. Would you like to go to the bank? (Yes=1, No=2)" << endl;
		cin >> choice;
		choice = Error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to go to the bank? (Yes=1, No=2)";
			cin >> choice;
			choice = Error(choice);
		}
		while (choice== 1) {
			withdraw();

			walletTotal = getConversion();
			if (walletTotal < transactionTotal) {
				cout << "You still do not have enough money. Would you like to go to the bank? (Yes=1, No=2)" << endl;
				cin >> choice;
				choice = Error(choice);
				while (choice!=1 && choice!=2) {
					cout << "Invalid input. Try again." << endl;
					cout << "Would you like to go to the bank? (Yes=1, No=2)";
					cin >> choice;
					choice = Error(choice);
				}
			}
			else {
				choice = 3; // Exiting withdrawl loop and avoiding next loop
			}
		}
		if (choice == 2) {
			cout << "You cannot make your purchase" << endl;
			x = 0; // Returning 0- purchase incomplete
		}
	}
	else {
		int finalTotal = walletTotal-transactionTotal;
		walletGalleons = 0; // Initializing new wallet balance
		walletSickles = 0;
		walletKnuts = 0;
		while (finalTotal>=493) { // Calculating total Galleons in change
			walletGalleons+=1;
			finalTotal-=493;
		}
		while (finalTotal>=29) { // Calculating total Sickles in change
			walletSickles+=1;
			finalTotal-=29;
		}
		walletKnuts = finalTotal; // Calculating total Knuts in change
		walletBalance();
		x = 1; // returning 1- purchase complete
	}
	return x;
}

/*Gringotts constructor function*/
Gringotts::Gringotts(string name):bankAccount(name) {
	cout << "Welcome to the wizarding world " << bankAccount.getName() << "!" << endl;
	sleep(3);
	cout << "To open your account we need to have a starting balance." << endl;
	cout << "Let's exchange your Pounds for wizard currency." << endl;
	bankAccount.setGalleons(61);
	bankAccount.setSickles(16);
	bankAccount.setKnuts(391);
	cout << "Now lets help you withdraw some money for your wallet." << endl;
	/*Initializing wallet balance*/
	walletGalleons = 0;
	walletSickles = 0;
	walletKnuts = 0;
	withdraw();
}

/*Gringotts destructor function*/
Gringotts::~Gringotts() {
	cout << "GAME OVER" << endl;
}
