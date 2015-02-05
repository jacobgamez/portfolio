//Jacob Gamez
//An example of a difference in n++ and ++n

#include <iostream>
using namespace std;

int main ()
{
  int x, n=2;

  x = 5 + n++;

  cout << "x= " << x << endl;
  cout << "n= " << n << endl;

  n=2;

  x = 5 + ++n;

  cout << "x= " << x << endl;
  cout << "n= " << n << endl;

  return 0;
}
