#include <iostream>
#include <string>
#include <fstream>
#include "includes/account.hpp"
using namespace std;

void storeAcc(string filename, account acc){
  ofstream file;
  file.open(filename);
  file << acc.accName + ";" + acc.email + ";" + acc.username + ";" + acc.password + "\n";
  file.close();
}

void readData(string filename){
  ifstream file;
  file.open(filename);
  string str;
  file >> str;
  cout << str;
}
