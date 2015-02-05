/* ***************************************************************
 * Jacob Gamez
 * Compiler: g++
 * File Type: Client C file
 * This client file will generate the test cases
 *****************************************************************/

#ifndef CLIENT_CPP
#define CLIENT_CPP

 #include <iostream>
 using namespace std;

 #include "slist.h"

 void copyTest(slist); 
 
 //Main driver function
 int main()
 {
	 el_t junk; //For deleting
	 
	//1
	slist L1;
	 
	for (int i=1; i<=5; i++)
		L1.addRear(i);
	
	//2
	copyTest(L1);
	
	//3
	cout << "Displaying L1:" << endl;
	L1.displayAll();
	
	//4
	L1 = L1;
	
	//5
	cout << "Displaying L1:" << endl;
	L1.displayAll();
	
	//6
	slist L2;
	
	for (int j=7; j <= 10; j++)
		L2.addRear(j);
	
	//7
	cout << "Displaying L2:" << endl;
	L2.displayAll();
	
	//8
	L2 = L1;
	
	//9
	cout << "Displaying L2:" << endl;
	L2.displayAll();
	
	//10
	L1.deleteRear(junk);
	
	//11
	cout << "Displaying L1:" << endl;
	L1.displayAll();
	
	//12
	cout << "Displaying L1:" << endl;
	L1.displayAll();
	
	//13
	cout << "Displaying L2:" << endl;
	L2.displayAll();

	return 0;
}

void copyTest(slist L)
{	
	L.addRear(6);
	
	cout << "Displaying in copyTest()" << endl;
	L.displayAll();
}


#endif //CLIENT_CPP
