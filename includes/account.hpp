#ifndef _account_hpp_
#define _account_hpp_
#include <string>
#include <vector>
#include <map>

class account {
    int access_num;
  public:
    std::string username;
    std::string password;
    std::string email;
    std::string accName;
};

typedef std::map<std::string, account> accList;

bool validInput(std::string s, std::vector<std::string> strArr);
bool yesOrNo(std::string s);
account addAcc();
void retrieveAcc(accList list);
void editAcc(accList list);
void printAccAttribute(std::string name, std::string str);
void printAccount(account acc);



#endif
