/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** false.cxx : catch2 example with failing test
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet catchfalse
#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

int five() { return 6; }

TEST_CASE( "needs to be 5" ) {
    REQUIRE( five()==5 );
}
//codesnippet end

