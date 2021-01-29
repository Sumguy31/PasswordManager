#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool validInput(string s, vector<string> strArr){
  for(unsigned int i = 0; i < strArr.size(); i++){
    if(s.compare(strArr[i]) == 0){
      return true;
    }
  }
  return false;
}

bool yesOrNo(string s){
  while(!validInput(s, {"y","n","Y","N"})){
    cout << "Invalid input please use: y/n/Y/N";
    cin >> s;
  }
  if( s.compare("y") == 0 || s.compare("Y") == 0){
    return true;
  }
  return false;
}
