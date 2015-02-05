#ifndef SECURE_C
#define SECURE_C

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "secure.h"

void Secure :: encryptrot(int rotation)
{
  string temporary;
  ifstream inf;
  ofstream outf;
  inf.open("original.txt");//The source message to be encrypted
  outf.open("encrypted.txt");//The destination where the encrypted message will be saved

  //In case the input file does not exist
  if(!inf)
    {
      cout << "Cannot Proceed! Input file \"source.txt\" not found!\n";
      return;
    }

  //Read the unencrypted message into vector "message" from input file
  while(!inf.eof())
    {
      inf >> temporary;
      message.push_back(temporary);
    }
  
  //Here the encryption process begins
  //Cycle through each word
  for (int i=0; i<message.size(); i++)
    {
      //Cycle through each character within each word
      for (int k=0; k<message[i].size(); k++)
	{
	  //If the character is an uppercase letter, convert to lower case. Otherwise, just continue
	  if (message[i][k]>=65 && message[i][k]<=90)
	    message[i][k]+=32;

	  //If the character is a lowecase letter, encrypt by the user-defined rotation. This ignores punctuation.
	  //It is impossible to have an uppercase letter at this point, because all uppercase letters have already been converted to lowercase.
	  if (message[i][k]>=97 && message[i][k]<=122)
	    {
	      message[i][k]%=96;//Lowers characters to minimum values in case rotation is too high for char value
	      message[i][k]+=rotation;

	      //In case the rotation is greater than 'z', wrap back to the beginning of the alphabet
	      if (message[i][k]>26)
		  message[i][k]%=26;

	      //After the wrapping process, a 'z' will equal zero
	      //To give 'z' the proper value, reassign as 'z'
	      if (message[i][k]==0)
		message[i][k]=26;

	      //Increase characters back to proper decimal values
	      message[i][k]+=96;
	    }
        }
      //A conditional statment so that the output file doesn't end with a whitespace
      if (i==message.size()-1)
	outf << message[i];
      else
	outf << message[i] << " ";
    }

  inf.close();
  outf.close();

  cout << "Finished!!!\n";

  return;
}

void Secure :: encryptgram()
{
  string key;
  string temporary;
  ifstream inf;
  ifstream keyf;
  ofstream outf;
  inf.open("original.txt");
  keyf.open("key.txt");
  outf.open("encrypted.txt");

  //In case the source file does not exist
  if (!inf)
    {
      cout << "Cannot proceed! Input file \"original.txt\" does not exist!\n";
      return;
    }

  //In case the key file does not exist
  if (!keyf)
    {
      cout << "Cannot proceed! Input file \"key.txt\" does not exist!\n";
      return;
    }

  //Retrieve message to be encrypted
  while(!inf.eof())
    {
      inf >> temporary;
      message.push_back(temporary);
    }

  //Retrieve Key
  keyf >> key;
 
  //Cycle through each word
  for (int i=0; i<message.size(); i++)
    {
      //Cycle through each letter
      for (int k=0; k<message[i].size(); k++)
	{
	  //If the character is upper-csae, convert to lower-case
	  if (message[i][k]>=65 && message[i][k]<=90)
	    message[i][k]+=32;

	  //If the character is a lowercase letter, encrypt by comparing to key string
	  if (message[i][k]>=97 && message[i][k]<=122)
	      message[i][k]=key[message[i][k]-97];	      
	}
      
      //Conditional statement to avoid ending in a whitespace
      if(i==message.size()-1)
	outf << message[i];
      else
	outf << message[i] << " ";
    }

  outf.close();
  inf.close();
  keyf.close();

  cout << "Finished!!!\n";

  return;
}

void Secure :: decryptrot(int rotation)
{
  string temporary;
  ifstream inf;
  ofstream outf;
  inf.open("encrypted.txt");//The source message to be decrypted
  outf.open("decrypted.txt");//The destination where the decrypted message will be saved

  //In case the input file does not exist
  if(!inf)
    {
      cout << "Cannot Proceed! Input file \"vault.txt\" not found!\n";
      return;
    }

  //Read the encrypted message into vector "message" from input file
  while(!inf.eof())
    {
      inf >> temporary;
      message.push_back(temporary);
    }
  
  //Here the decryption process begins
  //Cycle through each word
  for (int i=0; i<message.size(); i++)
    {
      //Cycle through each character within each word
      for (int k=0; k<message[i].size(); k++)
	{
	  //If the character is a lowecase letter, decrypt using the user-defined rotation. This ignores punctuation.
	  //It is impossible to have an uppercase letter at this point, because all uppercase letters have already been converted to lowercase (during encryption).
	  if (message[i][k]>=97 && message[i][k]<=122)
            {
              message[i][k]%=96;//Lowers characters to minimum values in case rotation is too high for char value
              message[i][k]-=rotation;

	      //In case the rotation is less than 'a', wrap to end of alphabet
	      if (message[i][k]<0)
		message[i][k]+=26;

              //After the wrapping process, a 'z' will equal zero
              //To give 'z' the proper value, reassign as 'z'
              if (message[i][k]==0)
                message[i][k]=26;

              //Increase characters back to proper decimal values
              message[i][k]+=96;
            }
        }

      //A conditional statment so that the output file doesn't end with a whitespace
      if (i==message.size()-1)
	outf << message[i];
      else
	outf << message[i] << " ";
    }

  inf.close();
  outf.close();

  cout << "Finished!!!\n";

  return;

}

void Secure :: decryptgram()
{
  //int s;
  string key;
  string temporary;
  ifstream inf;
  ifstream keyf;
  ofstream outf;
  inf.open("encrypted.txt");
  keyf.open("key.txt");
  outf.open("decrypted.txt");

  //In case the source file does not exist
  if (!inf)
    {
      cout << "Cannot proceed! Input file \"encrypted.txt\" does not exist!\n";
      return;
    }

  //In case the key file does not exist
  if (!keyf)
    {
      cout << "Cannot proceed! Input file \"key.txt\" does not exist!\n";
      return;
    }

  //Retrieve message to be decrypted
  while(!inf.eof())
    {
      inf >> temporary;
      message.push_back(temporary);
    }

  //Retrieve Key
    keyf >> key;

    //Cycle through each word
  for (int i=0; i<message.size(); i++)
    {
      //Cycle through each letter
      for (int k=0; k<message[i].size(); k++)
        {
	  //Impossible to have a capital letter due to the encryption process

	  //Decrypt by finding index, then adding to decimal value
	  if (message[i][k]>=97 && message[i][k]<=122)
	    {
	      for (int s=0; s<key.size(); s++)
		{
		  if (message[i][k]==key[s])
		    {
		      message[i][k]=s+97;
		      break;
		    }
		}
	      
	    }
        }

      //Avoid ending in whitespace
      if(i==message.size()-1)
        outf << message[i];
      else
        outf << message[i] << " ";
    }

  outf.close();
  inf.close();
  keyf.close();

  cout << "Finished!!!\n";

  return;
}

#endif
