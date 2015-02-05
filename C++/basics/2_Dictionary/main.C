/*
Jacob Gamez
CS211
Assignment 2
3-25-14

This program uses a class Dictionary to create sorted dictionary files that add, print, delete, and
search words individually or whole files at a time.
The functions are dictated by an input file that the user inputs.
 */

#ifndef MAIN_C
#define MAIN_C

using namespace std;

//Include dictionary class header file
#include "dictionary.h"

int main()
{
  Dictionary DictForCS211;
  DictForCS211.ProcessTransactionFile();
  return 0;
}

#endif
