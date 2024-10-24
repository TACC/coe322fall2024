// compile this with
// icpx -o prog main.cpp

#include <iostream>

// textual inclusion
#include "func.cpp"

int main() {
  std::cout << f(5) << '\n';
  return 0;
}
