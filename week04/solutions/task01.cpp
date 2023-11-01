#include <iostream>


int main() {
  std::cout << "Enter a natural number:\t";
  unsigned n = 0u;
  std::cin >> n;

  unsigned digitsCount = 0u;
  while (n > 0) {
    ++digitsCount;
    n /= 10;
  }

  std::cout << "It has " << digitsCount << " digits.\n";
  return 0;
}
