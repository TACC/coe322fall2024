#include <iostream>
using std::cout;

double f(double);
double deriv(double);

int main() {
  // find the square root of two
  // start somewhere
  double current_x = 10000000.;
  // while the function in the current value is too large keep looping
  double function_value = f(current_x);
  for ( int iteration_count=0; ; ++iteration_count ) {
    // update current x
    current_x -= f(current_x) / deriv(current_x);
    // calcute new function value
    function_value = f(current_x);
    if ( std::abs(function_value)<1.e-5 ) {
      cout << "Function is " << f(current_x) << " at " << current_x <<
	" in iteration " << iteration_count << '\n';
      break;
    }
  }
  // print results
  return 0;
}

double f( double x ) { return x*x-2; }
double deriv( double x ) { return 2*x; }

// C-k : kill to end of line, once more to get the line end
// C-y : paste the thing you've killed
