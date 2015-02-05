/*
Jacob Gamez
9.23.14

This program demonstrates a basic binary search
 */

#include <iostream>
using namespace std;
int binarySearch(int[], int, int, int);

int main()
{
  int array[10]={1,3,5,7,9,11,13,15,17,19};
  int position=0, query=0, maxi=9, mini=0;

  cout << "Please input a number to search for: ";
  cin >> query;

  try {
    position = binarySearch(array, query, maxi, mini) + 1;
  }

  catch (string error){ cout << error; return 0;}

  cout << "The number was found in position " << position << endl;

}

int binarySearch(int array[], int query, int max, int min)
{
  string error = "ERROR: NOT FOUND\n";
  int mid = (min+max)/2;

  if (min>max)
    {
      throw error;
    }
  else if (array[mid]==query)
    {
      return mid;
    }
  else if (array[mid]<query)
    {
      min=mid+1;
      mid=binarySearch(array, query, max, min);
    }
  else if (array[mid]>query)
    {
      max=mid-1;
      mid=binarySearch(array, query, max, min);
     }
  return mid;
}
