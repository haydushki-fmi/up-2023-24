#include <cmath>


int main() {
  std::cout << "Enter a 32-bit natural number:\t";
  uint32_t n = 0u;
  std::cin >> n;

  unsigned sum = 0u;
  constexpr unsigned fourBitMask = 0b1111;
  for (unsigned i = 0u; i < 8u; ++i) {
    const unsigned currentMask = fourBitMask << (i * 4);
    const unsigned currentNumber = (n & currentMask) >> (i * 4);
    sum += currentNumber;
  }

  std::cout << sum << std::endl;
  return 0;
}
