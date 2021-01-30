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

string takeInputs(vector<string> strArr){
  string input;
  cin >> input;
  while(!validInput(input, strArr)){
    cout << "Invalid input please use valid input: ";
    for(string str : strArr){
      cout << str;
      if(str != strArr.back()){
	cout << "/";
      }else{
	cout << " ";
      }
    }
    cin >> input;
  }
  return input;
}

bool yesOrNo(){
  string input = takeInputs({"y","n","Y","N"});
  /*while(!validInput(s, {"y","n","Y","N"})){
    cout << "Invalid input please use: y/n/Y/N ";
    cin >> s;
  }*/
  if( input.compare("y") == 0 || input.compare("Y") == 0){
    return true;
  }
  return false;
}
