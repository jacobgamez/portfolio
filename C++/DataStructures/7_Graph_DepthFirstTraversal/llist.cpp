// ====================================================
//Your name: Jacob Gamez
//Complier:  g++
//File type: Linked List implementation file

//This file contains the implementation of the functions
//attributed to the llist class
//=====================================================

#ifndef LLIST_CPP
#define LLSIT_CPP

#include <iostream>
using namespace std;

#include "llist.h" 


//Constructor
llist::llist()
{
//initialize Front and Rear to be NULL and Count = 0.
Front = NULL;
Rear = NULL;
Count = 0;
//This does not create any node.  The new list is empty.
}

//Destructor  
llist::~llist()
{
el_t junk; //Place for temporary values to be stored from deleteFront()
//while the list is not empty, call deleteFront repeatedly to delete all nodes.
while (!isEmpty())
{deleteFront(junk);}

//Please place a cout in this function "calling the llist desctructor."
cout << "Calling the llist destructor." << endl;
}

//boolean isEmpty()
//Will return true if list is empty
bool llist::isEmpty()
{
//- return true if Front and Rear are both pointing to NULL.
	if (Front==NULL && Rear==NULL)//If the list is empty return true
		return true;
	else//Otherwise return false
		return false;
//- (note: do not use Count for this!!!)
}

//void displayAll()
//Will display all of Elem members of each node from Front to Rear
void llist::displayAll()
{
//- displays each element of the list starting from Front in [ ].
	if (!isEmpty())//If the list is not empty
	{
		Node *current = Front;//Start at Front
		cout << "[ ";
		while (current != NULL)//do to every node in list
		{
			cout << current -> Elem << " ";
			current = current -> Next;
		}
		cout << "]" << endl;
	}
//- (special case: if the list is empty, display [ empty ] ).
	else {cout << "[empty]" << endl;} //If the list is empty
	
}


//void addRear(el_t NewNum) 
//Will add a node to the rear of the list
//NewNum is a parameter which will be the Elem member of the new Node
void llist::addRear(el_t NewNum)
{
//- 2 cases
//- adds a new node at the rear and puts NewNum in the Elem field
//  of this new node. Count is updated.
//- (special case: if this is going to be the very first node, you must
//   create a new node and make Front and Rear point to it.)
if (isEmpty())//In case the list is empty (special case)
{
	Front = new Node;
	Rear = Front;
	Front->Next=NULL;
	Front->Elem = NewNum;
}
else//Regular case
{
//Regular case:
Rear->Next = new Node;
Rear = Rear->Next;
Rear->Elem = NewNum;
Rear->Next = NULL;
}
Count++;
}


//void deleteFront(el_t& OldNum)
//Deletes the first node in the list (Front)
//OldNum is passed by reference and will contain the Elem member of the 
//Node this function deletes
void llist::deleteFront(el_t& OldNum)
{
//- 3 cases
//-  error case: if the List is empty, throw an exception.

if (isEmpty())//Error case
	throw Underflow();
//-  else give back the front node element through OldNum (pass by reference)
//   and also remove the front node. Count is updated.
else //Regular case
{
	OldNum = Front->Elem;
	Node *Second;
	Second = Front->Next;
	delete Front;
	Front=Second;
	Count--;
}
//-  (special case: if this is going to make the list empty,
//    make sure both Front and Rear become NULL).
if (Count==0) //This appendix to Regular case constitutes the special
{			  //case
	Front = NULL;
	Rear = NULL;
}
}


//void addFront(el_t NewNum)
//Will add a new Node to the front of the list
//NewNum will become the Elem member of the new Node
void llist::addFront(el_t NewNum)
{
//- 2 cases
//- will add a new node to the front of the list. Count is updated.
//- (special case: if this is going to be the very first node, you must
//  create a new node and make Front and Rear point to it.)
if (isEmpty()) //Special Case
{
	Front = new Node;
	Rear = Front;
	Front->Elem = NewNum;
	Front->Next = NULL;
}
else//Regular case:
{
Node *x;
x = new Node;
x->Next = Front;
Front = x;
Front->Elem = NewNum;
}
Count++;
}

//void deleteRear(el_t& OldNum)
//Deletes the last Node in the list
//OldNum will become the Elem member of the Node that this
//function deletes (passed by reference)
void llist::deleteRear(el_t& OldNum)
{
//- 3 cases
//- error case: if empty, throw an exception.
if (isEmpty())
	throw Underflow();
	
//- (special case: if this is going to make the list empty,
//   make sure both Front and Rear become NULL).
else if (Count == 1)
{
	OldNum = Rear->Elem;
	delete Rear;
	Rear = NULL;
	Front = NULL;
}

//- else give back the rear node element through OldNum (pass by reference)
//  and also remove the rear node. Count is updated.
else //Regular case
{
	OldNum = Rear->Elem;
	Node *p = Front;
	while(p->Next != Rear)
		p = p->Next;

	delete Rear;
	Rear = p;
	Rear->Next = NULL;
}
Count--;
}


//void deleteIth(int I, el_t& OldNum)
//Deletes the Ith Node in the list. 
//I is the index (the number in order) of the Node to be deleted
//OldNum will become the Elem member of the Node which this function
//Deletes (Passed by reference)
void llist::deleteIth(int I, el_t& OldNum)
{
//- 4 cases
//- will delete the Ith node (I starts out at 1).  Count is updated.
//- Error cases: 
//  If I is an illegal value (i.e. > Count or < 1) throw an exception.
//- (note: this may simply call deleteFront or deleteRear for some cases)

if (I>Count || I<1)//Error Case
	throw OutOfRange();

else if (I==1) //In case I indicates the Front node
	deleteFront(OldNum);
else if (I==Count) //In case I indicates the Rear node
	deleteRear(OldNum);
else//Regular Case
{
	Node* current = Front->Next;
	Node* trail;
	
	int i=2;
	while(i<I) //get Current to I and trail to I-1
	{
		trail=current;
		current=current->Next;
		i++;
	}
	OldNum = current->Elem;
	trail->Next=current->Next;
	delete current;
	Count--;
}
}

//void addbeforeIth(int I, el_t newNum)
//Adds a new node before the Ith Node in the list
//I is the index (the number in order) of the Node before which the 
//New Node will be created
//newNum will become the Elem member of the new Node
void llist::addbeforeIth(int I, el_t newNum)
{
//- 4 cases
//-  will add right before the Ith node.  Count is updated.
//-  Error cases:
//   If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.      
//-  (note: this may simply call addFront or addRear for some cases)
	if (I>Count+1 || I<1) //Error case
		throw OutOfRange();
	else if (I==1) //In case the new Node will be in Front
		addFront(newNum);
	else if (I==Count+1) //In case the new Node will be in Rear
		addRear(newNum);
	else //Regular case
	{
		Node* current = Front;
		Node* trail;
		for (int i=0; i<I-2; i++) //Current will be L[I-1]
			current=current->Next;
		trail=current->Next;
		current->Next = new Node;
		current->Next->Next = trail;
		current->Next->Elem = newNum;
		Count++;
	}
}

#endif //LLIST_CPP
