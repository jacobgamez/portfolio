#ifndef DGRAPH_H
#define DGRAPH_H

//*************************************************************************************************
// Name: Jacob Gamez
// Compiler: g++
// File Type: C++ Header File for dgraph class
// Purpose: Declare the dgraph class and its attributes and affiliates
//*************************************************************************************************/


#include <iostream>
#include "slist.h"
using namespace std;

const int SIZE = 20;

// this will be in each GTable slot
struct Gvertex
{
  char vertexName;       //the vertex Name
  int outDegree;//the Out degree
  slist adjacentOnes;   //the adjecent vertices in an slist
  int visit;            // This will hold the visit number in HW7 
};

class dgraph
{
 private:
  Gvertex Gtable[SIZE];
  int  countUsed; // how many slots of the Gtable are actually used
  
 public:
  
  dgraph();    // initialize vertexName (blank) and visit numbers (0)
               // initialize countUsed to be 0
  ~dgraph();   // delete all nodes of slists in table
  // Question: If we do not do this, will the llist destructor
  // be called automatically???
  
  void fillTable();   // read from the input file table.txt and fill GTable
  
  void displayGraph();  // displays in an easy to read format 
  
  int findOutDegree(char);  // returns the out degree of a given vertex
  
  slist findAdjacency(char);  // returns the adjacency list of a given vertex
  
  void visit(int,el_t);  //assigns a visit number to the vertex name provided.
  
  bool isMarked(el_t); //checks if a vertex is marked and if it is, provides the name of said vertex to the user.
};

#endif // DGRAPH_H
