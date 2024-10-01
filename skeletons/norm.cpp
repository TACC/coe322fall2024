#include <vector>
using std::vector;
#include <cmath>
#include <iostream>
using std::cout;

float compute_norm( const vector<float>& values ) {
  float norm=0.f;
  for ( auto elt : values )
    norm += elt*elt;
  norm = std::sqrt(norm);
  return norm;
}

void scale( vector<float>& values,float norm ) {
  for ( auto& elt : values )
    elt /= norm;
}

int main() {
  vector<float> values(1000000,.5);

  float norm;
  //  for ( int i=0; i<1000; ++i ) {
  norm = compute_norm(values);
  // values[0] += norm;
    // }

  scale( values,norm );

  norm=0.f;
  for ( auto elt : values )
    norm += elt*elt;
  norm = std::sqrt(norm);

  cout << "Norm s/b 1: " << norm << '\n';


  return 0;

}

