/***************************************
 * Jacob Gamez
 * File Type: cpp main client program
 * Compiler: g++
 * 
 * This program includes the combine section of the 
 * Merge sorting algorithm. It will take 2 vectors
 * containing 3 integers in ascending order each
 * and produce a sorted list in a third vector.
****************************************/

#ifndef COMBINE_CPP
#define COMBINE_CPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void combine(vector<int>, vector<int>, vector<int>&);

//The purpose of main is to recieve the 2 vectors containing 3
//integers in ascending order from the user and to call the
//combine() function. It then outputs the resulting L3 vector
//which contains a sorted list
int main()
{
	vector<int> L1;
	vector<int> L2;
	vector<int> L3;
	int in;
	
	//Fill first vector
	cout << "Please enter 3 integers in ascending order: " << endl;
	
	for(int i=0; i<3; i++)
	{
		cout << i+1 << ": ";
		cin >> in;
		L1.push_back(in);
	}
	
	//Fill second vector
	cout << "Please enter 3 more integers in ascending order: " << endl;
	
	for(int i=0; i<3; i++)
	{
		cout << i+1 << ": ";
		cin >> in;
		L2.push_back(in);
	}
	
	//Combine L1 and L2 into L3
	combine(L1, L2, L3);
	
	//Print the resulting sorted list
	cout << "Result: ";
	
	for(int i=0; i<L3.size(); i++)
		cout << L3[i] << " ";
		
	cout << endl;
	
	return 0;
}
//The purpose of the combine() function is to sort 2 vectors into
//a third vector (R). These 2 vectors are given as parameter vectors
//A and B, and the third vector is passed by reference.
//ALGORITHM: combine() will compare an incremented index in A to an 
//incremented index in B, pushing the lesser of the two to R. When one
//vector runs out, the remaining ints in the other vector will be
//pushed to R.
void combine(vector<int> A, vector<int> B, vector<int>& R)
{
	//These are the incremented indexes for a and b
	int ia=0, ib=0;
	
	//Compare indexes until one of the vectors is out of numbers
	while(ia < A.size() && ib < B.size())
	{
		//The lesser of A[ia] and B[ib] will be pushed to R
		if(A[ia] < B[ib])
		{
			R.push_back(A[ia]);
			ia++;
		}
		else
		{
			R.push_back(B[ib]);
			ib++;
		}
	}
	
	//The remainder of the nonempty vector will be pushed to R
	while(ia<A.size())
	{
		R.push_back(A[ia]);
		ia++;
	}
	
	while(ib<B.size())
	{
		R.push_back(B[ib]);
		ib++;
	}
}

#endif //COMBINE_CPP
