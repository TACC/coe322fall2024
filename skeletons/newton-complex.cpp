#include <iostream>
using std::cout;
#include <complex>
using std::complex;

complex<double> f(complex<double>);
complex<double> deriv(complex<double>);

int main() {
  // find the square root of two
  // start somewhere
  using namespace std::complex_literals;
  complex<double> current_x = 10000000.+1.i;
  // while the function in the current value is too large keep looping
  complex<double> function_value = f(current_x);
  for ( int iteration_count=0; ; ++iteration_count ) {
    // update current x
    current_x -= f(current_x) / deriv(current_x);
    // calcute new function value
    function_value = f(current_x);
    cout << iteration_count << ":" << function_value << '\n';
    if ( std::abs(function_value)<1.e-5 ) {
      cout << "Function is " << f(current_x) << " at " << current_x <<
	" in iteration " << iteration_count << '\n';
      break;
    }
  }
  // print results
  return 0;
}

complex<double> f( complex<double> x ) { return x*x-static_cast<complex<double>>(-2); }
complex<double> deriv( complex<double> x ) { return static_cast<complex<double>>(2)*x; }

// C-k : kill to end of line, once more to get the line end
// C-y : paste the thing you've killed

// ESC x repl<space>st<space> : replace
// ESC % : query replace
