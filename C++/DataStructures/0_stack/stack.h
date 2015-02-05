// =======================================================
// Your name: Jacob Gamez
// Compiler:  g++ 
// File type: header file stack.h
//=======================================================

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
using namespace std;

//el_t type will be int; we will convert from
//char to int as each operand is added to the
//queue
typedef int el_t;    // the el_t type is ** for now
                      // el_t is unknown to the client


class stack
  { 

   private: // to be hidden from the client

        vector<el_t> el;       // el is  an *VECTOR of el_t's

   public: // prototypes to be used by the client

        // exception handling classes  
        class Overflow{};
        class Underflow{};

      	stack();   // constructor
      	~stack();  // destructor  

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: if not full, enters an element at the top;
        //          otherwise throws an exception - Overflow
        void push(el_t);

        // HOW TO CALL: provide variable to receive the popped element
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(el_t&);

        // HOW TO CALL: provide a variable for the top value to be saved in
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(el_t&);

        //PURPOSE: Returns true if stack is empty
      	bool isEmpty();
      	//PURPOSE: Returns true if stack is full *Will always return false
      	//because vectors are dynamic in size
      	bool isFull();
      	//PURPOSE: Displays all elements vertically (return after each)
        void displayAll();
        //PURPOSE: Pops all reamining elements from stack
        void clearIt();
        
  };  

#endif //STACK_H
