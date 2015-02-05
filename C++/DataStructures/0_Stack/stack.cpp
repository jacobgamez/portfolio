// =========================================================
//Your name: Jacob Gamez
//Complier:  g++
//File type: stack implementation file stack.cpp
//================================================================

#ifndef STACK_CPP
#define STACK_CPP

#include "stack.h"

//Constructor has nothing to do since vector creation
//is already controlled
stack::stack()
{//Nothing to do
}

//Destructor must clear stack using clearIt() to make sure
//it leaves no cells behind
stack::~stack()
{ 
	clearIt();
}
  
// isEmpty checks to see if the size of the vector stack is empty. If it
//is, then it returns true
bool stack::isEmpty()
{ 
	if (el.size()==0) //if stack is empty
		return true;

	else return false;
}
    
//isFull will always return false because with the new vector
//implementation the stack will never be full (Vectors are dynamic)
bool stack::isFull()
{ 
	return false;
}
  
// push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
// elem is given by the client to be added into the stack
void stack::push(el_t elem)
  { if (isFull())
	  throw Overflow(); //In case of overflow
	  
    else 
    { 
		el.push_back(elem); //elem is deposited into that empty spot and
						//is now the top value
	}
}
  
// pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//elem is a variable in the client program that will be given the
//top value from the stack
void stack::pop(el_t& elem)
{ 
	//If the stack is empty and we try to pop then there must not
	//be enough operands, therefore we throw underflow
	if (isEmpty())
	  throw Underflow();
	
	else 
	{ 
		elem = el[el.size()-1]; //elem now contains the top value from the stack
		el.pop_back(); //remove the "top" element in el
	}
}

// topElem calls isEmpty and if true, throws an exception (underflow)
// Otherwise, gives back the top element from el.
// elem is a variable in the client program that will take the value
// of the top value in stack
void stack::topElem(el_t& elem)
{ 
	if (isEmpty())
		throw Underflow();
    else 
    { 
		elem = el[el.size()-1]; 
	}
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//Otherwise, diplays the elements vertically.
void stack::displayAll()
{  
	if (isEmpty()) cout << "[ empty ]" << endl;
    else for (int i=0; i>=el.size(); i++)
	{ 
		  cout << el[i] << endl; 
	}
}

//clearIt pops all elements from the stack to make it empty if it is not empty yet.
//Alg: continues to pop values from the stack in while loop until stack is empty
void stack::clearIt()
{
	el_t leftover; //leftover will briefly contain all the remaining elements in the stack
				   //and will be destroyed after the function exits
	while (!isEmpty())
	{
		pop(leftover);
	}
}

#endif //STACK_CPP
