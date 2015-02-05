/***************************************
 * Jacob Gamez
 * Compiler: g++
 * File Type: .cpp Client File
 * This file is the client file that creates the test cases
****************************************/

#include <iostream>
using namespace std;

#include "llist.h"

int main()
{
	int tcase;
	llist L;
	el_t show; //Variable for recieving results from functions
	
	cout << "Which test case would you like to try? ";
	cin >> tcase;
	
	if (tcase==1)
	{
		//1
		if(L.isEmpty())
			cout << "List is Empty" << endl;
		else
			cout << "List is Not Empty" << endl;
			
		//2
		L.displayAll();
		
		//3
		L.addRear(1); L.addRear(2); L.addRear(3);
		
		//4
		L.displayAll();
		
		//5
		L.deleteFront(show);
		cout << show << endl;
		L.deleteFront(show);
		cout << show << endl;
		
		//6
		L.displayAll();
		
		//7
		if(L.isEmpty())
			cout << "List is Empty" << endl;
		else
			cout << "List is Not Empty" << endl;
			
		//8
		L.deleteFront(show);
		cout << show << endl;
		
		//9
		if(L.isEmpty())
			cout << "List is Empty" << endl;
		else
			cout << "List is Not Empty" << endl;
	}
	
	else if (tcase==2)
	{
		//1
		L.addFront(5);
		
		//2
		L.addFront(4);
		
		//3
		L.deleteFront(show);
		
		//4
		L.addRear(6); L.addRear(8); L.addRear(9);
		
		//5
		L.displayAll();
		
		//6
		L.addbeforeIth(1, 4);
		
		//7
		L.addbeforeIth(4, 7);
		
		//8
		L.addbeforeIth(7, 10);
		
		//9
		try
		{
		L.addbeforeIth(9, 12);
		}
		catch (llist::Underflow)
		{cout << "error - (Underflow)" << endl;}
		catch (llist::OutOfRange)
		{cout << "error - (Out of Range)" << endl;}
		
		//10
		try
		{
		L.addbeforeIth(0, 0);
		}
		catch (llist::Underflow)
		{cout << "error - (Underflow)" << endl;}
		catch (llist::OutOfRange)
		{cout << "error - (Out of Range)" << endl;}
		
		//11
		L.displayAll();
		
		//GOOD
		
		//12
		L.deleteIth(1, show);
		cout << show << endl;
		
		//13
		L.deleteIth(6, show);
		cout << show << endl;
		
		//14
		L.deleteIth(3, show);
		cout << show << endl;
		
		//15
		try
		{
		L.deleteIth(5, show);
		}
		catch (llist::Underflow)
		{cout << "error - (Underflow)" << endl;}
		catch (llist::OutOfRange)
		{cout << "error - (Out of Range)" << endl;}
		
		//16
		try
		{
		L.deleteIth(0, show);
		}
		catch (llist::Underflow)
		{cout << "error - (Underflow)" << endl;}
		catch (llist::OutOfRange)
		{cout << "error - (Out of Range)" << endl;}
		
		//17
		L.displayAll();
		
		//18
		while (!L.isEmpty())
		{
			L.deleteRear(show);
			cout << show << endl;
		}
		
		//19
		try
		{
		L.displayAll();
		}
		catch (llist::Underflow)
		{cout << "error - (Underflow)" << endl;}
		catch (llist::OutOfRange)
		{cout << "error - (Out of Range)" << endl;}
	
	}
	
	else if (tcase==3)
	{
		//1
		try
		{
			L.addbeforeIth(0, 0);
		}
		catch (llist::Underflow)
		{cout << "error - (Underflow)" << endl;}
		catch (llist::OutOfRange)
		{cout << "error - (Out of Range)" << endl;}
		
		//2
		try
		{
			L.deleteFront(show);
		}
		catch (llist::Underflow)
		{cout << "error - (Underflow)" << endl;}
		catch (llist::OutOfRange)
		{cout << "error - (Out of Range)" << endl;}
	}
	
	else if (tcase==4)
	{
		//1
		try
		{
		L.deleteIth(2, show);
		}
		catch (llist::Underflow)
		{cout << "error - (Underflow)" << endl;}
		catch (llist::OutOfRange)
		{cout << "error - (Out of Range)" << endl;}
		
		//2
		try
		{
		L.deleteRear(show);
		}
		catch (llist::Underflow)
		{cout << "error - (Underflow)" << endl;}
		catch (llist::OutOfRange)
		{cout << "error - (Out of Range)" << endl;}
	}
	else
	{cout << "bad input" << endl;}
	
return 0;
}
