// =========================================================

//Stack Client
//Your name: Jacob Gamez
//Complier:  g++
//File type: cpp client file

//================================================================

#include <iostream>
#include <string>
#include <cctype> //Including to use isdigit
#include "stack.h"
using namespace std;

int main()
{
  stack postfixstack;  // integer stack
  string expression;
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result; //missing variable from popped boxes & will use for final solution
 
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i]; //1.  read an item.
	  i++; //increment i for the while loop
	  
	  if (isdigit(item)) //Check if is operand (isdigit is function of cctype)
	  {
		int number=item-'0'; //convert item to integer
		postfixstack.push(number); //push it (you might get Overflow exception)
	  }
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	 apply the operator to the two operands, and
	  //    push the result.
	  
         else if ( (item == '+') || (item == '-') || (item == '*'))
	   {
	     postfixstack.pop(box1);
	     postfixstack.pop(box2);
             // a whole bunch of cases
             if (item == '-') result = box2-box1;
             // also do the + and * cases 
             else if (item=='+') result=box2+box1;
             else if (item=='*') result=box2*box1;
	     // push the result
	     postfixstack.push(result);
	   }
	 else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
	catch (stack::Overflow)
	{
		cout << "STACK OVERFLOW: Too many operands" << endl;
		return 1;
	}
    catch (stack::Underflow)
	{
		cout << "STACK UNDERFLOW: Not enough operands for operators" << endl;
		return 1;
	}
    catch (char const* errorcode) // for invalid item
	{
		cout << "You entered an unsupported symbol" << endl;
		return 1;
	}
      // go back to the loop
      //End of exception handling
   }// end of while
  
  //  After the loop successfully completes: 
  //  The result will be at the top of the stack. Pop it and show it.
  //  If anything is left on the stack, an incomplete expression was found
  // inform the user.
  
  postfixstack.pop(result);
  if(!postfixstack.isEmpty())
  {
	  cout << "Incomplete Expression" << endl;
	  return 1;
  }
  cout << "Solution: " << result<< endl;
  
  return 0;  
}
