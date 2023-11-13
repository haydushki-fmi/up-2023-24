#include <cmath>
#include <iostream>

using std::abs;
using std::cin;
using std::cout;
using std::endl;


void task1() {
  cout << "Enter a natural number:\t";
  unsigned n = 0u;
  cin >> n;

  unsigned sum = 0u;
  for (unsigned i = 3u; i < n; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  cout << "The sum of all multiples of 3 and 5 smaller than " << n;
  cout << " is " << sum << ".\n";
}

/*----------------------------------------------------------------------------*/

void printDigit(unsigned digit) {
  for (unsigned i = 0u; i < digit; ++i) {
    cout << "*";
  }
  cout << endl;
}

void task2() {
  cout << "Enter a natural number:\t";
  unsigned n = 0u;
  cin >> n;

  unsigned currentPowerOfTen = unsigned(1e9);
  bool nonZeroEncountered = false;

  while (currentPowerOfTen > 0) {
    unsigned currentDigit = (n / currentPowerOfTen) % 10;
    if (currentDigit != 0) {
      nonZeroEncountered = true;
    }
  
    if (nonZeroEncountered) {
      printDigit(currentDigit);
    }
  
    currentPowerOfTen /= 10;
  }
}

/*----------------------------------------------------------------------------*/

constexpr unsigned MAX_ARRAY_SIZE = 1000;

unsigned readNUpTo(unsigned limit) {
  cout << "Enter a natural number N <= " << limit << ":\t";
  unsigned n = 0u;
  cin >> n;
  while (n > limit) {
    std::cerr << n << " > " << limit << "; try again:\t";
    cin >> n;
  }
  return n;
}

void task10() {
  unsigned n = readNUpTo(MAX_ARRAY_SIZE);

  cout << "Now enter " << n << " real numbers:\n";
  double numbers[MAX_ARRAY_SIZE] = {0.0};
  double average = 0.0;
  for (unsigned i = 0u; i < n; ++i) {
    cin >> numbers[i];
    average += (numbers[i] / n);
  }
  cout << "Their average is " << average << ".\n";

  unsigned bestIndex = 0u;
  double bestDifference = abs(numbers[0] - average);
  for (unsigned i = 1u; i < n; ++i) {
    if (abs(numbers[i] - average) < bestDifference) {
      bestIndex = i;
      bestDifference = abs(numbers[i] - average);
    }
  }
  cout << "The entered number closest to it is " << numbers[bestIndex] << ".\n";
}

/*----------------------------------------------------------------------------*/

int main() {
  cout << "Task 1\n";
  task1();

  cout << "Task 2\n";
  task2();

  cout << "Task 10\n";
  task10();

  return 0;
}
