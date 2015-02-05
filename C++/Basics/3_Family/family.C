//This is the family implementation file, where all of the major
//processes take place
#ifndef FAMILY_C
#define FAMILY_C

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "family.h"
#include "child.h"
#include "husband.h"
#include "wife.h"

Family::Family()
{
	top = NULL;
}

///////////

//This method will be used to remove all children when removing Husband or Wife
void Family::RemoveAllChildren(long SSN)
{
	//This start pointer will mark the beginning of the link list of children
	//We set start to NULL so we will know later if any children have been found
	Child *start=NULL, *temp;
	
	//Now we start the search for the Husband
	//After this, curr will point to the Husband of the family
	Husband* curr = top;
	while (curr -> SSN != SSN)
	{
		curr = curr -> nextFamily;
		if(curr==NULL)
		{
			cout << "Sorry, husband " << SSN << " does not exist!\n";
			return;
		}
	}
	if (curr -> myWife != NULL)//If the Husband has a wife,
	{
		if (curr -> myWife -> myChild != NULL)//and if wife has a child,
			start = curr -> myWife -> myChild;//then point start to the first child

		//If there are no children, we can leave the function because
		//there is then nothing to delete
		else
			return;
	}
	//If there is no wife, we can leave the function because there
	//are no children, then, to delete
	else
		return;
	
	//Delete all of the children
	while(start != NULL)
	{
		temp = start;
		start = start -> mySibling;
		delete temp;
	}
	
	//Set wife's myChild to NULL to indicate there are no children now
	curr -> myWife -> myChild = NULL;
}

////****METHODS PERTAINING TO HUSBAND****\\\\

void Family::AddHusband(long SSN, string Fname, string Lname)
{
	//If the husband is the first family, top will have been set to NULL
	if (top==NULL)
		top = new Husband(SSN, Fname, Lname);//The new Husband
	//Otherwise, we need to insert the Husband in the top of the list
	else
	{
		Husband* newhus = new Husband(SSN, Fname, Lname);//The new Husband
		newhus -> nextFamily = top;
		top = newhus;
	}
}

///////////

void Family::RemoveHusband(long SSN)
{
	//Remove all of the children belonging to this husband
	RemoveAllChildren(SSN);
	
	//Remove the wife of this husband
	RemoveWife(SSN);
	
	//Remove the husband
	Husband *curr, *temp;
	if(SSN == top -> SSN)//If the husband is the first one
	{
		temp = top;
		top = top -> nextFamily;
	}
	else//If the husband is not the first one
	{
		curr = top;
		while(curr -> nextFamily -> SSN != SSN)
		{
			curr = curr -> nextFamily;
			if(curr==NULL)
			{
				cout << "Sorry, husband " << SSN << " does not exist!\n";
				return;
			}
		}
		temp = curr -> nextFamily;
		curr -> nextFamily = curr -> nextFamily -> nextFamily;
	}
	delete temp;
}
	
////****METHODS PERTAINING TO WIFE****\\\\
	
void Family::AddWife(long SSN, string Fname, string Lname, long husbandSSN)
{
	//After this, hus will indicate the husband of the desired family
	Husband* hus = top;
	while (hus -> SSN != husbandSSN)
	{
		hus = hus -> nextFamily;
		if (hus==NULL)
			{
				cout << "Sorry, husband " << husbandSSN << " does not exist!\n";
				return;
			}
	}
	
	//Now we add a new wife with the given information and point husband to it
	Wife* newWife = new Wife(SSN, Fname, Lname);
	hus -> myWife = newWife;
}

///////////

void Family::RemoveWife(long husbandSSN)
{
	//First remove all children using RemoveAllChildren()
	RemoveAllChildren(husbandSSN);
	
	//Next we point to the correct family with hus
	Husband* hus = top;
	while (hus -> SSN != husbandSSN)
	{
		hus = hus -> nextFamily;
		if(hus==NULL)
		{
			cout << "Sorry, husband " << husbandSSN << " does not exist!\n";
			return;
		}
	}
	//Delete the wife
	delete hus -> myWife;
	
	//Set myWife pointer to NULL so we know there is no wife
	hus -> myWife = NULL;
}

////****METHODS PERTAINING TO CHILD****\\\\

void Family::AddAChild(long SSN, string Fname, string Lname, long FatherSSN)
{
	//After this, dad will indicate the husband of the desired family
	Husband* dad = top;
	while (dad -> SSN != FatherSSN)
	{
		dad = dad -> nextFamily;
		if(dad==NULL)
		{
			cout << "Sorry, husband " << FatherSSN << " does not exist!\n";
			return;
		}
	}
	//Create a pointer to indicate the mother
	Wife* mom = dad -> myWife;

	//If mother has no child, simply add the child and point mother to it
	if (mom -> myChild == NULL)
	{
		Child* newkid = new Child(SSN, Fname, Lname);
		mom -> myChild = newkid;
	}
	
	//Otherwise, add the child to the beginning of the children list
	else
	{
		Child* newkid = new Child(SSN, Fname, Lname);
		newkid -> mySibling = mom -> myChild;
		mom -> myChild = newkid;
	}
}

///////////

