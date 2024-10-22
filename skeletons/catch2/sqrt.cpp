/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** tdd.cxx : example of catch2 main
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;
#include <cmath>

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

//codesnippet catch2sqrt
double root(double x) {
  if (x<0) throw(1);
  return std::sqrt(x);
};

TEST_CASE( "test sqrt function" ) {
  double x=3.1415, y;
  REQUIRE_NOTHROW( y=root(x) );
  REQUIRE( y*y==Catch::Approx(x) );
  REQUIRE_THROWS( y=root( -3.14 ) );
}
//codesnippet end
