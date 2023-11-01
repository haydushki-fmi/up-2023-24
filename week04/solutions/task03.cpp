#include <iostream>


int main() {
  {
    std::cout << "Enter a natural number:\t";
    int n = 0;
    std::cin >> n;
  
    unsigned digitsCount = 0u;
    do {
      ++digitsCount;
      n /= 10;
    } while (n != 0);
  
    std::cout << "It has " << digitsCount << " digits.\n";
  }

/* --------------------------------------------------------------------------*/ 

  {
    std::cout << "Enter a rational number `r`:\t";
    double r = 0.0;
    std::cin >> r;
  
    std::cout << "Enter a natural number `n`:\t";
    int n = 0; // The previous `n` is out of scope here.
    std::cin >> n;
  
    double r_to_the_n = 1.0;
    do {
      r_to_the_n *= r;
      --n;
    } while (n > 0);
  
    std::cout << "`r` to the power of `n` is " << r_to_the_n << std::endl;
  }
  return 0;
}
