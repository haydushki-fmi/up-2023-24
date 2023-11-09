#include <cmath>
#include <iostream>


void task1() {
  std::cout << "Enter the lake's radius:\t";
  double r = 0.0;
  std::cin >> r;

  std::cout << "Enter an octarine lily's area:\t";
  double lilyArea = 0.0;
  std::cin >> lilyArea;

  constexpr double PI = 3.141592;
  const unsigned maximumLilyCount = std::floor(PI * r * r / lilyArea);

  unsigned currentDayN = 6u;
  unsigned lilyCountN = 8u;
  unsigned lilyCountNMinus1 = 5u;

  while (lilyCountN < maximumLilyCount) {
    ++currentDayN;

    const unsigned newLilyCount = lilyCountNMinus1 + lilyCountN;
    lilyCountNMinus1 = lilyCountN;
    lilyCountN = newLilyCount;
  }

  std::cout << "The Lily lake will be full on Sectober " << currentDayN;
  std::cout << std::endl;
}

/*----------------------------------------------------------------------------*/

bool isPrime(unsigned n) {
  for (unsigned i = 2u; i <= std::sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void task3() {
  std::cout << "Enter a natural number:\t";
  unsigned n = 0u;
  std::cin >> n;

  bool nIsPrime = true;
  for (unsigned i = 2u; i <= std::sqrt(n); ++i) {
    if (n % i == 0) {
      std::cout << i << std::endl;
      nIsPrime = false;
      break;
    }
  }
  if (nIsPrime) {
    std::cout << "prime\n";
  }

  /*--------------------------------------------------------------------------*/

  for (unsigned candidate = 2u; candidate <= n; ++candidate) {
    if (isPrime(candidate)) {
      std::cout << candidate << std::endl;
    }
  }
}

/*----------------------------------------------------------------------------*/

unsigned factorial(unsigned n) {
  unsigned result = 1u;
  for (unsigned i = 2u; i <= n; ++i) {
    result *= i;
  }
  return result;
}

unsigned doubleFactorial(unsigned n) {
  if (n == 0) return 1;

  unsigned result = n;
  for (unsigned i = n - 2; i > 1; i -= 2) {
    result *= i;
  }
  return result;
}

void task4() {
  std::cout << "Enter two natural numbers, `m` and `n`:\t";
  unsigned m = 0u, n = 0u;
  std::cin >> m >> n;

  std::cout << m << "! = " << factorial(m) << std::endl;
  std::cout << n << "! = " << factorial(n) << std::endl;

  std::cout << m << "!! = " << doubleFactorial(m) << std::endl;
  std::cout << n << "!! = " << doubleFactorial(n) << std::endl;
}

/*----------------------------------------------------------------------------*/

uint32_t subBits(uint32_t n, unsigned firstBit, unsigned bitsCount) {
  const uint32_t bitMask = (1u << bitsCount) - 1;
  const unsigned bitsToShift = 32 - firstBit - bitsCount;
  return (n >> bitsToShift) & bitMask;
}

bool isPalindrome(uint32_t n, unsigned bitGroupSize) {
  unsigned i = 0;
  unsigned j = 32 - bitGroupSize;
  
  while (i < j) {
    if (subBits(n, i, bitGroupSize) != subBits(n, j, bitGroupSize)) {
      return false;
    }
    i += bitGroupSize;
    j -= bitGroupSize;
  }
  
  return true;
}

void task8() {
  std::cout << "Enter n:\t";
  uint32_t n = 0u;
  std::cin >> n;

  const bool isPalindromeHex = isPalindrome(n, 4);
  const bool isPalindrome4 = isPalindrome(n, 2);

  std::cout << n << " is " << (isPalindromeHex? "" : "not ");
  std::cout << "a hexadecimal palindrome. It is ";
  std::cout << (isPalindrome4? "" : "not ") << "a quaternary palindrome.\n";
}

/*----------------------------------------------------------------------------*/

void printQuaternary(uint32_t n) {
  for (unsigned i = 0; i < 32; i += 2) {
    std::cout << subBits(n, i, 2);
  }
}

void printHex(uint32_t n) {
  for (unsigned i = 0; i < 32; i += 4) {
    const uint32_t currentBits = subBits(n, i ,4);
    switch(currentBits) {
      case 15:
        std::cout << 'F';
        break;
      case 14:
        std::cout << 'E';
        break;
      case 13:
        std::cout << 'D';
        break;
      case 12:
        std::cout << 'C';
        break;
      case 11:
        std::cout << 'B';
        break;
      case 10:
        std::cout << 'A';
        break;
      default:
        std::cout << currentBits;
    }
  }
}

void task9() {
  std::cout << "Enter n:\t";
  uint32_t n = 0u;
  std::cin >> n;

  const bool isPalindromeHex = isPalindrome(n, 4);
  const bool isPalindrome4 = isPalindrome(n, 2);

  printHex(n);
  std::cout << " is " << (isPalindromeHex? "" : "not ");
  std::cout << "a hexadecimal palindrome. ";
  printQuaternary(n);
  std::cout << " is " << (isPalindrome4? "" : "not ");
  std::cout << "a quaternary palindrome.\n";
}

/*----------------------------------------------------------------------------*/

int main() {
  std::cout << "Task 1\n";
  task1();

  std::cout << "Task 3\n";
  task3();

  std::cout << "Task 4\n";
  task4();

  std::cout << "Task 8\n";
  task8();

  std::cout << "Task 9\n";
  task9();

  return 0;
}
