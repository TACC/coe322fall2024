#include <iostream>
using std::cout;

template<typename real>
real epsilon() {
  auto one = static_cast<real>(1);
  real guess = one;
  while (one+guess>one) {
    guess /= static_cast<real>(2);
  }
  return guess;
}

int main() {
  auto ef = epsilon<float>();
  cout << ef << '\n';
  auto ed = epsilon<double>();
  cout << ed << '\n';
  return 0;

}

