#include <iostream>


int main() {
  std::cout << "Enter a natural number:\t";
  uint32_t n = 0u; // Generally equivalent to `unsigned int`.
  std::cin >> n;

  bool upBitEncountered = false;
  for (uint32_t currentBit = 0b1 << 31; currentBit > 0; currentBit >>= 1) {
    bool currentBitUp = ((n & currentBit) == currentBit);
    if (currentBitUp) {
      upBitEncountered = true;
    }
    if (upBitEncountered) { // Start printing on first 1 => skip leading 0s.
      std::cout << (currentBitUp ? '1' : '0');
    }
  }
  std::cout << std::endl;
  return 0;
}
