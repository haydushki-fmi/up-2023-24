#include <cmath>
#include <iostream>


int main() {
  std::cout << "Enter the choice parameter c:\t";
  unsigned c = 0;
  std::cin >> c;

  std::cout << "Enter a real number x:\t";
  double x = 0.0;
  std::cin >> x;

  double y = 0.0;
  switch (c) {
    case 1:
      y = x - 5;
      break;
    case 2:
      y = std::sin(x);
      break;
    case 3:
      y = std::cos(x);
      break;
    case 4:
      y = std::exp(x);
      break;
    default:
      std::cout << "Unexpected value for `c`: " << c << "!\n";
      return;
  }

  std::cout << "y = " << y << std::endl;
}
