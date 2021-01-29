//main file
#include <iostream>
#include <map>
//#include <fstream>
#include "includes/account.hpp"
#include "includes/storage.hpp"
#include "includes/io.hpp"
using namespace std;

string filename = "data.tmp";

int Menu(){
  cout << "\n------------------------------------------------------\n"
       << "What would you like to do? (retrieve/add/exit/r/a/e)\n"
       << " - retrieve a password\n"
       << " - add a new account\n"
       << " - exit\n";
  
  string input;
  cin >> input;
  while(!validInput(input, {"retrieve", "add", "exit", "r", "a", "e"})){
    cout << "Invalid input please use: retrieve/add/exit/r/a/e ";
    cin >> input;
  }
  if(input.compare("add") == 0 || input.compare("a") == 0){
    return 1;
  }else if(input.compare("retrieve") == 0 || input.compare("r") == 0){
    return 0;
  }
  return -1;
}

int main(){
  cout << "Welcome to SnapPass!\n";
   
  accList list = readAccList(filename);
  bool exit = false;

  while(!exit){
    int M = Menu();
    if(M == 1){
      //add account
      bool cont = true;
      while(cont){
	account acc = addAcc();
	list.insert(pair<string, account>(acc.accName, acc));
	
	cout << "would you like to add another account? (y/n/Y/N) ";
	string input;
	cin >> input;
	cont = yesOrNo(input);
      }
    }else if(M == 0){
      //retrieve account
      bool cont = true;
      while(cont){
	retrieveAcc(list);
	
	cout << "would you like to retrieve another account? (y/n/Y/N) ";
	string input;
	cin >> input;
	cont = yesOrNo(input);
      }
    }else{
      //M == -1
      exit = true;
    }
  }

  storeAccList(filename, list);
  return 0;
}
