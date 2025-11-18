#include <iostream>
using namespace std;
/*Function Declarations*/
void Wand();
void WandQuiz();
int Error(int);
int Alley();
string SpellCasting();

/*Global Variables*/
extern int wand;
extern int pet;

/*Wallet Class*/
class Wallet {
protected:
	int walletGalleons;
	int walletSickles;
	int walletKnuts;
public:
	void walletBalance();
	int getConversion();
};

/*Bank Account Class*/
class BankAccount {
protected:
	string Name;
	int Galleons;
	int Sickles;
	int Knuts;
public:
	friend ostream& operator<<(ostream& out, BankAccount& temp);
	BankAccount(string n) {Name=n;}
	int setGalleons(int G) {Galleons=G;}
	int setSickles(int S) {Sickles=S;}
	int setKnuts(int K) {Knuts=K;}
	int& getGalleons() {return Galleons;}
	int& getSickles() {return Sickles;}
	int& getKnuts() {return Knuts;}
	string& getName() {return Name;}
};

/*Gringotts bank Class*/
class Gringotts: public Wallet {
private:
	BankAccount bankAccount;
public:
	Gringotts(string);
  ~Gringotts();
	void withdraw();
	int Transaction(int, int, int);
};
