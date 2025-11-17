//Throw an exception object
#include <iostream>
#include "Gringotts.h"
#include <unistd.h>
using namespace std;

/* Operator overloading */
ostream& operator<<(ostream& out, BankAccount& temp) {
	out << "Bank Balance: " << endl;
	out << "Galleons: " << temp.Galleons << endl;
	out << "Sickles: " << temp.Sickles << endl;
	out << "Knuts: " << temp.Knuts << endl;
	return out;
}

/* Wallet class- checking wallet balance function*/
void Wallet:: walletBalance() {
	cout << "Wallet balance: " << endl;
	cout << "Galleons: " << walletGalleons << endl;
	cout << "Sickles: " << walletSickles << endl;
	cout << "Knuts: " << walletKnuts << endl;
}

/* Wallet class- conversion function*/
int Wallet:: getConversion() {
	/* Converting change to Knuts*/
	int GalleonsToKnuts = walletGalleons* 493; // 493 Knuts in a Galleon
	int SicklesToKnuts = walletSickles* 29; // 29 Knuts in a Sickle
	int total = walletKnuts + GalleonsToKnuts + SicklesToKnuts;
	return total;
}

/* Gringotts class- conversion function
int Wallet:: getConversion() {
	/* Converting change to Knuts
	int GalleonsToKnuts = bankAccount.getGalleons()* 493; // 493 Knuts in a Galleon
	int SicklesToKnuts = bankAccount.getSickles()* 29; // 29 Knuts in a Sickle
	int total = bankAccount.getKnuts() + GalleonsToKnuts + SicklesToKnuts;
	return total;
}*/

/* Gringotts class- deposit function */
void Gringotts:: deposit() {
	int choice, count;
	walletBalance();
	if (walletGalleons > 0) {
		cout << "Would you like to deposit any Galleons? (Yes=1, No=2)";
		cin >> choice;
		choice = error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to deposit any Galleons? (Yes=1, No=2)";
			cin >> choice;
			choice = error(choice);
		}
		if (choice == 1) {
			cout << "How many would you like to deposit?";
			cin >> count;
			count = error(count);
			while (count > walletGalleons) {
				cout << "You only have " << walletGalleons << " Galleons. Enter again." << endl;
				cout << "How many would you like to deposit?";
				cin >> count;
				count = error(count);
			}
			walletGalleons-=count;
			bankAccount.getGalleons() +=count;

		}
	}
	else {
		cout << "You have no Galleons to deposit." << endl;
	}
	if (walletSickles > 0) {
		cout << "Would you like to deposit any Galleons? (Yes=1, No=2)";
		cin >> choice;
		choice = error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to deposit any Sickles? (Yes=1, No=2)";
			cin >> choice;
			choice = error(choice);
		}
		if (choice == 1) {
			cout << "How many would you like to deposit?";
			cin >> count;
			count = error(count);
			while (count > walletSickles) {
				cout << "You only have " << walletSickles << " Sickles. Enter again." << endl;
				cout << "How many would you like to deposit?";
				cin >> count;
				count = error(count);
			}
			walletSickles-=count;
			bankAccount.getSickles()+=count;
		}
	}
	else {
		cout << "You have no Sickles to deposit." << endl;
	}
	if (walletKnuts > 0) {
		cout << "Would you like to deposit any Knuts? (Yes=1, No=2)";
		cin >> choice;
		choice = error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to deposit any Knuts? (Yes=1, No=2)";
			cin >> choice;
			choice = error(choice);
		}
		if (choice == 1) {
			cout << "How many would you like to deposit?";
			cin >> count;
			count = error(count);
			while (count > walletKnuts) {
				cout << "You only have " << walletKnuts << " Knuts. Enter again." << endl;
				cout << "How many would you like to deposit?";
				cin >> count;
				count = error(count);
			}
			walletKnuts-=count;
			bankAccount.getKnuts()+=count;

		}
	}
	else {
		cout << "You have no Knuts to deposit." << endl;
	}
}

