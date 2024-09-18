#include <iostream>
using std::cout;
#include <functional>
using std::function;

double newton_root( function< double(double) > f,
		    function< double(double) > deriv ) {
		   
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
      // cout << "Function is " << f(current_x) << " at " << current_x <<
      // 	" in iteration " << iteration_count << '\n';
      break;
    }
  }
  return current_x;
}

int main() {

  auto f = [] ( double x ) { return x*x-2; };
  auto deriv = [] ( double x ) { return 2*x; };
 
  // print results
  cout << "Sqrt 2=" << newton_root(f,deriv) << '\n';

  return 0;
}

// C-k : kill to end of line, once more to get the line end
// C-y : paste the thing you've killed
// C-SPACE : set mark
// goto other end of region
// C-w : kill region
// and then C-y : paste back

// if you have a region:
// ESC x comment-reg : comment a region

// C-x u : undo
// C-x 3 : vertical divide
// C-x 2 : horizontal
// C-x 0 : remove current pane
// C-x o : "other" pane
// C-x 1 : make this the only pane

// ESC x global-f : turn off color

