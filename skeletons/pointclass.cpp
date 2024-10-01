/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** poitnclass.cxx : Point class skeleton
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;

class Point {
private:
  float x,y;
public:
  Point(float in_x,float in_y) {
    x = in_x; y = in_y; };
  float distance_to_origin() {
    return sqrt( x*x + y*y );
  };
};

int main() {
  Point p1(1.0,1.0);
  float d = p1.distance_to_origin();
  cout << "Distance to origin: "
       << d << '\n';

  return 0;
}
