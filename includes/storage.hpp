#ifndef _storage_hpp_
#define _storage_hpp_

void storeAcc(std::string filename, account acc);

void storeAccList(std::string filename, accList acc);

account readAcc(std::string str);
accList readAccList(std::string filename);


#endif
