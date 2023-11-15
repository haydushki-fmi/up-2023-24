#include <iostream>
#include <cmath>

unsigned getDigitCount(unsigned n) {
  unsigned counter = 0;

  while (n > 0) {
    counter++;
    n /= 10;
  }

  return counter;
}

unsigned getDigitToPowerSum(unsigned n) {
    unsigned digitCount = getDigitCount(n);
    unsigned sum = 0;

    while (n > 0) {
      sum += std::pow(n % 10, digitCount);
      n /= 10;
    }
    
    return sum;
}

int main()
{
    unsigned int n;
    std::cin >> n;

    unsigned int sum = getDigitToPowerSum(n);

    std::cout << std::boolalpha << (sum == n) << std::endl;

    return 0;
}