void Family::RemoveAChild(long FatherSSN, long childSSN)
{
	//After this, dad will indicate the husband of the desired family
	Husband* dad = top;
	while (dad -> SSN != FatherSSN)
	{
		dad = dad -> nextFamily;
		if(dad==NULL)
		{
			cout << "Sorry, husband " << FatherSSN << " does not exist!\n";
			return;
		}
	}
	
	//Create a pointer "start" to indicate the most 'top' of the children
	Child* start = dad -> myWife -> myChild;
	
	//Remove the child
	Child* temp;
	
	if (start -> SSN == childSSN)//If the child is the first on the list
	{
		dad -> myWife -> myChild = start -> mySibling;
		delete start;
	}
	else//If the child is not first on the list
	{
		while (start -> SSN != childSSN)
		{
			start = start -> mySibling;
			if (start==NULL)
				{
					cout << "Sorry, child " << childSSN << " does not exist\n";
					return;
				}
		}
		temp = start -> mySibling;
		start -> mySibling = temp -> mySibling;
		delete temp;
	}
}

////****Printing and Transaction****\\\\

void Family::PrintAFamily(long fatherSSN)
{
	Husband* theHusband=top;//Initialize to top for beginning of search
	Wife* theWife;
	Child* theChild;
	
	//Print header
	cout << "\n***FAMILY***\n";
	
	//Locate husband and print
	while (theHusband -> SSN != fatherSSN)
	{
		theHusband = theHusband -> nextFamily;
		if (theHusband==NULL)
		{
			cout << "Sorry, husband " << fatherSSN << " does not exist!\n";
			return;
		}
	}
	
	cout << "Husband: " << theHusband -> firstName
		 << " " << theHusband -> lastName << " " << theHusband -> SSN << endl;
	
	//If the wife exists, print wife
	if (theHusband -> myWife != NULL)
	{
		theWife = theHusband -> myWife;
		cout << "Wife: " << theWife -> firstName << " "
			 << theWife -> lastName << " " << theWife -> SSN << endl;
	}
	
	if (theWife != NULL)//Skip if there is no wife
	{
		//If children exist, print them
		if (theWife -> myChild != NULL)
		{
			theChild = theWife -> myChild;
			while (theChild != NULL)
			{
				cout << "Child: " << theChild -> firstName << " " 
					 << theChild -> lastName << " " << theChild -> SSN << endl;			
				theChild = theChild -> mySibling;
			}
		}
	}
	cout << endl;
}

///////////

void Family::PrintAllFamilies()
{
	Husband* theHusband=top;//Initialize to top for beginning of loop
	Wife* theWife=NULL;
	Child* theChild=NULL;
	
	while (theHusband != NULL)
	{
		//Print header
		cout << "\n***FAMILY***\n";
	
		//Print Husband
		cout << "Husband: " << theHusband -> firstName
			 << " " << theHusband -> lastName << " " << theHusband -> SSN << endl;
	
		//If the wife exists, print wife
		if (theHusband -> myWife != NULL)
		{
			theWife = theHusband -> myWife;
			cout << "Wife: " << theWife -> firstName << " "
				 << theWife -> lastName << " " << theWife -> SSN << endl;
		}
		
		if (theWife != NULL)//Skip if there is no wife
		{
			//If children exist, print them
			if (theWife -> myChild != NULL)
			{
				theChild = theWife -> myChild;
				while (theChild != NULL)
				{
					cout << "Child: " << theChild -> firstName << " " 
						 << theChild -> lastName << " " << theChild -> SSN << endl;			
					theChild = theChild -> mySibling;
				}
			}
		}
		cout << endl;
		theHusband = theHusband -> nextFamily;
	}
}

///////////

void Family::ReadTransactionFile()
{
	//Open transaction file
	ifstream inf;
	inf.open("trans.txt");
	
	if (!inf)
	{
		cout << "Error: transaction file \"trans.txt\" not found!\n";
		return;
	}
	
	while(!inf.eof())//Loop while all commands in file are processed
	{
		string command; //This will contain the command keyword
		inf >> command;
		
		if(command=="AddHusband")
		{
			long SSN;
			string fname, lname;
			inf >> SSN >> fname >> lname;
			AddHusband(SSN, fname, lname);
		}
		
		else if (command=="RemoveHusband")
		{
			long SSN;
			inf >> SSN;
			RemoveHusband(SSN);
		}
		
		else if (command=="AddWife")
		{
			long SSN, hSSN;
			string fname, lname;
			inf >> SSN >> fname >> lname >> hSSN;
			AddWife(SSN, fname, lname, hSSN);
		}
		
		else if (command=="RemoveWife")
		{
			long SSN;
			inf >> SSN;
			RemoveWife(SSN);
		}
		
		else if (command=="AddAchild")
		{
			long SSN, fSSN;
			string fname, lname;
			inf >> SSN >> fname >> lname >> fSSN;
			AddAChild(SSN, fname, lname, fSSN);
		}
		
		else if (command=="RemoveAchild")
		{
			long SSN, fSSN;
			inf >> fSSN >> SSN;
			RemoveAChild(fSSN, SSN);
		}
		
		else if (command=="PrintAFamily")
		{
			long SSN;
			inf >> SSN;
			PrintAFamily(SSN);
		}
		
		else if (command=="PrintAllFamilies")
			PrintAllFamilies();
			
	}
	cout << endl;
}
	
#endif