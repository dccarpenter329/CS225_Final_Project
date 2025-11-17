#include <iostream>
#include "Gringotts.h"
#include <vector>
#include <set>
#include <unistd.h>
#include <cstdlib>
//https://www.geeksforgeeks.org/cpp/multiset-in-cpp-stl/
using namespace std;

void Alley() {
	srand(time(NULL));
	int choice, i;
	string wordBank[3]= {"hippogriff", "azkaban", "basilisk"};
	multiset<char> word;
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
	//choice = error(choice);
	while (choice!=1 && choice!=2) {
		cout << "Invalid input. Try again." << endl;
		cout << "\"Would you like to play?\" (Yes=1, No=2)";
		cin >> choice;
		//choice = error(choice);
	}
	int r = rand() % 4;
	for (i=0; i<wordBank[r].size(); i++) {
		word.insert(wordBank[r][i]);
		//cout << word[i];
	}
	cout << "Unscramble: ";
	for(char c : word) {
		cout << c << " ";
	}
	cout << endl;
	cout << "You have 3 guesses" << endl;
	int count=3;
	int ii=1;
	string guess;
	int pet=0;
	do {
		cin >> guess;
		if (guess== wordBank[r]) {
			cout << "You guessed correct, very good!" << endl;
			cout << "The phoenix is now yours- take great care of him." << endl;
			pet=1; // fix int- is global variable in header file
			//read in phoenix ascii art
			//ii=count;
		}
		else {
			cout << "Incorrect. Guess again." << endl;
			ii++;
		}
	} while (ii<=count && pet!=1);
	if (pet!=1) {
		cout << "Your lack of cleverness disappoints me." << endl;
		cout << "You do not deserve a phoenix as your companion. Be gone!" << endl;
		pet = 0;
	}
}







