#include <iostream>

int main() {
  int a = 0;
  std::cout << "Enter a three-digit integer:\t";
  std::cin >> a;

  unsigned digits_gt_5 = (a % 10 > 5) + ((a / 10) % 10 > 5) + ((a / 100) % 10 > 5);
  std::cout << "The number of digits greater than 5 is " << digits_gt_5 << std::endl;
  // Doesn't work with negative integers: try -666. Modulo (%) returns a
  // negative result when its first parameter is negative.
  // Correctly works with non-integers, which is surprising. std::cin ignores
  // the decimal point and everything after it when reading integers.
  // Works for positive integers with more than 3 digits, but only counts their
  // last 3 digits - `% 10` only returns the last digit, and we're never
  // dividing by more than 100, i.e. never discarding more than 2 digits.
  
  return 0;
}
