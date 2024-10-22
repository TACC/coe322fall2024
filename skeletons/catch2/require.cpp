/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** require.cxx : catch2 example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet catchtoyexample
#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

int five() { return 5; }

TEST_CASE( "needs to be 5" ) {
    REQUIRE( five()==5 );
}
//codesnippet end

//codesnippet catchtestno
float fiveish() { return 5.00001; }
TEST_CASE( "not six" ) {
  // this will fail
  REQUIRE( fiveish()==5 );
  // this will succeed
  REQUIRE( fiveish()==Catch::Approx(5) );
}
//codesnippet end

//codesnippet catchevenfun
void even( int e ) {
    if (e%2==1) throw(1);
    cout << "Even number: "
         << e << '\n';
}
//codesnippet end

//codesnippet catchtesteven
TEST_CASE( "even fun" ) {
    REQUIRE_NOTHROW( even(2) );
    REQUIRE_THROWS( even(3) );
}
//codesnippet end

//codesnippet catchtestgen
TEST_CASE( "even set" ) {
    int e = GENERATE( 2,4,6,8 );
    REQUIRE_NOTHROW( even(e) );
}
//codesnippet end


