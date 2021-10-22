/*
 * Simple solution to swapping two variables 
 * with C-style parameter passing
 */

#include <iostream>
using namespace std;

void swap( int *i,int *j ) {
  int t = *i;
  *i = *j;
  *j = t;
}

int main() {
  int i=1, j=2;
  cout << "i=" << i << ", j=" << j << "\n";
  swap(  &i,&j );
  cout << "i=" << i << ", j=" << j << "\n";
  return 0;
}
