#ifndef DGRAPH_C
#define DGRAPH_C

//*************************************************************************************************
//Name: Jacob Gamez
//Compiler: g++
//File type: C++ implementation file for dgraph class
//Purpose: Implement the functions describes in the dgraph class header file
//*************************************************************************************************/

#include <iostream>
#include <fstream>
#include "dgraph.h"
using namespace std;



dgraph::dgraph()// initialize vertexName (blank) and visit numbers (0)// initialize countUsed to be 0
{
  Gtable[SIZE].vertexName = ' ';
  Gtable[SIZE].visit = 0;
  countUsed = 0;
}
dgraph::~dgraph()   // delete all nodes of slists in table// 
{
  el_t letter;
  for(int i= 0; i < countUsed; i++)
    {
      //loops to go through all of the different vertices in the graph.
      for(int j = 0; j < Gtable[i].outDegree;j++)
	{
	  //if the adjecent list is not empty, delete from rear
	  if(!(Gtable[i].adjacentOnes).isEmpty())
	    (Gtable[i].adjacentOnes).deleteRear(letter);
	}
    }
  countUsed = 0;//make sure the count is empty at the end

}
void dgraph::fillTable()   // read from the input file table.txt and fill GTable
{
  ifstream fin;
  char adjacent;//variable to store the adjacent vertices
  fin.open("table.txt");
  while (fin >> Gtable[countUsed].vertexName)
    { // increment the countUsed;
      fin >> Gtable[countUsed].outDegree;
      // Then for the Out times do the following:
      for(int i=0;i<Gtable[countUsed].outDegree; i++)
	{
	  fin >> adjacent;
	  (Gtable[countUsed].adjacentOnes).addRear(adjacent);//uses the slist function
	  // this uses a slist function from HW3
	}
      if(fin.eof())
	{
	  break;
	}
      countUsed++; //adds to the count
    }
  fin.close();//closes table.txt

}  
void dgraph::displayGraph()  //used to display the graph 
{
  for(int i=0;i<countUsed;i++)//goes through the graph dependent on how many were counted
    {
      cout << "Vertex: " << Gtable[i].vertexName << endl;
      cout << "Out Degree: " << Gtable[i].outDegree << endl;
      cout << "Adjacent List: ";
      (Gtable[i].adjacentOnes).displayAll();//within the graph, it displays the slist
      
      cout << endl;
    }
}
int dgraph::findOutDegree(char x)  //returns the degree of the given vertex
{ 
  for(int i=0;i<countUsed;i++)//goes through all the vertices
    {
      if(x == Gtable[i].vertexName)//sets variable to the vertex
	return Gtable[i].outDegree;
    }
}
slist dgraph::findAdjacency(char x)  // finds the adjacent to the graph
{
  slist adjacent;//creates a new list
  for(int i=0;i<countUsed;i++)//goes through the list as many times as there is a count
    {
      if(x == Gtable[i].vertexName)
	adjacent = Gtable[i].adjacentOnes;
    }
  return adjacent;
}

void dgraph::visit(int order, el_t x)
{
  x=toupper(x);

  for (int i=0; i<countUsed; ++i)
    {
      if(Gtable[i].vertexName==x)
	{
	  Gtable[i].visit =order;
	}
    }

}

bool dgraph::isMarked(el_t x)
{
  for(int i=0; i<countUsed;++i)
    {
      if(Gtable[i].vertexName==x)
	{
	  if(Gtable[i].visit !=0)
	    return true;
	}
    }
  return false;
}

#endif // DGRAPH_C
