#ifndef CLIENT_C
#define CLIENT_C

/*************************************************************************************************
Name: Jacob Gamez
Compiler: g++
File type: Client C++ file for HW6
Purpose: Contains the main driver for hw6 and allows user to run through test cases for dgraph
**************************************************************************************************/

#include <iostream>
#include "dgraph.h"
using namespace std;

int main()
{
  dgraph G1; 
  char userinput;
  int out;
  slist slist;

  G1.fillTable();
  G1.displayGraph();

  cout << "Enter node letter to find out degree. (Enter Q to stop): " << endl;
  cin >> userinput;

  //Run through outdegree queries until user inputs Q
  while(userinput !='Q' && userinput != 'q')
    {
      out = G1.findOutDegree(userinput);
      if(out ==0)
	cout << "No Vertex found" << endl;
      else
	cout << "Out degree: " << out << endl;

      cout << "Enter node letter to find outdegree. (Enter Q to stop): ";
      cin >> userinput;
    }

  cout << "Enter vertex letter to find adjacency list. (Enter Q to stop): " << endl;
  cin >> userinput;
  
  //Run through adjacency queries until user inputs Q
  while(userinput !='Q' && userinput != 'q')
    {
      slist = G1.findAdjacency(userinput);
      cout << "Adjacent list: ";
      slist.displayAll();
      cout << "Enter vertex letter to find adjacency list. (Enter Q to stop): ";
      cin >> userinput;
    }
  
  return 0;
}

#endif //CLIENT_C
