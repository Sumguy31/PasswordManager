#include <iostream>
#include <string>
#include <vector>
#include "includes/account.hpp"
#include "includes/io.hpp"
using namespace std;

account addAcc(){
  account new_acc;
  cout << "What account would you like to add? ";
  cin >> new_acc.accName;

  cout << "Would you like to add a username?(y/n/Y/N) ";
  string str;
  cin >> str;
  if(yesOrNo(str)){
    cout << "What is your username? ";
    cin >> new_acc.username;
  }
    
  cout << "Would you like to add a email?(y/n/Y/N) ";
  cin >> str;
  if(yesOrNo(str)){
    cout << "What is your email? ";
    cin >> new_acc.email;
  }
  
  cout << "Do you have a password already?(y/n/Y/N) ";
  cin >> str;
  if(yesOrNo(str)){
    cout << "What is your password? ";
    cin >> new_acc.password;
  }else{
    cout << "Generating password...(Not implemented)\n";
    cout << "using suggested password: password\n";
    new_acc.password = "password";
  }

  return new_acc;
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
