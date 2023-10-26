#include <iostream>


int main() {
  std::cout << "Enter a natural number <= 255:\t";
  unsigned n = 0;
  std::cin >> n;

  const unsigned n_true_bits = (
    (n & 1) + ((n >> 1) & 1) + ((n >> 2) & 1) + ((n >> 3) & 1) +
    ((n >> 4) & 1) + ((n >> 5) & 1) + ((n >> 6) & 1) + ((n >> 7) & 1));
  std::cout << "The number of 1 bits in " << n << " is " << n_true_bits;
  std::cout << std::endl;

  return 0;
}
