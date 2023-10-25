#include <cmath>
#include <iostream>


int main() {
  std::cout << "Enter `a`:\t";

  double a = 0.0;
  std::cin >> a;

  double x = 0.0;
  if (a > 0) {
    x = -std::sqrt(std::abs(a - 1)) / (5 * std::pow(a, 1.0 / 3));
  }
  else {
    const double e_to_ax = a * a + 5;
    x = std::log(e_to_ax) / a;
  }

  std::cout << "x = " << x << std::endl;

  return 0;
}
