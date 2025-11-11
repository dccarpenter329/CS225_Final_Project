#include <iostream>
using namespace std;
void wand();
void wandQuiz();
int error(int);

//Global Variables
int wand;
//void cost(int, int, int, BankAccount&); 
//void bank(Gringotts&);
class Wallet {
protected:
	int walletGalleons;
	int walletSickles;
	int walletKnuts;
public: 
    void walletBalance();
};
class BankAccount {
protected: 
  string Keyword;
  string Name;
 	int Galleons;
	int Sickles;
	int Knuts;
	int Balance;
public:
  BankAccount(string k, string n) {Keyword=k; Name=n;}
  friend ostream& operator<<(ostream& out, BankAccount& temp);
  int setGalleons(int G) {Galleons=G;}
  int setSickles(int S) {Sickles=S;}
  int setKnuts(int K) {Knuts=K;}
  int& getGalleons() {return Galleons;}
  int& getSickles() {return Sickles;}
  int& getKnuts() {return Knuts;}
  string& getName() {return Name;}
};

class Gringotts: public Wallet {
private:
  BankAccount bankAccount;
public:
	Gringotts(string,string);
  void transaction();
	void balance();
	void withdraw();
	void deposit();
	//void bank(Gringotts&);
};
