//main file
#include <iostream>
#include <map>
//#include <fstream>
#include "includes/account.hpp"
#include "includes/storage.hpp"
#include "includes/io.hpp"
using namespace std;

bool Menu(){
  cout << "What would you like to do? (retrieve/add/r/a)\n"'
  cout << " - retrieve a password\n"; 
  cout << " - add a new account\n";
  
  string input;
  cin >> input;
  while(!validInput(input, {"retrieve", "add", "r", "a"})){
    cout << "Invalid input please use: retrieve/add/r/a";
    cin >> input;
  }
  if(input.compare("add") == 0 || input.compare("a") == 0){
    return true;
  }
  return false;
}

int main(){
  cout << "Welcome to SnapPass!\n";
  //readData("data.sp");
   
  map<string, account> accList;

  if(Menu()){
    bool cont = true;
    while(cont){
      account acc = addAcc();
      accList.instert(pair<string, account>(acc.accName, acc));
      
      cout << "would you like to add another account? (y/n/Y/N)";
      string input;
      cin >> input;
      cont = yesOrNo(input);
    }

  storeAcc("data.sp", acc);
  return 0;
}
