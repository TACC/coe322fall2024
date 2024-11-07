/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2024 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** actuple.cpp : abc formula
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <cmath>
#include <string>
using std::string;

#include <optional>
using std::optional;

#include <tuple>
using std::pair, std::make_pair, std::tuple, std::make_tuple;
#include <variant>
using std::variant, std::monostate;

using quadratic = tuple<double,double,double>;

double discriminant
    ( quadratic q ) {
  auto [a,b,c] = q;
  return b*b-4*a*c;
}




int main() {

  /*
   * Initialization syntax is not unique
   */
  { 
    // spell it out
    auto sunk = tuple<double,double,double>{1.,0.,-2};
  }
  {
    // brace syntax
    auto sunk = quadratic{1.,0.,-2};
  }

  /*
   * Here is the actual program
   */
  // parenthesis syntax
  // polynomial: x^2 - 2
  auto sunk = quadratic(1.,0.,-2);
  auto [a,b,c] = sunk;
  cout << "coefficients: " << a << "," << b << ',' << c << '\n';

  auto d = discriminant( sunk );
  cout << "discriminant: "
       << d << '\n';

  auto num_solutions = how_many_roots(sunk);
  if ( not num_solutions.has_value() )
    cout << "none\n";
  else
    cout << num_solutions.value() << '\n';

  auto roots = abc_roots( sunk );
  auto [xplus,xminus] = roots;
  cout << xplus << "," << xminus << '\n';

  auto root_cases = abc_cases( sunk );
  switch (root_cases.index()) {
  case 0 : cout << "No roots\n"; break;
  case 1 : cout << "Single root: " << get<1>(root_cases); break;
  case 2 : {
    auto xs = get<2>(root_cases);
    auto [xp,xm] = xs;
    cout << "Roots: " << xp << "," << xm << '\n';
  } ; break;
  }

  return 0;
}
