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

class board {
private:
  vector<int> columns;
public:
  board( int n ) 
    : columns( vector<int>(n,-1) ) {};
  board( vector<int> cols ) 
    : columns(cols) {};
  board( int n, vector<int> cols )
    : board(n) {
    // copy the elements of cols -> columns
  }

  int next_row_to_be_filled() const {
    int next=0;
    while (columns[next]>=0)
      next++;
    return next;
  };
  void place_next_queen_at_column( int c ) {
    if ( c<0 or c>=columns.size() ) throw(1);
    int row = next_row_to_be_filled();
    columns[row] = c;
  };
  bool feasible() { // is the current configuration conflict free?
  };
};

#ifndef NQUEENS
#define NQUEENS 8
#endif

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

TEST_CASE( "empty board" ) {
  int n=10;
  board empty(n);
  REQUIRE( empty.next_row_to_be_filled()==0 );
}

TEST_CASE( "bounds test" ) {
  int n=10;
  board empty(n);
  REQUIRE_THROWS( empty.place_next_queen_at_column(-1) );
  REQUIRE_THROWS( empty.place_next_queen_at_column(n) );
  REQUIRE_NOTHROW( empty.place_next_queen_at_column(0) );
  REQUIRE( empty.next_row_to_be_filled()==1 );
}

TEST_CASE( "feasibility test" ) {
  const int n=10;
  board empty(n);
  REQUIRE( empty.feasible() );

  board one = empty;
  one.place_next_queen_at_column(0);
  REQUIRE( one.next_row_to_be_filled()==1 );
  REQUIRE( one.feasible() );
}

TEST_CASE( "collision test" ) {
  const int n=10;
  board empty(n);
  board one = empty;
  one.place_next_queen_at_column(0);
  board collide = one;
  collide.place_next_queen_at_column(0);
  REQUIRE( not collide.feasible() );
}

#if 0

TEST_CASE( "final test" ) {
  board five( {0,3,1,4,2} );
  REQUIRE( five.feasible() );
  REQUIRE( five.filled() );
}

TEST_CASE( "generate one and two" ) {
  const int n=10;
  board empty(n);

  // loop over all possibilities first queen
  auto firstcol = GENERATE_COPY( range(1,n) );
  board place_one = empty;
  REQUIRE_NOTHROW( place_one.place_next_queen_at_column(firstcol) );
  REQUIRE( place_one.feasible() );

  // loop over all possbilities second queen
  auto secondcol = GENERATE_COPY( range(1,n) );
  board place_two = place_one;
  REQUIRE_NOTHROW( place_two.place_next_queen_at_column(secondcol) );
  if (secondcol<firstcol-1 or secondcol>firstcol+1) {
    REQUIRE( place_two.feasible() );
  } else {
    REQUIRE( not place_two.feasible() );
  }
}

TEST_CASE( "final step" ) {
  // make board 4x4 with 3 rows filled
  board almost( 4, {1,3,0} );
  auto solution = almost.place_queens();
  REQUIRE( solution.has_value() );
  REQUIRE( solution->filled() );
}

TEST_CASE( "no 2x2 solutions" ) {
  board two(2);
  auto solution = two.place_queens();
  REQUIRE( not solution.has_value() );
}

TEST_CASE( "no 3x3 solutions" ) {
  board three(3);
  auto solution = three.place_queens();
  REQUIRE( not solution.has_value() );
}

TEST_CASE( "there are 4x4 solutions" ) {
  board four(4);
  auto solution = four.place_queens();
  REQUIRE( solution.has_value() );
}

#endif
