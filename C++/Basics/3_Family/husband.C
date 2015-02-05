#ifndef HUSBAND_C
#define HUSBAND_C

#include <string>
using namespace std;

#include "husband.h"

Husband::Husband(long social, string Fname, string Lname)
{
	SSN=social;
	firstName=Fname;
	lastName=Lname;
	nextFamily=NULL;
	myWife=NULL;
}


#endif