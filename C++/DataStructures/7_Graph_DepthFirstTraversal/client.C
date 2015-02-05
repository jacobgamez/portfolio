//Jacob Gamez
//HW7P2
//Compiler: g++
//File type: C++ client program
//Purpose: Contains main driver of program to implement HW7P2 client

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


#include "dgraph.h"
#include "llist.h"
#include "stack.h"


int main()
{

    slist tempSlist; //holds objects upon return
    stack tempStack; //objects of the stack
    dgraph graph; //begins the graph

    char x ='a'; //user input

    int count =1; //counter for order assignment
    int deg; //degree holder 
    int visitCorrect=1; //correct the visitation number

    graph.fillTable(); //begin reading from text file
    cout<<"Graph: "<<endl;
    graph.displayGraph();


    graph.visit(1,x); //the first vertex gets visited

    tempSlist= graph.findAdjacency(x); //stores adjacency list for first elements
    deg= graph.findOutDegree(x); //gets out degree for first adjacency list
    cout<<"\n Popped : "<<char(toupper(x))<<" from Stack"<<endl;
    cout<<"Adding ..."<<endl;
    tempSlist.displayAll();

    for(int i=0; i<deg; ++i) //i is less than outdegree
    {
	tempSlist.deleteRear(x); //returns element
	tempStack.push(x); //add element to the stack
    }

    cout<<"\n Current Stack:"<<endl;
    tempStack.displayAll();

    while (!tempStack.isEmpty()) //until the stack is empty 
    {
	deg=0; //reset the degree
	count++; //add 1 to visit order
	visitCorrect++; //fixes right visit order
	tempStack.pop(x); //get top element of stack
	cout<<"\nPopped "<<x<<" from Stack"<<endl;

	if(!graph.isMarked(x)) //while the element has not been visited yet
	{
	    graph.visit(count,x); //update visit number
	    cout<< "Visited "<<x<< endl;
	    tempSlist= graph.findAdjacency(x); //add adjacency list
	    deg= graph.findOutDegree(x); 
	    cout<< "Adding... "<<endl;
	    tempSlist.displayAll();
	    for(int i=0; i<deg; ++i) //adds adjacency list to the stack
	    {
		tempSlist.deleteRear(x);
		tempStack.push(x);
	    }
	}

	else
	{
	    cout<<"Visited "<< x<<" again"<<endl;
	    cout<<" "<<x<<" is already marked"<<endl;
	}

	cout<< "Current Stack:" <<endl;
	tempStack.displayAll();
    }

    graph.displayGraph();
    return 0;

}







