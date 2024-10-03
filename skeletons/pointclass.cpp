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
  float distance_to_origin();
  float angle( /* no x or y here! */ ) {
    return atan(y/x); // atan2(y,x)
  };
  // float dx( Point q ) { return x-q.x; };
  // float dy( Point q ) { return y-q.y; };
  float distance( Point q ) {
    auto dx = x-q.x, dy = y-q.y;
    return sqrt( dx*dx + dy*dy );
  };
  float twice_the_angle() {
    float a = angle(); // equiv to: (*this).angle();
    return 2*a;
  };
};

int main() {
  Point p1(1.0,1.0);
  float d = p1.distance_to_origin();
  cout << "Distance to origin: "
       << d << '\n';
  cout << p1.angle() << '\n';
  Point q(2,2);
  p1.distance(q);

  cout << p1.twice_the_angle() << '\n';

  return 0;
}

float Point::distance_to_origin() {
  return sqrt( x*x + y*y );
};

// C-x 3 : vert split
// C-x 2 : horiz split
