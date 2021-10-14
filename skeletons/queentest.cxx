/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** queens.cxx : solution to 8-queens problem
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::fixed;
using std::setprecision;

#include <vector>
using std::vector;
#include <chrono>
#include <optional>
using std::optional;

#include "queens.h"

#ifndef NQUEENS
#define NQUEENS 8
#endif

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"


TEST_CASE( "bounds test" ) {
  constexpr int n=10;
  board empty(n);
}

TEST_CASE( "feasibility test" ) {
  constexpr int n=10;

}

TEST_CASE( "collision test" ) {
  constexpr int n=10;
  board empty(n);
  board one = empty;
  one.place_next_queen_at_column(0);
}

TEST_CASE( "final test" ) {
  REQUIRE( five.filled() );
}

TEST_CASE( "generate one and two" ) {
  constexpr int n=10;
  board empty(n);

}

TEST_CASE( "final step" ) {
}



