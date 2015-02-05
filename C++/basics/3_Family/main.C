/*****************************************************
 Jacob Gamez
 5/8/2014
 
 This program processes a transaction file that manages a linked list data structure
 as if it were a family. 
*****************************************************/

#ifndef MAIN_C
#define MAIN_C

#include <iostream>
using namespace std;

#include "family.h"

int main()
{
  Family USAFamilies;
  USAFamilies.ReadTransactionFile();
  return 0;
} 

#endif
