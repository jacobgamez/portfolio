#ifndef SLIST_H
#define SLIST_H

/*******************************
 * Jacob Gamez
 * File Type: slist header file
 * Compiler: g++
 *******************************/

#include "llist.h"

class slist : public llist
{
public:
	slist(); //Constructor (same as llist constructor)
	slist(const slist& source); //Copy constructor
	
	//Searches through list to see if any node contains Key
	//returns the position of the number (returns 0 if Key not found)
	int search(el_t Key);
	
	//Replace element in Ith node with value of Elem parameter
	//Throws exception if illegal value
	void replace(el_t Elem, int I);
	
	//Operator= overloading function
	slist& operator=(const slist& otherOne);
	
};

#endif //SLIST_H
