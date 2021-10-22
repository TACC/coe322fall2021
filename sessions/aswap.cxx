/*
 * Swapping the pointer to two variables 
 * with C-style parameter passing
 *
 * This is a `just because I can' solution,
 * and it illustrates `**' syntax.
 * If you don't grok this, don't worry.
 */

#include <iostream>
using namespace std;

void swap( int **i,int **j ) {
  cout << "input " << **i << "," << **j << "\n";
  int *t = *i;
  *i = *j;
  *j = t;
  cout << "output " << **i << "," << **j << "\n";
}

int main() {
  // create two variables
  int i=1, j=2;
  // create pointers to the variables
  int *ii = &i,*jj = &j;

  // print out the values from dereferencing the pointers
  cout << "i=" << *ii << ", j=" << *jj << "\n";
  // swap the pointers
  swap(  &ii,&jj );
  // prove that indeed the pointers have been swapped.
  cout << "i=" << *ii << ", j=" << *jj << "\n";
  return 0;
}
