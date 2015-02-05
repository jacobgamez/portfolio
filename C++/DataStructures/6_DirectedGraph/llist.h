
//****************************************************************************
//  CS311 Linked - by Rika for those who could not get HW3 to work
//  Header File  llist.h

//**Jacob Gamez**//
//****************************************************************************

#ifndef LLIST_H
#define LLIST_H

typedef int el_t ;

	   // list node is defined here as a struct Node
struct Node
{
  el_t Elem;   // elem is the element stored
  Node   *Next;  // next is the pointer to the next node
};

// I could have done class Node and add the data members under public
// but it will use too much space


class llist
{
  
 protected:
  
  Node *Front;       // front  pointer 
  Node *Rear;        // rear   pointer
  int  Count;        // counter for the number of elements
  
 public:
  
  //Exception handling classes:
  class Underflow{};
  class OutOfRange {};
    
  llist ();                       // constructor  
  ~llist();                       // destructor
  
  //Will return true if list is empty
  bool isEmpty();
  
  //Will display all of Elem members of each node from Front to Rear
  void displayAll();
  
  //Will add a node to the rear of the list
  //NewNum is a parameter which will be the Elem member of the new Node  
  void addRear(el_t NewNum);
  
  //Deletes the first node in the list (Front)
  //OldNum is passed by reference and will contain the Elem member of the 
  //Node this function deletes  
  void deleteFront(el_t& OldNum);
  
  //Will add a new Node to the front of the list
  //NewNum will become the Elem member of the new Node  
  void addFront(el_t NewNum);
  
  //Deletes the last Node in the list
  //OldNum will become the Elem member of the Node that this
  //function deletes (passed by reference)  
  void deleteRear(el_t& OldNum);
  
  //Deletes the Ith Node in the list. 
  //I is the index (the number in order) of the Node to be deleted
  //OldNum will become the Elem member of the Node which this function
  //Deletes (Passed by reference)  
  void deleteIth(int I, el_t& OldNum);
  
  
  //Adds a new node before the Ith Node in the list
  //I is the index (the number in order) of the Node before which the 
  //New Node will be created
  //newNum will become the Elem member of the new Node  
  void addbeforeIth(int I, el_t newNum);
    
};

#endif //LLIST_H
