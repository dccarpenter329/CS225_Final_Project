#include <iostream>
#include "Gringotts.h"

string SpellCasting() {
	string s;
	/*Exception error message*/
	const string MSG= "The spell backfires on yourself and you go unconscious.";
	cout << "With all your supplies you can now cast your first spell!" << endl;
	cout << "Enter your first spell: ";
	cin.ignore(200,'\n');
	getline(cin, s, '\n'); // Read in spell
	/* Exception throw block*/
	if (s== "stupefy" || s== "Stupefy" )
		throw(MSG); // Throw an error message to catch block
	return s; // Return the spell string
}
