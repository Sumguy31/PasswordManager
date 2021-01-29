#include <iostream>
#include <string>
#include <fstream>
#include "includes/account.hpp"
using namespace std;

string delimiter = ";";

void storeAcc(string filename, account acc){
  ofstream file;
  file.open(filename);
  file << acc.accName + delimiter + acc.email + delimiter 
       << acc.username + delimiter + acc.password + "\n";
  file.close();
}

void storeAccList(string filename, accList list){
  ofstream file;
  file.open(filename);
  accList::iterator itr;
  for(itr = list.begin(); itr != list.end(); itr++){
  file << itr->second.accName + delimiter + itr->second.email + delimiter 
       << itr->second.username + delimiter + itr->second.password + "\n";
  }
  file.close();
}

account readAcc(string str){
  account new_acc;
  unsigned int pos = str.find(delimiter);
  new_acc.accName = str.substr(0,pos);
  str.erase(0, pos + delimiter.length());
  
  pos = str.find(delimiter);
  new_acc.email = str.substr(0,pos);
  str.erase(0, pos + delimiter.length());
    
  pos = str.find(delimiter);
  new_acc.username = str.substr(0,pos);
  str.erase(0, pos + delimiter.length());

  new_acc.password = str;
  printAccount(new_acc);
  return new_acc;
}

accList readAccList(string filename){
  ifstream file;
  file.open(filename);
  string str;
  
  accList list;
  while(getline(file, str)) {
    account new_acc = readAcc(str);
    list.insert(pair<string, account>(new_acc.accName, new_acc));
  }
  return list;
}
