#ifndef SECURE_H
#define SECURE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Secure
{
 private:
  vector<string> message; //The message will be stored in here

 public:
  void encryptrot(int);//Encrypt via rotation
  void encryptgram();//Encrypt via cryptogram
  void decryptrot(int);//Decrypt via rotation
  void decryptgram();//Decrypt via cryptogram
};

#endif
