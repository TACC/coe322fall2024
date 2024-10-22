/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2024 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** zeroclasslib.hpp : headers for root finding library
 ****
 ****************************************************************/

#include <vector>

class polynomial {
private:
  std::vector<double> coefficients;
public:
  polynomial( std::vector<double> c );
  bool is_odd() const;
  double evaluate_at(double x) const;
  double operator()(double x) const { return evaluate_at(x); };
};

void find_initial_bounds
    ( const polynomial&,double &left,double &right);

void move_bounds_closer
    ( const polynomial&,double& left,double& right,bool trace=false );

double find_zero( const polynomial&,double,bool=false );
