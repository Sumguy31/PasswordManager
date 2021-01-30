//main file
#include <iostream>
#include <map>
#include "includes/account.hpp"
#include "includes/storage.hpp"
#include "includes/io.hpp"
using namespace std;

string filename = "data.tmp";

int Menu(){
  cout << "\n------------------------------------------------------\n"
       << "What would you like to do? (retrieve/add/edit/exit)\n"
       << " - retrieve an account\n"
       << " - edit an existing account\n"
       << " - add a new account\n"
       << " - exit\n";
  
  string input = takeInputs({"retrieve", "add", "edit", "exit"});
  if(input.compare("add") == 0){
    return 1;
  }else if(input.compare("retrieve") == 0){
    return 0;
  }else if(input.compare("edit") == 0){
    return 2;
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
	cont = yesOrNo();
      }
    }else if(M == 0){
      //retrieve account
      bool cont = true;
      while(cont){
	retrieveAcc(list);
	cout << "would you like to retrieve another account? (y/n/Y/N) ";
	cont = yesOrNo();
      }
    }else if(M == 1){
      //edit account
      editAcc(list);
    }else{
      //M == -1
      exit = true;
    }
  }

  storeAccList(filename, list);
  return 0;
}
