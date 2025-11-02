#include <iostream>
#include <fsream> 
using namespace std;

Gringotts::Gringotts() {
  cout << "Would you like to check your account balance (1), deposit money (2), or withdraw money (3)? ";
  cin>> choice;
  while (choice!=1 && choice!=2 && choice!=3) {
    cout << "Invalid input, please enter again."<<endl;
    cout << "Would you like to check your account balance (1), deposit money (2), or withdraw money (3)? ";
    cin << choice;
  }
  if (choice==1) {
    cout <<  
  }
  else if (choice==2) {

  }
  else if (choice==3) {

  }
  else {
  
