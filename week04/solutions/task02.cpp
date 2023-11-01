#include <iostream>


int main() {
  std::cout << "Enter a rational number `r`:\t";
  double r = 0.0;
  std::cin >> r;

  std::cout << "Enter a natural number `n`:\t";
  unsigned n = 0u;
  std::cin >> n;

  double r_to_the_n = r;
  for (unsigned i = 1u; i < n; ++i) {
    r_to_the_n *= r;
  }
  std::cout << "`r` to the power of `n` is " << r_to_the_n << std::endl;
  return 0;
}
