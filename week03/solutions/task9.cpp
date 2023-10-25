#include <iostream>

int main() {
  std::cout << "Enter three numbers:\t";
  float a = 0.0f, b = 0.0f, c = 0.0f;
  std::cin >> a >> b >> c;

  std::cout << "The numbers sorted in increasing order are:\t";
  if (a < b) {
    if (b < c) {
      std::cout << a << ' ' << b << ' ' << c << std::endl;
    }
    else if (a < c) {
      std::cout << a << ' ' << c << ' ' << b << std::endl;
    }
    else {
      std::cout << c << ' ' << a << ' ' << b << std::endl;
    }
  }
  else if (b < c) {
    if (a < c) {
      std::cout << b << ' ' << a << ' ' << c << std::endl;
    }
    else {
      std::cout << b << ' ' << c << ' ' << a << std::endl;
    }
  }
  else {
    std::cout << c << ' ' << b << ' ' << a << std::endl;
  }
}
