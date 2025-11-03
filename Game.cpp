#include <iostream>
#include <fstream>
#include "Gringotts.h"
using namespace std;
/*Error handling */
int error(int x) {
	while (!(cin)) {
		/*This statement converts the input into a boolean statement/value so
		if the input is not an integer then it will return 0 and run the following code */
		cin.clear(); //clears the red flags that went up when a non integar was entered
		cin.ignore(200, '\n'); /* ignore up 200 characters or until a new line charcter*/
		cout<< "This is not a valid number, try again: ";
		cin>>x;
	}
	/*	if (x<0) {
			x=1;
			cout<< "Error: the entered value is a negative number. The value is now 1."<<endl;
		}*/
	return x;
}
/*ostream& operator- (ostream& out, Gringotts& temp) {
    out << "Galleons" temp.Galleons
    Gringotts.balance- Wallet.balance;
    return out;
}*/
void Gringotts:: balance() {
	cout << "Balance: " << endl;
	cout << "Galleons: " << Galleons << endl;
	cout << "Sickles: " << Sickles << endl;
	cout << "Knuts: " << Knuts << endl;
}
void Wallet:: walletBalance() {
	cout << "Wallet balance: " << endl;
	cout << "Galleons: " << walletGalleons << endl;
	cout << "Sickles: " << walletSickles << endl;
	cout << "Knuts: " << walletKnuts << endl;
}
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
			Galleons+=count;

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
			Sickles+=count;
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
			Knuts+=count;

		}
	}
	else {
		cout << "You have no Knuts to deposit." << endl;
	}
}
void Gringotts:: withdraw() {
	int choice, count;
	balance();
	if (Galleons>0) {
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
			while (count > Galleons) {
				cout << "You only have " << Galleons << " Galleons. Enter again." << endl;
				cout << "How many would you like to withdraw?";
				cin >> count;
				count = error(count);
			}
			Galleons-=count;
			walletGalleons+=count;
		}
	}
	else {
		cout << "You have no Galleons to deposit." << endl;
	}
	if (Sickles>0) {
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
			while (count > Sickles) {
				cout << "You only have " << Sickles << " Sickles. Enter again." << endl;
				cout << "How many would you like to withdraw?";
				cin >> count;
				count = error(count);
			}
			Sickles-=count;
			walletSickles+=count;
		}
	}
	else {
		cout << "You have no Sickles to deposit." << endl;
	}
	if (Knuts>0) {
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
			while (count > Knuts) {
				cout << "You only have " << Knuts << " Knuts. Enter again." << endl;
				cout << "How many would you like to withdraw?";
				cin >> count;
				count = error(count);
			}
			Knuts-=count;
			walletKnuts+=count;
		}
	}
	else {
		cout << "You have no Knuts to deposit." << endl;
	}
}
void Gringotts::bank() {
	int choice;
	cout << "Would you like to check your account balance (1), deposit money (2), or withdraw money (3)? ";
	cin >> choice;
	while (choice!=1 && choice!=2 && choice!=3) {
		cout << "Invalid input, please enter again."<<endl;
		cout << "Would you like to check your account balance (1), deposit money (2), or withdraw money (3)? ";
		cin >> choice;
	}
	if (choice==1) {
		balance();
	}
	else if (choice==2) {
		deposit();
	}
	else if (choice==3) {
		withdraw();
	}
	else {}
}
int main() {
    int i;
    string line;
    ifstream fin("ascii_art.txt");
    string header[18];
   for (i=0; i<18; i++) {
     header[i]= getline(fin, line);
    cout << header[i];
}
    cout << "Welcome to Hogwarts";
	Gringotts g;
	return 0;
}
