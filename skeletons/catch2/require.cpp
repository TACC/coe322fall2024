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

float fiveish() { return 5.00001; }
TEST_CASE( "not six" ) {
  // this will fail
  REQUIRE( fiveish()!=5 );
  // this will succeed
  REQUIRE( fiveish()==Catch::Approx(5) );
}

bool is_prime( int n ) {
  if (n<=0) throw("negative number");
  if (n==1) return false;
  //  if (n==2) return true;
  for ( int factor=2; factor<n; ++factor )
    if (n%factor==0) return false;
  return true;
}

TEST_CASE( "primality testing" ) {
  REQUIRE_THROWS( is_prime(-1) );
  REQUIRE_NOTHROW( is_prime(1) );
  REQUIRE( not is_prime(1) );
  REQUIRE( is_prime(2) );
}

#if 0

void even( int e ) {
    if (e%2==1) throw(1);
    cout << "Even number: "
         << e << '\n';
}

TEST_CASE( "even fun" ) {
    REQUIRE_NOTHROW( even(2) );
    REQUIRE_THROWS( even(3) );
}

TEST_CASE( "even set" ) {
    int e = GENERATE( 2,4,6,8 );
    REQUIRE_NOTHROW( even(e) );
}
#endif
