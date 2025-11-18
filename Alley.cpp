/*References: https://www.geeksforgeeks.org/cpp/multiset-in-cpp-stl/ */
#include <iostream>
#include <fstream>
#include <set>
#include <unistd.h>
#include <cstdlib>
#include "Gringotts.h"
using namespace std;

/*Function when player enters alley*/
int Alley() {
	srand(time(NULL)); // Seeding random number generator
	int choice, i,x = 0;
	int Pet = 0;
	string wordBank[3]= {"hippogriff", "azkaban", "basilisk"};
	multiset<char> word; // Initializing multiset to sort word characters in order
	cout << "You walk over to the witch" << endl;
	cout << "\"You're looking for a pet aren't you?\" she says." << endl;
	sleep(5);
	cout << "How does she know that?" << endl;
	cout << "\"Yes, why?\"" << endl;
	cout << "\"I have one that might tempt you more than any in Magical Menagerie\"" << endl;
	sleep(5);
	cout << "\"And what would that be\"" << endl;
	cout << "\" A phoenix. All you have to do to is unscramble a word and he is yours.\"" << endl;
	cout << "\"Would you like to play?\" (Yes=1, No=2)" << endl;
	cin >> choice;
	choice = Error(choice);
	while (choice!=1 && choice!=2) {
		cout << "Invalid input. Try again." << endl;
		cout << "\"Would you like to play?\" (Yes=1, No=2)";
		cin >> choice;
		choice = Error(choice);
	}
	int r = rand() % 3;
	for (i=0; i<wordBank[r].size(); i++) {
		word.insert(wordBank[r][i]);
	}
	cout << "Unscramble: ";
	for(char c : word) { // Range based sorting
		cout << c << " ";
	}
	cout << endl;
	cout << "You have 3 guesses" << endl;
	int count=3;
	int ii=1; // Attempt counter
	string guess;
	do {
		cin >> guess;
		if (guess== wordBank[r]) {
			cout << "You guessed correct, very good!" << endl;
			cout << "The phoenix is now yours- take great care of him." << endl;
			x=1; // pet=1
			/*Phoenix ascii art*/
			ifstream fn("ascii_art_phx.txt");
			string header[14];
			for (i=0; i<14; i++) {
				getline(fn, header[i]);
				cout << header[i] << endl;
			}
			fn.close();
		}
		else {
			cout << "Incorrect. Guess again." << endl;
			ii++;
		}
	} while (ii<=count && x!=1);
	return x;
}
