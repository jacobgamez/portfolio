//DICTIONARY CLASS IMPLEMENTATION FILE
#ifndef DICTIONARY_C
#define DICTIONARY_C

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "dictionary.h"//include the dictionary class declaration

bool Dictionary::failure=false;
bool Dictionary::success=true;

//Default constructor
Dictionary::Dictionary():maxWordsInDict(10000),maxWordsPerFile(100)
{
  totalWordsInDict=0;
  for(int i=0; i<26; i++)
      numOfWordsInFile[i]=0;
}

//Custom constructor
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords):maxWordsInDict(dictMaxWords),maxWordsPerFile(fileMaxWords)
{
   totalWordsInDict=0;
  for(int i=0; i<26; i++)
    numOfWordsInFile[i]=0;
}

//AddW function
bool Dictionary::AddAWord(string word)
{
  string FileName="#.txt";
  ofstream outf;

  //Open the correct file in dictionary
  FileName[0]=toupper(word[0]);
  outf.open(FileName.data(), ios::app);

  //If the word exists already, exit and failure
  if (SearchForWord(word)==(Dictionary::success))
    return (Dictionary::failure);

  //If the file and dictionary aren't too large, add word, if they are, fail
  if(totalWordsInDict<maxWordsInDict && numOfWordsInFile[toupper(word[0])-65]<maxWordsPerFile)
    {
      totalWordsInDict++;
      numOfWordsInFile[toupper(word[0])-65]++;
    }
  else
    return (Dictionary::failure);

  //Make word lowercase before entering
  for(int i=0; i<word.size(); i++)
    word[i]=tolower(word[i]);

  outf << word << endl;

  return (Dictionary::success);
}

//DeleteW Function
bool Dictionary::DeleteAWord(string word)
{
  string temp;
  vector<string> contents;
  string FileName="#.txt";
  ifstream inf;
  ofstream outf;

  //Open proper file
  FileName[0]=toupper(word[0]);
  inf.open(FileName.data());

  //If word already exists, fail
  if(SearchForWord(word)==false)
    return(Dictionary::failure);

  //Find word and delete
  while(inf)
    {
      inf >> temp;
      contents.push_back(temp);
    }

  for (int i=0; i<contents.size(); i++)
    {
      if(contents[i]==word)
	{
	  contents.erase(contents.begin()+i);
	  break;
	}
    }
  
  inf.close();

  totalWordsInDict--;

  numOfWordsInFile[toupper(word[0])-65]--;

  outf.open(FileName.data());
  
  //Write revised file back
  for (int i=0; i<contents.size(); i++)
    outf << contents[i] << endl;

  outf.close();

  return (Dictionary::success);
}

//SearchW Function
bool Dictionary::SearchForWord(string word)
{
  ifstream inf;
  string FileName="#.txt";
  vector<string> contents;
  string temp;

  //Open proper file
  FileName[0]=toupper(word[0]);
  inf.open(FileName.data());

  //Find word, if found return success
  while(inf)
    {
      inf >> temp;
      contents.push_back(temp);
    }

  for(int i=0; i<contents.size(); i++)
    {
      if(contents[i]==word)
	return(Dictionary::success);
    }

  inf.close();

  //If not successful, return failure
  return(Dictionary::failure);
}

//PrintF Function
bool Dictionary::PrintAFileInDict(string filename)
{
  ifstream inf;
  vector<string> contents;
  string temp;

  inf.open(filename.data());

  //In case file does not exist
  if(!inf)
    return(Dictionary::failure);

  //Load contents
  while(inf)
    {
      inf >> temp;
      contents.push_back(temp);
    }

  //Header to organize output
  cout << "File contains: \n";

  //Print contents
  for(int i=0; i<contents.size(); i++)
    {
      for(int k=0; k<5; k++)
	{
	  if(i<contents.size())
	    cout << contents[i] << " ";
	  i++;
	}

      cout << endl;
    }

  cout << endl;

  inf.close();

  return(Dictionary::success);
}

//SpellCheck Function
bool Dictionary::SpellChecking(string filename)
{
  ifstream inf;
  string temp;

  inf.open(filename.data());

  if(!inf)
    return(Dictionary::failure);

  //Header to organize output
  cout << "Misspelled Words: \n";

  //Check all words
  while(inf)
    {
      inf >> temp;

      //Since dictionary words are in lowercase, convert to lowercase for comparison
      for(int i=0; i<temp.size(); i++)
	temp[i]=tolower(temp[i]);

      //compare word to dictionary
      if(SearchForWord(temp)==false)
	cout << temp << endl;
    }

  cout << endl;

  inf.close();

  return(Dictionary::success);
}

//InsertF Function
bool Dictionary::InsertWordsIntoDict(string filename)
{
  ifstream inf;
  vector<string> contents;
  string temp;

  inf.open(filename.data());

  if(!inf)
    return(Dictionary::failure);

  //Cycle through all words and add to dictionary those which don't already exist
  while(inf)
    {
      inf >> temp;
      if(SearchForWord(temp)==false)
	AddAWord(temp);
    }

  inf.close();

  return(Dictionary::success);
}

//Called by main
void Dictionary::ProcessTransactionFile()
{
  ifstream inf;
  string filename, command, info;
  cout << "Please enter the transaction file name: ";
  cin >> filename;

  inf.open(filename.data());

  //In case the file doesn't exist
  if(!inf)
    {
      cout << "Error! File " << filename << " does not exist!\n";
      return;
    }

  //Direct transaction commands to their functions
  while(inf)
    {
      inf >> command >> info;

      if(command=="AddW")
	AddAWord(info);

      else if(command=="DeleteW")
	DeleteAWord(info);

      else if(command=="SearchW")
	SearchForWord(info);

      else if(command=="PrintF")
	PrintAFileInDict(info);

      else if(command=="SpellCheck")
	SpellChecking(info);

      else if(command=="InsertF")
	InsertWordsIntoDict(info);

      else
	{
	  cout << "Error! Command " << command << " is not valid!\n";
	  return;
	}
    }

  inf.close();
}

#endif
