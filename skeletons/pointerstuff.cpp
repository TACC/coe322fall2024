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

#include <memory>
using std::make_shared;

#include <cmath>
using std::sqrt;

class Point {
private:
  float x,y;
public:
  Point(float in_x,float in_y) {
    x = in_x; y = in_y; };
  float get_x() { return x; }; // don't use this too much
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

class Rectangle {
private:
  Point botleft; // this would use the def constructor
  Point topright;
public:
  Rectangle( Point bl,Point tr ) : botleft(bl),topright(tr) {};
  float area() { ... }; // <<<<<<<<<<<<<<<<<<<<<
public:
};

int main() {
  auto  p1 = make_shared<Point>(1.0,1.0);
  auto  q  = make_shared<Point>(2,2);
  cout << p1->distance(*q) << '\n';

  Rectangle r(*p1,*q);
  cout << r.area() << '\n';

  return 0;
}

float Point::distance_to_origin() {
  return sqrt( x*x + y*y );
};

// C-x 3 : vert split
// C-x 2 : horiz split
// C-x o : go to other pane
// C-x 1 : make this the only pane
// C-x 0 : delete this pane

// C-l : current line to middle / top / bot of the screen

// C-v : screen down

