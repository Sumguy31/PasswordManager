//main file
#include <iostream>
#include <map>
//#include <fstream>
#include "includes/account.hpp"
#include "includes/storage.hpp"
#include "includes/io.hpp"
using namespace std;

bool Menu(){
  cout << "What would you like to do? (retrieve/add/r/a)\n";
  cout << " - retrieve a password\n"; 
  cout << " - add a new account\n";
  
  string input;
  cin >> input;
  while(!validInput(input, {"retrieve", "add", "r", "a"})){
    cout << "Invalid input please use: retrieve/add/r/a ";
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
   
  accList list;

  if(Menu()){
    bool cont = true;
    while(cont){
      account acc = addAcc();
      list.insert(pair<string, account>(acc.accName, acc));
      
      cout << "would you like to add another account? (y/n/Y/N) ";
      string input;
      cin >> input;
      cont = yesOrNo(input);
    }
  }

  storeAccList("data.sp", list);
/*  map<string, account>::iterator itr;
  for(itr = list.begin(); itr != list.end(); itr++){
    cout << itr->first + "\n";
    storeAcc("data.sp", itr->second);
  }*/
  return 0;
}
