// anytime you withdraw many use balance insertion operator first <<
// Error handling if user enters a number for full name
#include <iostream>
#include <fstream>
#include "Gringotts.h"
#include <unistd.h>
#include <cstdlib>
using namespace std;

/*Error handling */
int Error(int x) {
	while (!(cin)) {
		/* convert input into boolean value, non-integer input will return 0 */
		cin.clear(); // Clears non-integer the red flags
		cin.ignore(200, '\n'); // Ignore up 200 characters or until a new line charcter
		cout<< "This is not a valid number, try again: ";
		cin>>x;
	}
	return x;
}

/*Main code*/
int main() {
	srand(time(NULL)); // Seeding the random number generator
	int wand = 0, pet = 0; // Initializing global variables
	int i, choice; // Initializing input integers
	string nme, temp; // Initializing input strings
	int book[4];
	string petOptions[4] = {"Desert Toad", "Black Cat", "Snowy Owl", "Brown Rat"};
	/*accessing file to read in ascii art*/
	ifstream fin("ascii_art.txt");
	string header[18]; // Array that will hold read in values
	for (i=0; i<18; i++) {
		getline(fin, header[i]);
		cout << header[i] << endl;
	}
	fin.close();
	/* Begin game*/
	cout << "You open a letter and find out you're a wizard!" << endl;
	cout << "You take a look at the list of required supplies..." << endl;
	cout << "Wand, robes, books, cauldron, pet..." << endl;
	cout << "A note at the bottom: Everything you need can be found in Diagon Alley" << endl;
	sleep(3);
	cout << "But you have no clue what Diagon Alley is or where to find it." << endl;
	cout << "You rifle through the papers in the hopes of finding something ";
	cout << "when you find a map on the back of the list!" << endl;
	sleep(3);
	cout << "You grab your wallet and a bag and head out in search of the wizard town." << endl;
	cout << "You walk towards Charing Cross Road and find the Leaky Caldron." << endl;
	sleep (3);
	cout << "Following the instructions, you walk around to the courtyard behind the tavern ";
	cout << "and find a rubbish bin against a brick wall." << endl;
	cout << "You go 3 bricks up and 2 across and knock twice." << endl;
	sleep (3);
	cout << "Suddenly the brick wall opens up to a bustling street full of wizards." << endl;
	cout << "Many of them are the same age as you carrying bags full of new school supplies." << endl;
	sleep(3);
	cout << "You stop one and ask where to find Ollivanders wand shop." << endl;
	cout << "Following the directions you turn right and walk until you find the sign: " << endl;
	cout << "Ollivanders: Makers of Fine Wands since 382 B.C." << endl;
	sleep(3);
	cout << "You enter the shop to find your wand." << endl;
	WandQuiz(); // Wand quiz function to figure out which wand you get
	cout << "Your wand costs 26 Galleons, 5 Sickles, and 200 Knuts." << endl;
	cout << "You go to pay for it with Pounds when Ollivander tells";
	cout << "you those are not accepted in the wizarding world." << endl;
	sleep(3);
	cout << "You must go to Gringotts bank across the street to exchange your money." << endl;
	cout << "You walk across the street and enter the massive marbled building." << endl;
	sleep(3);
	cout << "Welcome to Gringotts Wizarding Bank!" << endl;
	cout << "What is your full name so we can open a bank account for you? ";
	getline(cin, temp, '\n'); // Read in new line character before getline
	getline(cin, nme, '\n'); // Read in players name
	Gringotts g(nme); // Running constructor
	cout << "With wizard money in your wallet you head back to Ollivanders to ";
	cout << "purchase you wand." << endl;
	int wandPurchase = g.Transaction(26,5,200);
	if (wandPurchase == 0) {
		cout << "You take a look at your list- next up you must find your pet." << endl;
		cout << "You ask Ollivandar where to find a pet store. He tells you to look for the Magical Menagerie on the North side of Diagon Alley." << endl;
		sleep(5);
		cout << "However, he warns you to be careful as some odd people often linger on the streets of the North side." << endl;
		cout << "You walk out of Ollivander's, no wand in hand." << endl;
	}
	else {
		wand=1;
		cout << "You take a look at your list- next up you must find your pet." << endl;
		cout << "You ask Ollivandar where to find a pet store. He tells you to look for the Magical Menagerie on the North side of Diagon Alley." << endl;
		sleep(5);
		cout << "However, he warns you to be careful as some odd people often linger on the streets of the North side." << endl;
		cout << "You walk out of Ollivander's, wand in hand." << endl;
	}

	sleep(5);
	cout << "With this warning in mind, you head towards North side in search of a new pet." << endl;
	cout << "You pass candy shops and apothecarys, shops of ends and oddities. " << endl;
	sleep(5);
	cout << "After 10 minutes of walking the street begins to dim, lamposts ";
	cout << "either gone out or glass broken." << endl;
	cout << "Suddenly you hear someone whisper at you from an alley... \"pst, hey you\"" << endl;
	cout << "You peer down the alley and see a witch cloaked in black standing in the corner." << endl;
	cout << "She beckons for you, \"I have something for you, come over here.\"" << endl;
	cout << "Will you go over to her? (Yes=1, No=2)" << endl;
	cin >> choice;
	choice= Error(choice);
	while (choice!=1 && choice!=2) {
		cout << "Invalid input. Try again." << endl;
		cout << "Would you like to withdraw any Sickles? (Yes=1, No=2)";
		cin >> choice;
		choice = Error(choice);
	}
	if (choice == 1) {
		int phoenix = Alley();
		if (phoenix == 0) {
			cout << "Your lack of cleverness disappoints me." << endl;
			cout << "You do not deserve a phoenix as your companion. Be gone!" << endl;
			int r= rand() % 4;
			cout << "You continue to make your way to the Magical Menagerie." << endl;
			cout << "You enter the shop to hear a rucus of animals: toads, owls, cats, rats..." << endl;
			sleep(5);
			cout << "After looking around you find a " << petOptions[r] << " that catches your eye." << endl;
			cout << "You tell a store clerk and he retrieves the animal for you." << endl;
			cout << "The total is 14 Galleons, 15 Sickles, and 8 Knuts." << endl;
			int petPurchase = g.Transaction(14,15,8);
			if (petPurchase == 0) {
				cout << "You leave empty-handed." << endl;
			}
			else {
				pet = 1;
				cout << "You leave with your new pet, excited to see what's next." << endl;
			}
		}
	}
	else {
		int r= rand() % 4;
		cout << "You continue to make your way to the Magical Menagerie." << endl;
		cout << "You enter the shop to hear a rucus of animals: toads, owls, cats, rats..." << endl;
		sleep(5);
		cout << "After looking around you find a " << petOptions[r] << " that catches your eye." << endl;
		cout << "You tell a store clerk and he retrieves the animal for you." << endl;
		cout << "The total is 14 Galleons, 15 Sickles, and 8 Knuts." << endl;
		int petPurchase = g.Transaction(14,15,8);
		if (petPurchase == 0) {
			cout << "You leave empty-handed." << endl;
		}
		else {
			pet = 1;
			cout << "You leave with your new pet, excited to see what's next." << endl;
		}
	}
	cout << "You open your list back up to see what's next: Books" << endl;
	cout << "You remember seeing a bookstore down the street and head over to the entrance: ";
	cout << "Flourish and Botts." << endl;
	sleep(5);
	int totalG, totalS, totalK;
	cout << "You find a selection of books and reference your list to find the ones you need." << endl;
	cout << "*****************************************************************************************" << endl;
	cout << "Fantastic Beasts and Where to Find Them by Newt Scamandar: " << endl;
	cout << "New: 7 Galleons, 15 Sickles, 403 Knuts  |   Used: 4 Galleons, 14 Sickles, 330 Knuts" << endl;
	cout << "*******************************************************************************" << endl;
	cout << "Advance Potion Making by Libatius Borage: " << endl;
	cout << "New: 9 Galleons, 2 Sickles, 238 Knuts   |   Used: 5 Galleons, 11 Sickles, 82 Knuts" << endl;
	cout << "*******************************************************************************" << endl;
	cout << "A Beginner's Guide to Transfiguration by Emeric Switch: " << endl;
	cout << "New: 6 Galleons, 13 Sickles, 98 Knuts   |   Used: 3 Galleons, 0 Sickles, 490 Knuts" << endl;
	cout << "*******************************************************************************" << endl;
	cout << "A History of Magic by Bathilda Bagshot: " << endl;
	cout << "New: 8 Galleons, 7 Sickles, 100 Knuts   |   Used: 5 Galleons, 2 Sickles, 35 Knuts" << endl;
	cout << "*******************************************************************************" << endl;
	/*First book selection*/
	cout << "Fantastic Beasts- new(1) or used(2): " ;
	cin >> book[0];
	book[0] = Error(book[0]);
	while (book[0] != 1 && book[0] != 2) {
		cout << "Invalid input. Try again." << endl;
		cout << "Fantastic Beasts- new(1) or used(2): ";
		cin >> book[0];
		book[0] = Error(book[0]);
	}
	if (book[0] == 1) {
		totalG = 7;
		totalS = 15;
		totalK = 403;
	}
	else {
		totalG = 4;
		totalS = 14;
		totalK = 330;
	}
	/*Second book selection*/
	cout << "Advance Potion Making- new(1) or used(2): ";
	cin >> book[1];
	book[1] = Error(book[1]);
	while (book[1] != 1 && book[1] != 2) {
		cout << "Invalid input. Try again." << endl;
		cout << "Advance Potion Making- new(1) or used(2): ";
		cin >> book[1];
		book[1] = Error(book[1]);
	}
	if (book[1] == 1) {
		totalG += 9;
		totalS += 2;
		totalK += 238;
	}
	else {
		totalG += 5;
		totalS += 11;
		totalK += 82;
	}
	/*Third book selection*/
	cout << "Beginner's Transfiguration- new(1) or used(2): ";
	cin >> book[2];
	book[2] = Error(book[2]);
	while (book[2] != 1 && book[2] != 2) {
		cout << "Invalid input. Try again." << endl;
		cout << "Beginner's Transfiguration- new(1) or used(2): ";
		cin >> book[2];
		book[2] = Error(book[2]);
	}
	if (book[2] == 1) {
		totalG += 6;
		totalS += 13;
		totalK += 98;
	}
	else {
		totalG += 3;
		totalS += 0;
		totalK += 490;
	}
	/*Fourth book selection*/
	cout << "History of Magic- new(1) or used(2): ";
	cin >> book[3];
	book[3] = Error(book[3]);
	while (book[3] != 1 && book[3] != 2) {
		cout << "Invalid input. Try again." << endl;
		cout << "History of Magic- new(1) or used(2): ";
		cin >> book[3];
		book[3] = Error(book[3]);
	}
	if (book[3] == 1) {
		totalG += 8;
		totalS += 7;
		totalK += 100;
	}
	else {
		totalG += 5;
		totalS += 2;
		totalK += 35;
	}
	int books = g.Transaction(totalG, totalS, totalK);
	if (books == 0) {
		cout << "You cannot pay for all your books" << endl;
		cout << "You decide to call it a day and go home." << endl;
	}
	else {
		cout << "Books in hand you walk out of the store and ";
		cout << "decide to finish your shopping another day." << endl;
		cout << "At home you crack open your new books and start learning some spells." << endl;
  }
		/*Exceptions*/
  if ( wand == 1) {
		try {
			string spell = SpellCasting();
			cout << "\"" << spell << "!\"" << endl;
			cout << "Your spell executes perfectly, you are a natural." << endl;
		}
		catch(string err_msg) {
			cout << err_msg << endl;
		}
	}
	return 0;
}
