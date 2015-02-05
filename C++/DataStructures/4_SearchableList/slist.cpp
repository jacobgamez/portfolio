/*********************************************
 * Jacob Gamez
 * File Type: slist class implementation file
 * Compiler: g++
 * 
 * This file contains the implementation of the functions described in slist.h
**********************************************/

#include <iostream>
using namespace std;

#include "slist.h"

//Constructor (same as llist constructor)
slist::slist()
{
	llist();
}

//Copy constructor
//Parameter source is the original list to be copied
slist::slist(const slist& source)
{
	this->Front=NULL;
	this->Rear=NULL;
	this->Count=0;
	
	Node* origin=source.Front;
	
	while (origin != NULL)
	{
		this->addRear(origin->Elem);
		origin=origin->Next;
	}
}


//Searches through list to see if any node contains Key
//returns the position of the number (returns 0 if Key not found)
int slist::search(el_t Elem)
{
	Node* current=Front;
	int I=1; //Start at 1 in case first evaluation is the correct Node
	while (current!=NULL)
	{
		//If the current node contains Elem
		if (current->Elem==Elem)
			return I;
		I++;
		current=current->Next;
	}
	
	//If Elem is not found
	return 0;
}

//Replace element in Ith node with value of Elem parameter
//Throws exception if illegal value
void slist::replace(el_t Elem, int I)
{
	//If the count is out of bounds, throw exception
	if (I>Count || I<1)
		throw OutOfRange();
	
	//Get to the Ith node
	Node* current=Front;
	for (int i=1; i<I; i++)
		current=current->Next;
	
	//Replace the Element in the Ith node with Elem
	current->Elem=Elem;
}

//Operator= overloading Function

slist& slist::operator=(const slist& l)
{
	int elem=0;
	
	if (&l != this) //Only if they are not the same
	{
		//empty this first
		while (!this->isEmpty())
			this->deleteRear(elem);
		
		Node* otherOne=l.Front;
		
		//repeats until reaching the end of otherOne
		while(otherOne != NULL)
		{
			this->addRear(otherOne->Elem);
			otherOne=otherOne->Next;
		}
	}
	
	return *this;
}
