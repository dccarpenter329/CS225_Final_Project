#include <iostream>
#include "Gringotts.h"
using namespace std;

/*Wand input function*/
void Wand(int Height, int EyeColor, int Trait) {
	float length;
	cout << "****************************************************" << endl;
	if (Height==1) {
		cout << "Length= 9 3/4" << endl;
	}
	else if (Height==2) {
		cout << "Length= 10 5/6" << endl;
	}
	else if (Height==3) {
		cout << "Length= 10 1/4" << endl;
	}
	if (EyeColor==1) {
		cout << "Core: Phoenix Feather" << endl;
	}
	else if (EyeColor==2) {
		cout << "Core: Unicorn Hair" << endl;
	}
	else if (EyeColor==3) {
		cout << "Core: Dragon Heartstring" << endl;
	}
	if (Trait==1) {
		cout << "Wood: Larch" << endl;
	}
	else if (Trait==2) {
		cout << "Wood: Ash" << endl;
	}
	else if (Trait==3) {
		cout << "Wood: Poplar" << endl;
	}
	cout << "****************************************************" << endl;
}

/*Wand quiz function*/
void WandQuiz() {
	int height, eyeColor, trait;
	cout << "Enter your height (short=1, tall=2, average=3)" ;
	cin >> height;
	height = Error(height);
	while (height!=1 && height!=2 && height!=3) {
		cout << "Invalid input. Try again." << endl;
		cout << "Enter your average height (short=1, tall=2, average=3)";
		cin >> height;
		height = Error(height);
	}
	cout << "Enter your eye color (brown=1, green=2, blue=3)" ;
	cin >> eyeColor;
	eyeColor = Error(eyeColor);
	while (eyeColor!=1 && eyeColor!=2 && eyeColor!=3) {
		cout << "Invalid input. Try again." << endl;
		cout << "Enter your eye color (brown=1, green=2, blue=3)";
		cin >> eyeColor;
		eyeColor = Error(eyeColor);
	}
	cout << "Do you pride yourself most on your determination(1), loyalty(2), kindness(3)" ;
	cin >> trait;
	trait = Error(trait);
	while (trait!=1 && trait!=2 && trait!=3) {
		cout << "Invalid input. Try again." << endl;
		cout << "Do you pride yourself most on your determination(1), loyalty(2), kindness(3)";
		cin >> trait;
		trait = Error(trait);
	}
	Wand(height, eyeColor,trait);
}
