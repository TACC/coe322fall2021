#include "lib.h"

#include <iostream>
using std::cout;
#include <string>
using std::string;

myclass::myclass(int in) {
  i = in;
};

void myclass::print( string s ) {
  cout << s << i << "\n";
};
