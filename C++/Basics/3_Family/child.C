#ifndef CHILD_C
#define CHILD_C

#include <string>
using namespace std;

#include "child.h"

Child::Child(long social, string Fname, string Lname)
{
	SSN=social;
	firstName=Fname;
	lastName=Lname;
	mySibling=NULL;
}

#endif