#include <iostream>
class Wallet {
protected:
	int walletGalleons;
	int walletSickles;
	int walletKnuts;
//	int walletBalance;
public: 
    void walletBalance();
};

class Gringotts: public Wallet {
private:
	int Galleons;
	int Sickles;
	int Knuts;
	int Balance;
public:
	Gringotts();
	void balance();
	void withdraw();
	void deposit();
	void bank();
};
