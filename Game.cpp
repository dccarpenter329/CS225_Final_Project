#include <iostream>
#include <fstream>
#include "Gringotts.h"
#include <unistd.h>
#include <cstdlib>
using namespace std;
/*Error handling */
int error(int x) {
	while (!(cin)) {
		/* convert input into boolean value so non-integer input will return 0 and run the following code */
		cin.clear(); //clears non-integer the red flags
		cin.ignore(200, '\n'); /* ignore up 200 characters or until a new line charcter*/
		cout<< "This is not a valid number, try again: ";
		cin>>x;
	}
	return x;
}
int main() {
	srand(time(NULL));
	int i;
	string nme, kywrd;
	string MESSAGE= "Error: invalid keyword";
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
	//sleep(5);
	cout << "But you have no clue what Diagon Alley is or where to find it." << endl;
	cout << "You rifle through the papers in the hopes of finding something when you find a map on the back of the list!" << endl;
	//sleep(5);
	cout << "You grab your wallet and a bag and head out in search of the wizard town." << endl;
	cout << "You walk towards Charing Cross Road and find the Leaky Caldron." << endl;
	//sleep (5);
	cout << "Following the instructions, you walk around to the courtyard behind the tavern";
	cout << "and find a rubbish bin against a brick wall." << endl;
	cout << "You go 3 bricks up and 2 across and knock twice." << endl;
	//sleep (5);
	cout << "Suddenly the brick wall opens up to a bustling street full of wizards dressed in robes." << endl;
	cout << "Many of them are the same age as you carrying similar bags full of new school supplies. " << endl;
	//sleep(5);
	cout << "You stop one and ask where to find Ollivanders wand shop." << endl;
	cout << "Following the directions you turn right and walk until you find the sign: " << endl;
	cout << "Ollivanders: Makers of Fine Wands since 382 B.C." << endl;
	//sleep(5);
	cout << "You enter the shop to find your wand." << endl;
	wandQuiz();
	cout << "You go to pay for it with Pounds when he tells you those are not accepted in the wizarding world." << endl;
	//sleep(5);
	cout << "You must go to Gringotts bank across the street to exchange your money." << endl;
	cout << "You walk across the street and enter the massive marbled building." << endl;
	//sleep(5);
	cout << "Welcome to Gringotts Wizarding Bank!" << endl;
	cout << "What is your full name so we can open a bank account for you? ";
	getline(cin, nme, '\n');
	cout << "Enter a keyword to access your bank account in the future: ";
	cin >> kywrd;
	while (kywrd.size() < 8) {
		cout << "Keyword must have at least 8 characters. Try again." << endl;
		cout << "Enter a keyword to access your bank account in the future: ";
		cin >> kywrd;
	}
	Gringotts g(nme, kywrd);
	cout << "With wizard money in your wallet you head back to Ollivanders to purchase you wand." << endl;
	cout << "Your wand costs 26 Galleons, 5 Sickles, and 200 Knuts." << endl;
	cout << walletBalance();
	try {
		g.transaction(26,5,200);
	}
	catch(message1) {
		cout << message << endl;
	}
 catch(message2) {
   cout << message2 << endl;
   }
   catch(message3) {
   cout << message3 << endl;
   }
   cout << "Would you like to go to the bank? (Yes=1, No=2)";
   cin >> choice;
   choice= error(choice);
			while (choice!=1 && choice!=2) {
				cout << "Invalid input. Try again." << endl;
				cout << "Would you like to go to the bank? (Yes=1, No=2)";
				cin >> choice;
				choice = error(choice);
			}
   if (choice== 1) {
   	g.withdraw();
   }
cout << "You take a look at your list- next up you must find your pet." << endl;
cout << "You ask Ollivandar where to find a pet store. He tells you to look for the Magical Menagerie on the North side of Diagon Alley." << endl;
	cout << "However, he warns you to be careful as some odd people often linger on the streets of the North side." << endl;
	sleep(5);
cout << "With this warning in mind, you head towards North side in search of a new pet." << endl;
	cout << "You pass candy shops and apothecarys, shops of ends and oddities. " << endl;
	sleep(5);
	cout << "After 10 minutes of walking the street begins to dim, lamposts either gone out or glass broken." << endl;
	cout << "Suddenly you hear someone whisper at you from an alley... \"pst, hey you\"
	
	// at one point you don't have enough money. you find someone in the alleygggg
	return 0;
}
