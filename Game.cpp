#include <iostream>
#include <fstream>
#include <unistd.h>
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
Gringotts::Gringotts() {
    string name;
    cout << "Welcome to Gringotts Wizarding Bank!" << endl;
    cout << "What is your name so we can open a bank account for you? ";
    cin >> name;
    cout << "Welcome to the wizarding world " << name << "!" << endl;
    sleep(5);
    cout << "To open your account we need to have a starting balance." << endl;
    cout << "Let's exchange your Pounds for wizard currency." << endl;
    Galleons= 41;
    Sickles= 16;
    Knuts= 391;
    balance();
    sleep(10);
    withdraw();
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
    ifstream fin("ascii_art.txt");
    string header[18];
   for (i=0; i<18; i++) {
     getline(fin, header[i]);
    cout << header[i] << endl;
}
    cout << "You open the letter and find out you're a wizard!" << endl;
    cout << "You take a look at the list of required supplies..." << endl;
    cout << "Wand, robes, books, cauldron, pet..." << endl;
    cout << "A note at the bottom: Everything you need can be found in Diagon Alley" << endl;
    sleep(5);
    cout << "But you have no clue what Diagon Alley is or where to find it." << endl;
    cout << "You rifle through the papers in the hopes of finding something when you find a map on the back of the list!" << endl;
    sleep(5);
    cout << "You grab your wallet and a bag and head out in search of the wizard town." << endl;
    cout << "You walk towards Charing Cross Road and find the Leaky Caldron." << endl;
    sleep (5);
    cout << "Following the instructions, you walk around to the courtyard behind the tavern";
    cout << "and find a rubbish bin against a brick wall." << endl;
    cout << "You go 3 bricks up and 2 across and knock twice." << endl;
    sleep (5);
    cout << "Suddenly the brick wall opens up to a bustling street full of wizards dressed in robes." << endl;
    cout << "Many of them are the same age as you carrying similar bags full of new school supplies. " << endl;
    sleep(5);
    cout << "You stop one and ask where to find Ollivanders wand shop." << endl;
    cout << "Following the directions you turn right and walk until you find the sign: " << endl;
    cout << "Ollivanders: Makers of Fine Wands since 382 B.C." << endl;
    sleep(5);
    cout << "You enter the shop to find your wand." << endl;
    cout << "You find a wand made of Aspen with a Dragon Heartstring core." << endl;
    cout << "You go to pay for it with your Pounds when he tells you those are not accepted in the wizarding world." << endl;
    sleep(5);
    cout << "You must go to Gringotts bank across the street to exchange your money." << endl;
	Gringotts g;
	return 0;
}
