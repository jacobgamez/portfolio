#ifndef WIFE_C
#define WIFE_C

#include <string>
using namespace std;

#include "wife.h"

Wife::Wife(long social, string Fname, string Lname)
{
	SSN=social;
	firstName=Fname;
	lastName=Lname;
	myChild=NULL;
}

#endif