/* Gringotts class- Withdraw function */
void Gringotts:: withdraw() {
	int choice, count;
	if (bankAccount.getGalleons()>0) {
		cout << "Would you like to withdraw any Galleons (Yes=1, No=2)? ";
		cin >> choice;
		choice = error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to deposit any Galleons? (Yes=1, No=2)";
			cin >> choice;
			choice = error(choice);
		}
		if (choice == 1) {
			cout << "How many Galleons would you like to withdraw? ";
			cin >> count;
			count = error(count);
			while (count > bankAccount.getGalleons()) {
				cout << "You only have " << bankAccount.getGalleons() << " Galleons. Enter again." << endl;
				cout << "How many would you like to withdraw?";
				cin >> count;
				count = error(count);
			}
			bankAccount.getGalleons()-=count;
			walletGalleons+=count;
		}
	}
	else {
		cout << "You have no Galleons to deposit." << endl;
	}
	if (bankAccount.getSickles()>0) {
		cout << "Would you like to withdraw any Sickles (Yes=1, No=2)? ";
		cin >> choice;
		choice= error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to deposit any Sickles? (Yes=1, No=2)";
			cin >> choice;
			choice = error(choice);
		}
		if (choice == 1) {
			cout << "How many Sickles would you like to withdraw? ";
			cin >> count;
			count = error(count);
			while (count > bankAccount.getSickles()) {
				cout << "You only have " << bankAccount.getSickles() << " Sickles. Enter again." << endl;
				cout << "How many would you like to withdraw?";
				cin >> count;
				count = error(count);
			}
			bankAccount.getSickles()-=count;
			walletSickles+=count;
		}
	}
	else {
		cout << "You have no Sickles to deposit." << endl;
	}
	if (bankAccount.getKnuts()>0) {
		cout << "Would you like to withdraw any Knuts (Yes=1, No=2)? ";
		cin >> choice;
		choice= error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to deposit any Knuts? (Yes=1, No=2)";
			cin >> choice;
			choice = error(choice);
		}
		if (choice == 1) {
			cout << "How many Knuts would you like to withdraw? ";
			cin >> count;
			count = error(count);
			while (count > bankAccount.getKnuts()) {
				cout << "You only have " << bankAccount.getKnuts() << " Knuts. Enter again." << endl;
				cout << "How many would you like to withdraw?";
				cin >> count;
				count = error(count);
			}
			bankAccount.getKnuts()-=count;
			walletKnuts+=count;
		}
	}
	else {
		cout << "You have no Knuts to deposit." << endl;
	}
}

/* Gringotts class- Transaction function */
int Gringotts:: Transaction(int tempGalleons, int tempSickles, int tempKnuts) {
	int choice;
	/* Converting charge total to Knuts*/
	int GalleonsToKnuts = tempGalleons* 493; // 493 Knuts in a Galleon
	int SicklesToKnuts = tempSickles* 29; // 29 Knuts in a Sickle
	int transactionTotal = tempKnuts + GalleonsToKnuts + SicklesToKnuts;
	if (getConversion() < transactionTotal) {
		cout << "You do not have enough money. Would you like to go to the bank? (Yes=1, No=2)" << endl;
		cin >> choice;
		choice= error(choice);
		while (choice!=1 && choice!=2) {
			cout << "Invalid input. Try again." << endl;
			cout << "Would you like to go to the bank? (Yes=1, No=2)";
			cin >> choice;
			choice = error(choice);
		}
		if (choice== 1) {
			withdraw();
		}
		else {
			return 0;
		}
	}
	else {
		walletGalleons -= tempGalleons;
		walletSickles -= tempSickles;
		walletKnuts -= tempKnuts;
		walletBalance();
	}
}

/* Gringotts constructor function */
Gringotts::Gringotts(string keyword, string name):bankAccount(keyword,name) {
	cout << "Welcome to the wizarding world " << bankAccount.getName() << "!" << endl;
	sleep(5);
	cout << "To open your account we need to have a starting balance." << endl;
	cout << "Let's exchange your Pounds for wizard currency." << endl;
	bankAccount.setGalleons(11);
	bankAccount.setSickles(16);
	bankAccount.setKnuts(391);
	withdraw();
}

/* Gringotts Transaction test function
void Gringotts:: TransactionTest(int tempGalleons, int tempSickles, int tempKnuts) {
   string MSG1= "Cannot complete transaction- not enough Galleons";
   string MSG2= "Cannot complete transaction- not enough Sickles";
   string MSG3= "Cannot complete transaction- not enough Knuts";
   if (walletGalleons()<tempGalleons) {
     throw(MSG1);
   }
   if (walletSickles() < tempSickles && walletGalleons<=tempGalleons) {
     throw(MSG1);
   }
   if (walletKnuts() < tempKnuts && walletSickles<=tempSickles && walletGalleons<=tempGalleons) {
     throw(MSG3);
   }
 }*/

/*    walletGalleons-=costGalleons;
  while (walletSickles() < costSickles) {
    walletGalleons--;*/


/*	void bank(Gringotts& temp) {
		int choice;
		//const string MESSAGE= "Invalid input, please enter again.";
		cout << "Would you like to check your account balance (1), deposit money (2), or withdraw money (3)? ";
		cin >> choice;
		choice= error(choice);
		while (choice!=1 && choice!=2 && choice!=3) {
			cout << "Invalid input, please enter again."<<endl;
			cout << "Would you like to check your account balance (1), deposit money (2), or withdraw money (3)? ";
			cin >> choice;
		}
		if (choice==1) {
			cout << temp;
		}
		else if (choice==2) {
			temp.deposit();
		}
		else if (choice==3) {
			temp.withdraw();
		}
	}*/
