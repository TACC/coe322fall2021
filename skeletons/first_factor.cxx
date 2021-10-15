/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** newton1.cxx : newton scalar example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>

#include <optional>
using std::optional;

optional<int> first_factor( int n ) {
  for ( int f=2; f<n; f++ ) {
    if (n%f==0)
      return f;
  }
  return {};
} 

int main() {

  for ( auto n : { 2, 4, 5 } ) {
    cout << n << "\n";
    auto ff = first_factor(n);
    if ( ff.has_value() ) 
      cout << "factor=" << ff.value() << "\n";
    else
      cout << "no factor\n";
  }

}
