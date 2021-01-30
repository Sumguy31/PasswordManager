#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include "includes/account.hpp"
#include "includes/io.hpp"
using namespace std;

account addAcc(){
  account new_acc;
  cout << "What account would you like to add? ";
  cin >> new_acc.accName;
  transform(new_acc.accName.begin(), new_acc.accName.end(),
	    new_acc.accName.begin(), 
	    [](unsigned char c){ return tolower(c); });

  cout << "Would you like to add a username?(y/n/Y/N) ";
  if(yesOrNo()){
    cout << "What is your username? ";
    cin >> new_acc.username;
  }
    
  cout << "Would you like to add a email?(y/n/Y/N) ";
  if(yesOrNo()){
    cout << "What is your email? ";
    cin >> new_acc.email;
  }
  
  cout << "Do you have a password already?(y/n/Y/N) ";
  if(yesOrNo()){
    cout << "What is your password? ";
    cin >> new_acc.password;
  }else{
    cout << "Generating password...(Not implemented)\n";
    cout << "using suggested password: password\n";
    new_acc.password = "password";
  }

  return new_acc;
}

void retrieveAcc(accList list){
  cout << "what account would you like to retrieve? ";
  string accName;
  cin >> accName;
  cout << "\n";
  printAccount(list[accName]);
}

void editAcc(accList list){
  if (list.size() < 1){
    cout << "No accounts found\n";
    return;
  }
  cout << "what account would you like to edit? ";
  string accName;
  cin >> accName;
  account acc = list[accName];
  bool exit = false;
  while(!exit){
    cout << "\n-----------------------------------------\n"
	 << "what would you like to change?:"
	 << " - (delete) the account"
	 << " - change (email)"
	 << " - change (username)"
	 << " - change (password)"
	 << " - (exit)";
    string input = takeInputs({"delete", "email", "username", "password", "exit"});

    if(input.compare("delete") == 0){
      cout << "Are you sure? (y/n/Y/N)";
      if(yesOrNo()){
	list.erase(accName);
	exit = true;
      }
    }else if(input.compare("email") == 0){
      cout << "what do you want to change it to? ";
      cin >> acc.email;
    }else if(input.compare("username") == 0){
      cout << "what do you want to change it to? ";
      cin >> acc.username;
    }else if(input.compare("password") == 0){
      cout << "what do you want to change it to? ";
      cin >> acc.username;
    }else{
      exit = true;
    }
  }
}

//prints string if it is none empty
void printAccAttribute(string name, string str){
  if(str != ""){
    cout << '\t' + name + ": " + str + '\n';
  }
}

void printAccount(account acc){
  cout << acc.accName + '\n';
  printAccAttribute("username", acc.username);
  printAccAttribute("email", acc.email);
  printAccAttribute("password", acc.password);
}
