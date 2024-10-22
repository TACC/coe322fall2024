/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2024 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** zeroclasstest.cpp : unittests for root finding
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

#include "zeroclasslib.hpp"

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

TEST_CASE( "proper test","[2]" ) {
  vector<double> coefficients{3., 2.5, 2.1};
  REQUIRE_NOTHROW( polynomial(coefficients) );

  coefficients.at(0) = 0.;
  REQUIRE_THROWS( polynomial(coefficients) );
}

TEST_CASE( "polynomial degree","[3]" ) {
  polynomial second( {2,0,1} ); // 2x^2 + 1
  REQUIRE( not second.is_odd() );
  polynomial third( {3,2,0,1} ); // 3x^3 + 2x^2 + 1
  REQUIRE( third.is_odd() );
}

TEST_CASE( "polynomial evaluation" ) {
  polynomial second( {2,0,1.1} ); 
  // correct interpretation: 2x^2 + 1.1
  REQUIRE( second.evaluate_at(2) == Catch::Approx(9.1) );
  // wrong interpretation: 1.1x^2 + 2
  REQUIRE( second.evaluate_at(2) != Catch::Approx(6.4) );
  polynomial third( {3,2,0,1} ); // 3x^3 + 2x^2 + 1
  REQUIRE( third(0) == Catch::Approx(1) );
}

TEST_CASE( "polynomial evaluation through functor" ) {
  polynomial second( {2,0,1.1} ); 
  // correct interpretation: 2x^2 + 1.1
  REQUIRE( second(2) == Catch::Approx(9.1) );
  polynomial third( {3,2,0,1} ); // 3x^3 + 2x^2 + 1
  REQUIRE( third(0) == Catch::Approx(1) );
}

TEST_CASE( "initial bounds" ) {
  double left{10},right{11};
  right = left+1;
  polynomial second( {2,0,1} ); // 2x^2 + 1
  REQUIRE_THROWS( find_initial_bounds(second,left,right) );
  polynomial third( {3,2,0,1} ); // 3x^3 + 2x^2 + 1
  REQUIRE_NOTHROW( find_initial_bounds(third,left,right) );
  REQUIRE( left<right );
  double
    leftval = third(left),
    rightval = third(right);
  REQUIRE( leftval*rightval<=0 );
}

TEST_CASE( "move bounds closer" ) {
  double left{10},right{11};
  polynomial third( {3,2,0,1} ); // 3x^3 + 2x^2 + 1
  REQUIRE_NOTHROW( find_initial_bounds(third,left,right) );
  double
    leftval = third(left), rightval = third(right);
  REQUIRE( leftval*rightval<=0 );
  REQUIRE_THROWS( move_bounds_closer(third,right,left) );
  REQUIRE_THROWS( move_bounds_closer(third,left,left) );

  double old_left = left, old_right = right;
  REQUIRE_NOTHROW( move_bounds_closer(third,left,right) );
  leftval = third(left); rightval = third(right);
  REQUIRE( leftval*rightval<=0 );
  REQUIRE( ( ( left==old_left and right<old_right ) or
	     ( right==old_right and left>old_left ) ) );
}

TEST_CASE( "test zero finder", "[7]" ) {
  vector<vector<double>> coefficients{
    {1., 0., 0., 0.01}, // x^3, 3x^2
    {.01, 0., 0., 0., 0., 100000.} // 1/100 x^5 + 10,000 , 1/20 x^4
  };
  for ( int ipoly=0; ipoly<coefficients.size(); ++ipoly ) {
    polynomial oddpoly(coefficients.at(ipoly));
    INFO( "polynomial #" << ipoly );
    double zero, value, prec=1.e-5;
    REQUIRE_NOTHROW( zero = find_zero(oddpoly,prec) );
    INFO( "found zero=" << zero );
    REQUIRE_NOTHROW( value = oddpoly(zero) );
    REQUIRE( std::abs(value)<prec );
  }
}
