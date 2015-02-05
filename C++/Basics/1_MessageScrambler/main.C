/******************************************
Jacob Gamez
25 February 2014

-----------------------------------------------------------------------------------
This program allows you to encrypt files using the rotation and cryptogram methods,
and allows you to decrypt files that were encrypted using the same methods.
-----------------------------------------------------------------------------------

-The source file should be called "original.txt"
-Any encrypted file generated will be called "encrypted.txt"
-The key for encryption via cryptogram should be placed in a file called "key.txt"
-->Please be sure that the source file does not contain spaces or indentations after the final character
   of the message
-->Please be sure that the "key.txt" file does not contain any spaces.
**********************************************/

#ifndef MAIN_C
#define MAIN_C

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//Include the Secure class, which contains all encryption capabilities
#include "secure.h"

int main()
{
  Secure message;
  char choice;
  int rotation;

  cout << "Would you like to encrypt or decrypt (e/d)? ";
  cin >> choice;

  //ENCRYPTION
  if (choice=='E' || choice=='e')
    {
      cout << "Would you like to use rotation or cryptogram (r/c)? ";
      cin >> choice;

      //Encrypt by rotaion
      if (choice=='r' || choice=='R')
	{
	  cout << "Rotate by how many? ";
	  cin >> rotation;

	  //In case the user inputs a negative rotation 
	  if (rotation<0)
	    {
	      cout << "Please use a positive number.\n";
	      return 0;
	    }

	  //In case the user inputs a redundantly high rotation, decrease to a non-redundant size
	  while (rotation>=26)
	      rotation%=26;

	  //In case the user uses a rotation that does not cause any rotation
	  if (rotation==0)
	    cout << "***Warning: This rotation will not encrypt message***\n";

	  message.encryptrot(rotation);
	}

      //Encrypt by cryptogram
      else if (choice=='C' || choice=='c')
	message.encryptgram();

      //In case the user makes an invalid selection
      else
	{
	  cout << "Invalid choice! Please try again!\n";
	  return 0;
	}
    }


  //DECRYPTION
  else if (choice=='D' || choice=='d')
    {
      cout << "Was the message encrypted using rotation or cryptogram (r/c): ";
      cin >> choice;

      //Decrypt by rotation
      if (choice=='R' || choice=='r')
	{
	  cout << "What was the rotation used for encryption? ";
	  cin >> rotation;

	  //In case the user inputs a negative rotation
	  if (rotation<0)
            {
              cout << "Please use a positive number.\n";
              return 0;
            }

          //In case the user inputs a redundantly high rotation, decrease to a non-redundant size
	  while (rotation>=26)
	    rotation%=26;

          //In case the user uses a rotation that does not cause any rotation
          if (rotation==0)
            cout << "***Warning: This rotation will not decrypt message***\n";

	  message.decryptrot(rotation);
	}
      else if (choice=='C' || choice=='c')
	message.decryptgram();

      //In case the user makes an invalid selection
      else
        {
          cout << "Invalid choice! Please try again!\n";
	  return 0;
        }

    }

  //In case the user makes an invalid selection                                                                                                                              
  else
    {
      cout << "Invalid choice! Please try again!\n";
      return 0;
    }

  return 0;
}

#endif
